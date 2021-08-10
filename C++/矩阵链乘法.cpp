#include<iostream>
using namespace std;
const int INTMAX=2147483647;

//输入矩阵链数   "n"  M=n+1
int const M=7;


void MATRIX_CHAIN_ORDER(int *p,int Length,int m[][M],int s[][M])
{
	int q,n=Length-1;
	for(int i=1;i<=n;i++) m[i][i]=0;
	for(int l=2;l<=n;l++) 	/* 矩阵链的长度 */
	{
		for(int i=1;i<=n-l+1;i++) 
		{
			int j=i+l-1;         /* 等价于 l=j-i+1 */
			m[i][j]=INTMAX;
			for(int k=i;k<=j-1;k++)
			{
				q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(q<m[i][j])
				{
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
}
void PRINT_OPTIMAL_PARENS(int s[][M],int i,int j)
{
	if(i == j) cout<<"A"<<i;
	else
	{
		cout<<"(";
		PRINT_OPTIMAL_PARENS(s,i,s[i][j]);
		PRINT_OPTIMAL_PARENS(s,s[i][j]+1,j);
		cout<<")";
	}
}
int main()
{  //输入对应行列数
   int p[M],n=M-1;
   for(int i=0;i<M; i++){
	   scanf("%d",&p[i]);
   }

   int m[M][M],s[M][M];
   MATRIX_CHAIN_ORDER(p,M,m,s);
   printf("当n=%d时最优解为:\n%d\n括号化方案为：\n",n,m[1][n]);
   PRINT_OPTIMAL_PARENS(s,1,n);


   return 0;
}