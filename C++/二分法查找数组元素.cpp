#include <stdio.h>
 
int main()
{
 int data[200];
 int i=0,j=99,n,k=199,p;
 for (i=0;i<200;i++)
 data[i]=4*i+6;
i=0;
scanf("%d",&n);

while(1){
if (data[j]>n) {p=j;j=(i+j)/2;k=p;}
else if (data[j]<n){p=j;j=(k+j)/2;i=p;}
else {printf("%d",j);break;}
}

    return 0;
}