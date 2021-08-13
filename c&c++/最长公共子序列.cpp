#include <stdio.h>
#include <math.h>
#include <algorithm> 
using namespace std;
#include <string.h>



int main()
{
int i,j,k,l,n,m,cnt=0;
char x[100],y[100],ans[100];
scanf("%s %s",&x,&y);
n=strlen(x);m=strlen(y);
char c[n+1][m+1],rec[n+1][m+1];
memset(c,0,sizeof(c));//初始化
memset(rec,0,sizeof(rec));
memset(ans,0,sizeof(ans));

for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
        if((x[i-1]==y[j-1])){c[i][j]=c[i-1][j-1]+1;rec[i][j]='P';}
        else if (c[i-1][j]>=c[i][j-1]){c[i][j]=c[i-1][j];rec[i][j]='U';}
        else {c[i][j]=c[i][j-1];rec[i][j]='L';}
    }
}
i--;j--;
//输出最长子序列
printf("%d\n",c[i][j]);
//追踪
out:
if (i==0||j==0) {for(i=cnt-1;i>=0;i--){
    printf("%c",ans[i]);
}
return 0;}
if(rec[i][j]=='P'){ans[cnt]=x[i-1];cnt++;i-=1;j-=1;goto out;}
else if(rec[i][j]=='U'){i-=1;goto out;}
else {j-=1;goto out;}




    return 0;
}