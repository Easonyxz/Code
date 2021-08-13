#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;
#include <vector>

//给定一个增序的整数数组和一个值，查找该值第一次和最后一次出现的位置。

/*
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
5 7 7 8 8 10
8
*/
int main()
{
    int i, j, k = -1, l = -1, target;
    vector<int> nums;
    
    do
    {
        scanf("%d", &i);
        nums.push_back(i);
    } while (getchar() != '\n');
    if (nums.empty())
    {
        printf("-1,-1");
        return 0;
    };
    scanf("%d", &target);

    //lower_bound返回指向大于等于key的第一个值的位置upper_bound()函数，它返回大于等于key的最后一个元素
    k = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
    l = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;

    if (k == nums.size() || nums[k] != target)
    {
        printf("-1,-1");
        return 0;
    }

    printf("%d,%d", k, l);
    return 0;
}