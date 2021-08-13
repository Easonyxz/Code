#include<stdio.h>


int main()
{
int i;
int j;
int n;
int p;
int cnt=0; 
char a[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
scanf("%d", &n);if(n>26||n<0)return 0;
j=n;
for (p=1;p<(n);p++){
for (i=1;i<(2*n);i++)
{ 
    if(i==(n-j+1)||i==n||i==(2*n-p))printf("%c",a[cnt]);
    else printf(".");
}
cnt++;
printf("\n");
j--;
}
if(cnt==(n-1))
{
    for(i=0;i<n;i++)
    printf("%c",a[i]);
    for(i=n-2;i>-1;i--)
    printf("%c",a[i]);
}
printf("\n");
cnt--;
for (p=n-1;p>0;p--){
for (i=2*n-1;i>0;i--)
{ 
    if(i==(n-j)||i==n||i==(2*n-p))printf("%c",a[cnt]);
    else printf(".");
}
cnt--;
printf("\n");
j++;
}
return 0;
}
