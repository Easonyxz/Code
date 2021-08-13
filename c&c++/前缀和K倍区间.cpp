#include <stdio.h>
#include <math.h>
#include <algorithm> 
using namespace std;



int main(){
	
int n,k,c;
int i,j;
long long cnt=0;
scanf("%d %d",&n,&k);
int a[n+1]={0},ans[n+1]={0};	
ans[0]=1;

	

for(i=1;i<=n;i++){
	scanf("%d",&a[i]);
	a[i]=(a[i-1]+a[i])%k;
	cnt+=ans[a[i]];
	ans[a[i]]++;
}



printf("%lld",cnt);
	return 0;
}