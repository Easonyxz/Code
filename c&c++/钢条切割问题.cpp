#include <stdio.h>
#include <math.h>
#include <algorithm> 
using namespace std;




int main(){
	
int n,q;
int i,j;
//输入钢条最长长度
scanf("%d",&n);
int Price[n+1],c[n+1]={0},rec[n+1]={0};
Price[0]=0;
//输入钢条价目表
for (i=1;i<=n;i++){
 scanf("%d",&Price[i]);
}

for(j=1;j<=n;j++){
 q=Price[j];
 rec[j]=j;
 for (i=1;i<=j-1;i++){
	 if (q<Price[i]+c[j-i]){q=Price[i]+c[j-i];rec[j]=i;}
 }
 c[j]=q;
}
while(n>=0){
	printf("%d ",rec[n]);
	n-=rec[n];
}





	return 0;
}