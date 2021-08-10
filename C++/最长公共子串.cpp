#include <stdio.h>
#include <math.h>
#include <algorithm> 
using namespace std;
#include <string.h>



int main()
{
int i,j,n,m,Pmax=0,Lmax=0;
char x[100],y[100];
scanf("%s %s",&x,&y);
n=strlen(x);m=strlen(y);
char c[n+1][m+1];
memset(c,0,sizeof(c));//≥ı ºªØ


for(i=1;i<=n;i++){
    for(j=1;j<=m;j++){
        if((x[i-1]==y[j-1]))
        {c[i][j]=c[i-1][j-1]+1;
            if(c[i][j]>Lmax){Lmax=c[i][j];Pmax=i;}}
            else {c[i][j]=0;}
    }
}
i--;j--;
if (Lmax==0)
{
    return 0;
}

for ( i = Pmax-Lmax; i < Pmax; i++)
{
    printf("%c",x[i]);
}



    return 0;
}