#include <iostream>
#include <malloc.h>
#include <stdio.h>
using namespace std;

typedef struct
{
	//结构体
	int row, col;
	//二维指针，目的是动态分配内存
	float** matrix;
} Matrix;

typedef struct
{
	char* name;
	char* number;
} Student;

Matrix CreateMatrix()
{
	Matrix m;
	int row, col;
	cout << "输入行数与列数：" << endl;
	cin >> row >> col;
	float** enterMatrix;
	enterMatrix = (float**)malloc(row * sizeof(float*));
	for (int i = 0; i < row; i++)
		enterMatrix[i] = (float*)malloc(col * sizeof(float));
	cout << "输入你的矩阵：" << endl;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cin >> enterMatrix[i][j];
		}
	}
	m.col = col;
	m.row = row;
	m.matrix = enterMatrix;
	return m;
}

Matrix Create2DArrayDefault(int row_col)
{
	Matrix m;
	float** enterMatrix;
	enterMatrix = (float**)malloc(row_col * sizeof(float*));
	for (int i = 0; i < row_col; i++)
		enterMatrix[i] = (float*)malloc(row_col * sizeof(float));
	for (int i = 0; i < row_col; i++)
	{
		for (int j = 0; j < row_col; j++)
		{
			enterMatrix[i][j] = 0;
		}
	}
	m.col = row_col;
	m.row = row_col;
	m.matrix = enterMatrix;
	return m;
}

// Function to get cofactor of A[p][q] in temp[][]. n is current 
// dimension of A[][] 
void getCofactor(Matrix A, Matrix temp, int p, int q, int n)
{
	int i = 0, j = 0;

	// Looping for each element of the matrix 
	for (int row = 0; row < n; row++)
	{
		for (int col = 0; col < n; col++)
		{
			//  Copying into temporary matrix only those element 
			//  which are not in given row and column 
			if (row != p && col != q)
			{
				temp.matrix[i][j++] = A.matrix[row][col];

				// Row is filled, so increase row index and 
				// reset col index 
				if (j == n - 1)
				{
					j = 0;
					i++;
				}
			}
		}
	}
}

/* Recursive function for finding determinant of matrix.
   n is current dimension of A[][]. */
int determinant(Matrix A, int n)
{
	int D = 0; // Initialize result 

	//  Base case : if matrix contains single element 
	if (n == 1)
		return A.matrix[0][0];

	Matrix temp = Create2DArrayDefault(n); // To store cofactors 

	int sign = 1;  // To store sign multiplier 

	 // Iterate for each element of first row 
	for (int f = 0; f < n; f++)
	{
		// Getting Cofactor of A[0][f] 
		getCofactor(A, temp, 0, f, n);
		D += sign * A.matrix[0][f] * determinant(temp, n - 1);

		// terms are to be added with alternate sign 
		sign = -sign;
	}

	return D;
}

// Function to get adjoint of A[N][N] in agetCofactordj[N][N]. 
void adjoint(Matrix A, Matrix adj)
{
	if (A.row == 1)
	{
		adj.matrix[0][0] = 1;
		adj.row = 1;
		adj.col = 1;
		return;
	}
	int N = A.row;
	// temp is used to store cofactors of A[][] 
	int sign = 1;
	Matrix temp = Create2DArrayDefault(N);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			// Get cofactor of A[i][j] 
			getCofactor(A, temp, i, j, N);

			// sign of adj[j][i] positive if sum of row 
			// and column indexes is even. 
			sign = ((i + j) % 2 == 0) ? 1 : -1;

			// Interchanging rows and columns to get the 
			// transpose of the cofactor matrix 
			adj.matrix[j][i] = (sign) * (determinant(temp, N - 1));
		}
	}
	adj.row = N;
	adj.col = N;
}

bool inverse(Matrix A, Matrix inverse)
{
	// Find determinant of A[][] 
	int N = A.row;
	int det = determinant(A, A.row);
	if (det == 0)
	{
		cout << "矩阵的逆不存在！"/*"Singular matrix, can't find its inverse"*/;
		return false;
	}

	// Find adjoint 
	Matrix adj = Create2DArrayDefault(N);
	adjoint(A, adj);

	// Find Inverse using formula "inverse(A) = adj(A)/det(A)" 
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			inverse.matrix[i][j] = adj.matrix[i][j] / float(det);
	inverse.row = N;
	inverse.col = N;
	return true;
}

