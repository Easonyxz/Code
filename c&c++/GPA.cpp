#include <stdio.h>
#include <math.h>
#include <algorithm> 
using namespace std;
#include<float.h>
#include <string.h>

float GPA(int n){
    int p,k;
    int s=0,t=0;
float i=0.0,j=0.0,a=0;
int si[n],ci[n];
char ans[3];
for(p=0;p<n;p++){
    scanf("%d %s", &si[p],&ans);
    for (k=0;k<strlen(ans);k++){
    if(ans[k]=='P'||ans[k]=='N'){ci[p]=-1;break;}
    else if(ans[k]>='0'&&ans[k]<='9'){
                        s=ans[k]-'0';
                        t=t*10+s;
                    }
    ci[p]=t;}s=0;t=0;
   
}
for(p=0;p<n;p++){
   if(ci[p]<0)continue;i+=(si[p]*ci[p]*1.0);  
}
for(p=0;p<n;p++){
   if(ci[p]<0)si[p]=0;j+=si[p];  
}

a=((i*1.0)/(j*1.0));
return a;
}


int main()
{
int n,l;
float a=0,b=0;
scanf("%d",&n);
a=GPA(n);
scanf("%d",&l);
b=GPA(l);
if(a-b<=0.01&&a-b>=-0.01)printf("0.00");
else printf("%.2llf",a-b);
    return 0;
}