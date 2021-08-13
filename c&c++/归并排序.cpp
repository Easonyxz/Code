
# include <iostream>
using namespace std;
# include <stdlib.h>
int main()
{
	void fsort(int a[],int n);
	int i;
	int a[10]={2,34,13,87,47,52,19,4,79,35};
	fsort(a,10);
	for(i=0;i<10;i++)
		cout<<a[i]<<" ";
system("pause");
return 0;
}
void merge(int a[],int temp[],int left,int mid,int right)    //合并两个数组
{
	int i=left,j=mid,k=0;
while(i<mid&&j<=right)
{
	if(a[i]<a[j])
		temp[k++]=a[i++];
	else
		temp[k++]=a[j++];
}
while(i<mid)
	temp[k++]=a[i++];
while(j<=right)
	temp[k++]=a[j++];
for(i=0;i<k;i++)
	a[left+i]=temp[i];
}
void mergesort(int a[],int tmp[],int left,int right)       //合并排序
{  
	if(left<right)
	{
		int mid=(left+right)/2;
	mergesort(a,tmp,left,mid);
	mergesort(a,tmp,mid+1,right);
	merge(a,tmp,left,mid+1,right);
	}
}
void fsort(int a[],int n)
{
	int *tmp=(int *)malloc(n*sizeof(int));
mergesort(a,tmp,0,n-1);
free(tmp);
}