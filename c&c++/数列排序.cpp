#include<stdio.h>
int main()
{
int n;
int i;
int j;
int k;
int cnt=0;
scanf("%d", &n);
int a[n];


for(i=0;i<n;i++)
scanf("%d", &a[i]);
int min=a[0];
for(i=0;i<n;i++){
    min=a[i];
    for(j=i;j<n;j++){
    if(a[j]<min){min=a[j];k=j;cnt++;}
    }
    if(cnt!=0){
a[k]=a[i];
a[i]=min;
k=i+1;
cnt=0;
}
 }
for(i=0;i<n;i++)
printf("%d ",a[i]);
return 0;
}
