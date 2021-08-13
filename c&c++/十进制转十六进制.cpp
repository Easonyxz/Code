#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <algorithm> 
using namespace std;

int main()
{   int j,i=0,cnt;
    scanf("%d", &j);
	char a[10];
	
		for(i=0;;i++)
		 {
		a[i]=(j%16) ;
		if(a[i]>9){a[i]=a[i]+'A'-10;}
		else a[i]+='0';
			j=j/16;        
		if(j==0)break;
		}

	cnt=i;if(a[i]=='0'&&i==cnt){printf("0");return 0;}

	for(i;i>=0;i--){
	printf("%c",a[i]);
	}

	return 0;
}