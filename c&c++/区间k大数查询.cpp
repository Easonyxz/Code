#include <stdio.h>
#include <algorithm> 
using namespace std;
/*第一行包含一个数n，表示序列长度。

第二行包含n个正整数，表示给定的序列。

第三个包含一个正整数m，表示询问个数。

接下来m行，每行三个数l,r,K，表示询问序列从左往右第l个数到第r个数中，
从大往小第K大的数是哪个。序列元素从1开始标号。
*/
bool cmp(int a,int b)
{    return a > b;} 


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
    sort(a,a+k,cmp);   
    printf("%d\n",a[l-1]);

}


    return 0;
}