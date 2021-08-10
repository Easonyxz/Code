#include <stdio.h>
#include <math.h>
#include <algorithm> 
using namespace std;

/*
　给定一个长度为N的数列，A1, A2, ... AN，如果其中一段连续的子序列Ai,
 Ai+1, ... Aj(i <= j)之和是K的倍数，我们就称这个区间[i, j]是K倍区间。
　　你能求出数列中总共有多少个K倍区间吗？

　第一行包含两个整数N和K。(1 <= N, K <= 100000)
　　以下N行每行包含一个整数Ai。(1 <= Ai <= 100000)
样例输入
5 2
1
2
3
4
5
样例输出
6
*/

int main(){
	
int n,k,c;
int i,j;
long long cnt;
scanf("%d %d",&n,&k);
int a[n+1]={0},si[n+1]={0},ans[k]={0};	
ans[0]=1;

	

for(i=1;i<=n;i++){
	scanf("%d",&a[i]);
	si[i]=(si[i-1]+a[i])%k;
	ans[si[i]]++;
}

for (i=0;i<k;i++){
	if(ans[i]==0||ans[i]==1)continue;
	else cnt+=(tgamma(ans[i]+1)/(tgamma(ans[i]-1)*2));
}

//printf("%lf",tgamma(5)); tgamma使用double类型
printf("%lld",cnt);
	return 0;
}