#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
using namespace std;
//����n�������ҳ���n���������ֵ����Сֵ���͡�
int main()  
{  
   int n,i,max,min,sum=0;
   scanf("%d",&n);
   int a[n];
   for (i=0;i<n;i++){
        scanf("%d",&a[i]);
   }
   max=a[0];min=a[0];
for (i=0;i<n;i++){
   if(a[i]>max)max=a[i];
   if(a[i]<min)min=a[i];
   sum+=a[i];
}

printf("%d\n",max);
printf("%d\n",min);
printf("%d",sum);
   return 0;  
}  