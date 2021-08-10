#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <algorithm> 
using namespace std;
#include<vector>
//在一个增序的整数数组里找到两个数，使它们的和为给定值。已知有且只有一对解。
int main()
{   

int target,i;
vector<int>numbers;

//输入是一个数组（numbers）
do{
        scanf("%d",&i);
        numbers.push_back(i);
    }while(getchar()!='\n');

    scanf("%d",&target);//给定一个给定值
    /*
    如果两个指针指向元素的和小于给定值，
    我们把左边的指针右移一位，使得当前的和增加一点。如果两个指针指向元
    素的和大于给定值，我们把右边的指针左移一位，使得当前的和减少一点。
    */
int l=0,r=numbers.size()-1,sum;
while(l<r){
    sum=numbers[l]+numbers[r];
    if(sum==target)break;
    if(sum<target)++l;
    else --r;
}
//输出是两个数的位置
printf("%d,%d",l+1,r+1);

	return 0;
}
