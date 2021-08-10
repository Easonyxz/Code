//
// Created by zhengwei.
//

/*
标题：打印图形

    小明在X星球的城堡中发现了如下图形和文字：
rank=3
   *
  * *
 *   *
* * * *

rank=5
               *
              * *
             *   *
            * * * *
           *       *
          * *     * *
         *   *   *   *
        * * * * * * * *
       *               *
      * *             * *
     *   *           *   *
    * * * *         * * * *
   *       *       *       *
  * *     * *     * *     * *
 *   *   *   *   *   *   *   *
* * * * * * * * * * * * * * * *

ran=6
                               *
                              * *
                             *   *
                            * * * *
                           *       *
                          * *     * *
                         *   *   *   *
                        * * * * * * * *
                       *               *
                      * *             * *
                     *   *           *   *
                    * * * *         * * * *
                   *       *       *       *
                  * *     * *     * *     * *
                 *   *   *   *   *   *   *   *
                * * * * * * * * * * * * * * * *
               *                               *
              * *                             * *
             *   *                           *   *
            * * * *                         * * * *
           *       *                       *       *
          * *     * *                     * *     * *
         *   *   *   *                   *   *   *   *
        * * * * * * * *                 * * * * * * * *
       *               *               *               *
      * *             * *             * *             * *
     *   *           *   *           *   *           *   *
    * * * *         * * * *         * * * *         * * * *
   *       *       *       *       *       *       *       *
  * *     * *     * *     * *     * *     * *     * *     * *
 *   *   *   *   *   *   *   *   *   *   *   *   *   *   *   *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *


    小明开动脑筋，编写了如下的程序，实现该图形的打印。

#define N 70

void f(char a[][N], int rank, int row, int col)
{
	if(rank==1){
		a[row][col] = '*';
		return;
	}

	int w = 1;
	int i;
	for(i=0; i<rank-1; i++) w *= 2;

	____________________________________________;
	f(a, rank-1, row+w/2, col);
	f(a, rank-1, row+w/2, col+w);
}

int main()
{
	char a[N][N];
	int i,j;
	for(i=0;i<N;i++)
	for(j=0;j<N;j++) a[i][j] = ' ';

	f(a,6,0,0);

	for(i=0; i<N; i++){
		for(j=0; j<N; j++) printf("%c",a[i][j]);
		printf("\n");
	}

	return 0;
}


    请仔细分析程序逻辑，填写缺失代码部分。

    通过浏览器提交答案。注意不要填写题目中已有的代码。也不要写任何多余内容（比如说明性的文字）
*/
#include <iostream>

using namespace std;
#define N 70

void f(char a[][N], int rank, int row, int col) {
    if (rank == 1) {
        a[row][col] = '*';
        return;
    }

    int w = 1;
    int i;
    for (i = 0; i < rank - 1; i++)
        w *= 2;

//    ____________________________________________;
    f(a, rank - 1, row , col+w/2);//a,5,0,16，处理顶上的三角形
    f(a, rank - 1, row + w / 2, col);//a,5,16,0，处理左下角
    f(a, rank - 1, row + w / 2, col + w);//a,5,16,16，处理右下角
}

int main() {
    char a[N][N];
    int i, j;
    for (i = 0; i < N; i++)
        for (j = 0; j < N; j++) a[i][j] = ' ';

    f(a, 5, 0, 0);

    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) printf("%c", a[i][j]);
        printf("\n");
    }

    return 0;
}
