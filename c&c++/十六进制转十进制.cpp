#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	char a[10];
	while(scanf("%s",a)!=EOF)
	{
		int l,k=0;
		long long sum=0,d;
		l=strlen(a);
		for(int i=l-1;i>=0;i--)
		{
			if(a[i]>='0'&&a[i]<='9')
			d=a[i]-'0';
			else
			d=a[i]-'A'+10;
			sum+=d*pow(16,k);
			k++;
		}
        printf("%I64d\n",sum);
	}
	return 0;
}