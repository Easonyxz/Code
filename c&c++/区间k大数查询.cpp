#include <stdio.h>
#include <algorithm> 
using namespace std;
/*��һ�а���һ����n����ʾ���г��ȡ�

�ڶ��а���n������������ʾ���������С�

����������һ��������m����ʾѯ�ʸ�����

������m�У�ÿ��������l,r,K����ʾѯ�����д������ҵ�l��������r�����У�
�Ӵ���С��K��������ĸ�������Ԫ�ش�1��ʼ��š�
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