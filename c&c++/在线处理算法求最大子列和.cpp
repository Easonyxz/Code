#include <stdio.h>

int MaxSubseqSum4( int A[], int N )
{ int ThisSum, MaxSum;
int i;
ThisSum = MaxSum = 0;
for( i = 0; i < N; i++ ) {
ThisSum += A[i]; /* 向右累加 */
if( ThisSum > MaxSum )
MaxSum = ThisSum; /* 发现更大和则更新当前结果 */
else if( ThisSum < 0 ) /* 如果当前子列和为负 */
ThisSum = 0; /* 则不可能使后面的部分和增大，抛弃之 */
}
return MaxSum;
} 

int main()
{
 int a[8]={-1,3,-2,4,-6,1,6,-1};
 int n=8;
 int c;
 c=MaxSubseqSum4(a,  n );
 printf("最大子列和=%d",c);

  return 0;  
}