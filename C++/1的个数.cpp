#include <stdio.h>
#include <math.h>
#include <algorithm> 
using namespace std;

//　输入正整数n，判断从1到n之中，数字1一共要出现几次。例如1123这个数，则出现了两次1。
//例如15，那么从1到15之中，一共出现了8个1
int cat(int x)
{   
    
    int q=1;
    int p=0;
    int mask = 1;
    int t =x;
	int cnt=0;
     while ( t>9 ) {
        t /=10;
        mask *=10;
    }

while ( mask > 0 ){
    int d = x / mask;
    if(d==1)cnt++;
   
            x%=mask;
            mask /=10;
       
}

    
     return cnt;
}

int main(){
	
int n,c;
int i,j;
long long k=0;
	scanf("%d",&n);
	for (i=0;i<=n;i++){
		c=cat(i);
		k+=c;
	}
	
	printf("%lld",k);



	return 0;
}