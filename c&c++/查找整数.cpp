#include<stdio.h>
#include<math.h>
#include<string.h>
/*给出一个包含n个整数的数列，问整数a在数列中的第一次出现是第几个。
第一行包含一个整数n。

第二行包含n个非负整数，为给定的数列，数列中的每个数都不大于10000。

第三行包含一个整数a，为待查找的数。
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
