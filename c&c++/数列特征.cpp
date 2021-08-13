#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
using namespace std;
//给出n个数，找出这n个数的最大值，最小值，和。
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