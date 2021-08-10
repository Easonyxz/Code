/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
 static bool cmp(vector<int>a,vector<int>b)
    {
        return a[0]<b[0];
    }
    vector<int> twoSum(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end(),cmp);
     int i,j;
     for(i=0,j=nums.size()-1;i<j;){
         if(nums[i]+nums[j]==target)return vector<int>{i,j};
         if(nums[i]+nums[j]>target)j--;
         else i++;
     }
    }
};
// @lc code=end