//初始化一个行为row列为col矩阵
Matrix InitMatrix(int row, int col)
{
	Matrix m;
	float** matrix;
	matrix = (float**)malloc(row * sizeof(float*));
	for (int i = 0; i < row; i++)
		matrix[i] = (float*)malloc(col * sizeof(float));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			matrix[i][j] = 0;
		}
	}
	m.col = col;
	m.row = row;
	m.matrix = matrix;
	return m;
}

Matrix add(Matrix m1, Matrix m2)
{
	for (int i = 0; i < m1.row; i++)
	{
		for (int j = 0; j < m1.col; j++)
		{
			m1.matrix[i][j] = m1.matrix[i][j] + m2.matrix[i][j];
		}
	}
	return m1;
}

Matrix sub(Matrix m1, Matrix m2)
{
	for (int i = 0; i < m1.row; i++)
	{
		for (int j = 0; j < m1.col; j++)
		{
			m1.matrix[i][j] = m1.matrix[i][j] - m2.matrix[i][j];
		}
	}
	return m1;
}

float calRowCol(Matrix M1, Matrix M2, int row, int col)//row为M1的行 col为m2的列
{
	float result = 0;
	int same = M1.col;
	for (int j = 0; j < same; j++)
	{
		result += M1.matrix[row][j] * M2.matrix[j][col];
	}

	return result;
}


Matrix Mul(Matrix m1, Matrix m2)
{
	Matrix result = InitMatrix(m1.row, m2.col);
	for (int i = 0; i < m1.row; i++)
	{
		for (int j = 0; j < m2.col; j++)
		{
			result.matrix[i][j] = calRowCol(m1, m2, i, j);
		}
	}
	return result;
}

Matrix numMul(Matrix m, int num)
{
	cout << "数值:" << num << endl;
	for (int i = 0; i < m.row; i++)
	{
		for (int j = 0; j < m.col; j++)
		{
			m.matrix[i][j] = m.matrix[i][j] * num;
		}
	}
	return m;
}

void printMatrix(Matrix m)
{
	for (int i = 0; i < m.row; i++)
	{
		for (int j = 0; j < m.col; j++)
		{
			cout << m.matrix[i][j] << "  ";
		}
		cout << endl;
	}
}

int main()
{
	int num = 0;
	do
	{
		cout << "*************************************\n";
		cout << "*              菜单                 *\n";
		cout << "*          1.矩阵相加               *\n";
		cout << "*          2.矩阵相减               *\n";
		cout << "*          3.矩阵相乘               *\n";
		cout << "*          4.矩阵数乘               *\n";
		cout << "*          5.矩阵的逆               *\n";
		cout << "*          6.退出                   *\n";
		cout << "*************************************\n";
		cin >> num;
		if (1 == num || 2 == num || 3 == num)
		{
			cout << "请输入矩阵1" << endl;
			Matrix m1 = CreateMatrix();
			cout << "请输入矩阵2" << endl;
			Matrix m2 = CreateMatrix();
			cout << "两矩阵为" << endl;
			printMatrix(m1);
			cout << endl;
			printMatrix(m2);
			switch (num)
			{
			case 1:
			{
				if (m1.col != m2.col || m1.row != m2.row)
				{
					cout << "行列不同" << endl;
				}
				else {
					cout << "结果为：" << endl;
					printMatrix(add(m1, m2));
				}
				break;
			}
			case 2:
			{

				if (m1.col != m2.col || m1.row != m2.row)
				{
					cout << "参数错误" << endl;
				}
				else {
					cout << "结果为：" << endl;
					printMatrix(sub(m1, m2));
				}
				break;

			}
			case 3:
			{
				if (m1.col != m2.row)
				{
					cout << "参数错误" << endl;
				}
				else {
					cout << "结果为：" << endl;
					printMatrix(Mul(m1, m2));
				}
				break;
			}
			default:
				break;
			}
		}
		else if (4 == num)
		{
			int number = 1;
			cout << "请输入矩阵" << endl;
			Matrix m = CreateMatrix();
			cout << "请输入数值" << endl;
			cin >> number;
			cout << "矩阵为：" << endl;
			printMatrix(m);
			cout << "数值为：" << endl;
			cout << number << endl;
			printMatrix(numMul(m, number));
		}
		else if (5 == num)
		{
			cout << "请输入矩阵" << endl;
			Matrix m1 = CreateMatrix();
			cout << "输入矩阵为" << endl;
			printMatrix(m1);
			cout << endl;
			Matrix m2 = Create2DArrayDefault(m1.row);
			inverse(m1, m2);
			printMatrix(m2);
		}
		cout << "按回车继续....";

		getchar();
		getchar();
		system("cls");
	} while (1 == num || 2 == num || 3 == num || 4 == num || 5 == num);
	return 0;
}