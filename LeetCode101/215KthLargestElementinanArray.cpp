#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <algorithm> 
using namespace std;
#include<vector>
//在一个未排序的数组中，找到第 k 大的数字。
/*
快速选择一般用于求解 k-th Element 问题，可以在 O(n) 时间复杂度，O(1) 空间复杂度完成求
解工作。快速选择的实现和快速排序相似，不过只需要找到第 k 大的枢（pivot）即可，不需要对
其左右再进行排序。与快速排序一样，快速选择一般需要先打乱数组，否则最坏情况下时间复杂
度为 O(n2)，
输入一个数组和一个目标值 k，输出第 k 大的数字。题目默认一定有解。
Input: [3,2,1,5,6,4] and k = 2
Output: 5
3 2 1 5 6 4
2
*/

int quickSelection(vector<int>& nums, int l, int r);

int main()
{
vector<int>nums;
int i,k;
do{
    scanf("%d",&i);
    nums.push_back(i);
}while (getchar()!='\n');
scanf("%d",&k);

int l = 0, r = nums.size() - 1, target = nums.size() - k;
while (l < r) {
int mid = quickSelection(nums, l, r);
if (mid == target) {
    printf("%d",nums[mid] );
    return 0;
}
    if (mid < target) {
    l = mid + 1;
    } 
    else {
    r = mid - 1;
    } 
}
    printf("%d",nums[l] );

    return 0;
}

int quickSelection(vector<int>& nums, int l, int r) {
int i = l + 1, j = r;
while (true) {
    while (i < r && nums[i] <= nums[l]) {
    ++i;
    }
    while (l < j && nums[j] >= nums[l]) {
    --j;
    }
    if (i >= j) { break; }
    swap(nums[i], nums[j]);
    }
swap(nums[l], nums[j]);
return j;
}