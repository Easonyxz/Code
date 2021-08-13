#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <algorithm> 
using namespace std;
#include<vector>
#include<numeric>

/*老师想给孩子们分发糖果，有 N个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。

你需要按照以下要求，帮助老师给这些孩子分发糖果：

每个孩子至少分配到 1 个糖果。
评分更高的孩子必须比他两侧的邻位孩子获得更多的糖果。
那么这样下来，老师至少需要准备多少颗糖果呢？

*/


int main()
{
int n;//输入孩子数量
scanf("%d",&n);
int i,j=0;
int ans[n];
//把所有孩子的糖果数初始化为 1；
vector<int>candy(n,1);

int size = candy.size();
if (size < 2) {
   printf("%d", size);
return 0;
}

for ( i = 0; i < n; i++)
{
    scanf("%d",&ans[i] );
   
}

/*
先从左往右遍历一遍，如果右边孩子的评分比左边的高，则右边孩子的糖果数更新为左边孩子的
糖果数加 1；再从右往左遍历一遍，如果左边孩子的评分比右边的高，且左边孩子当前的糖果数
不大于右边孩子的糖果数，则左边孩子的糖果数更新为右边孩子的糖果数加 1。
*/

for ( i = 1; i < n ; ++i)
{
    if (ans[i]>ans[i-1])candy[i]+=1;
}

for ( i = n-1; i >0 ; --i)
{
    if (ans[i]<ans[i-1])candy[i-1]=max(candy[i-1],candy[i]+1);
}

//求和
j=accumulate(candy.begin(), candy.end(), 0);
printf("%d",j);

    return 0;   
}