//输入一行，包含两个整数n和m，分别表示你要输出的图形的行数的列数。
#include<stdio.h>
#include<math.h>
#include<string.h>
#include<iostream>
using namespace std;

int main()  
{  
   int i,j,k,n,m;
char a[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
scanf("%d",&n);
scanf("%d",&m);
if(n<0||n>26||m<0||m>26) return 0;
for(i=0;i<n;i++){ k=i;if(k>26)k-=26;
     for (j=0;j<m;j++){
         
          printf("%c",a[k]);
          if(k>=0)k--;if(k<0)goto out;
                
          }

          out:k++;
          for (j+=1;j<m;j++){
           k++;
          printf("%c",a[k]);
          
                
          }j=0;
        printf("\n"); 
     }




   return 0;  
}  