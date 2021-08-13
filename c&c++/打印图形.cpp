
#include<stdio.h>

int main()
{
int i;
int j;
int n;
int p=0;
int q=0;

scanf("%d", &n);
if(n<20&&n>0){
for(i=0,j=1;i<n;i++,j+=2){
for(q=i;q<n-1;q++)
{
  printf(" ");
}
for(p=j;p>0;p--)
  printf("*");

printf("\n");
}


}

return 0;
}
