#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
using namespace std;

int main()  
{  
   int n,i,j,k,l,p,q,cnt=0,cnt1=0;
   char symbol;
   scanf("%d ",&n);if(n<=0||n>1000) return 0; p=n;
   scanf("%c",&symbol);
    for(i=1,k=0;k<(n/2-1);i+=2){
        k+=i;
        cnt++;
        j=i;
    }
       for(i=0,j;i<cnt,j>0;i++,j-=2){
           for(l=0;l<cnt1;l++)printf(" ");
           for(l=j;l>0;l--){
                printf("%c",symbol);p--;
           }
      printf("\n");cnt1++;
       }cnt1--;
for(i=1,j=3;i<cnt,j<=p;i++,j+=2){
           for(l=cnt1-1;l>0;l--)printf(" ");
           for(l=j;l>0;l--){
                printf("%c",symbol);p--;
           }
      printf("\n");cnt1--;
       }
if(j>p&&cnt1>0){for(p;p>0;p--)printf("%c",symbol);printf("\n");}


if(n>(k*2-1))printf("%d",n-(k*2-1));
   return 0;  
}  