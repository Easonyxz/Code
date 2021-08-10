#include <stdio.h>
#include <algorithm> 
using namespace std;

int main()
{
 int m,n,i,j,k,l,t,b;
 scanf("%d",&n);
 int ans[n];
 for ( i=0;i<n;i++){
     scanf("%d",&ans[i]);
 }
scanf("%d",&m);
int query[m][3];

    for(b=0;b<m;b++){
    for(i=0;i<3;i++)
    scanf("%d",&query[b][i]);
    }

for ( i=0;i<m;i++){
    k=query[i][1]-query[i][0]+1;
    l=query[i][2];
    int a[k];
    for ( t=0,j=query[i][0]-1;j<query[i][1];j++,t++){
        a[t]=ans[j];
    }
    sort(a,a+k);   
    printf("%d\n",a[k-l]);

}


    return 0;
}