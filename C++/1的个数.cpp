#include <stdio.h>
#include <math.h>
#include <algorithm> 
using namespace std;

//������������n���жϴ�1��n֮�У�����1һ��Ҫ���ּ��Ρ�����1123������������������1��
//����15����ô��1��15֮�У�һ��������8��1
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