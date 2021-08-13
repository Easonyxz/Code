#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <algorithm> 
using namespace std;
#include<vector>
/*
一个原本增序的数组被首尾相连后按某个位置断开（如 [1,2,2,3,4,5] → [2,3,4,5,1,2]，在第一
位和第二位断开），我们称其为旋转数组。给定一个值，判断这个值是否存在于这个为旋转数组
中。
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
2 5 6 0 0 1 2
0
*/

int main()
{
vector<int>nums;
int i,target;
do{
    scanf("%d",&i);
    nums.push_back(i);
}while (getchar()!='\n');
scanf("%d",&target);
int start=0,end=nums.size()-1;

while (start <= end) {
    int mid = (start + end) / 2;

    if (nums[mid] == target) {
    printf("true"); return 0;}

    if (nums[start] == nums[mid]) {
    // 无法判断哪个区间是增序的
    ++start;
    } else if (nums[mid] <= nums[end]) {
    // 右区间是增序的
    if (target > nums[mid] && target <= nums[end]) {
    start = mid + 1;
    } else {
    end = mid - 1;
    } } else {
    // 左区间是增序的
    if (target >= nums[start] && target < nums[mid]) {
    end = mid - 1;
    } else {
    start = mid + 1;
    } } }
printf("false");



    return 0;
}