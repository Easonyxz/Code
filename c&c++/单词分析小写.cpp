#include <stdio.h>
#include <algorithm> 
using namespace std;
#include <string.h>

int main()
{
char n[1000];
char a[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
int b[26]={0};
int i,j,k=0,l;

scanf("%s",&n);
for (j=0;j<26;j++){
    a[j]+=32;
}
for (i=0;i< strlen(n);i++){
    for (j=0;j<26;j++){
        if(n[i]==a[j]){b[j]++;break;}
    }   
}
for (j=0;j<26;j++){
        if(b[j]>k){k=b[j];l=j;}
    }  
    printf("%c\n",a[l]);
    printf("%d",k);
    return 0;
}