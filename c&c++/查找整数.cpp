#include<stdio.h>
#include<math.h>
#include<string.h>
/*����һ������n�����������У�������a�������еĵ�һ�γ����ǵڼ�����
��һ�а���һ������n��

�ڶ��а���n���Ǹ�������Ϊ���������У������е�ÿ������������10000��

�����а���һ������a��Ϊ�����ҵ�����
*/
int main()
{
    int n;
    int i,j,k,l;
    scanf("%d", &n);
    int a[n];
    for (i=0;i<n;i++)
{
  scanf("%d",&a[i]);
  if(a[i]<0)return 0;
}
scanf("%d",&j);

for (i=0;i<n;i++)
{
  if(a[i]==j){printf("%d",i+1);return 0;}
}

printf("-1");

return 0;
}
