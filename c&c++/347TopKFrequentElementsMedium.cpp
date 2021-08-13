#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <algorithm> 
#include <unordered_map>
using namespace std;
#include<vector>
//给定一个数组，求前 k 个最频繁的数字。
//输入是一个数组和一个目标值 k。输出是一个长度为 k 的数组。
/*
Input: nums = [1,1,1,1,2,2,3,4], k = 2
Output: [1,2]
在这个样例中，最频繁的两个数是 1 和 2。
1 1 1 1 2 2 3 4
2
*/
int main()
{
int n,k;
int max_count = 0;
vector<int>nums;
unordered_map<int, int> counts;
do{
   scanf("%d",&n);
   nums.push_back(n);
}while(getchar()!='\n');
scanf("%d",&k);

for (const int & num : nums) {
max_count = max(max_count, ++counts[num]);
}

vector<vector<int>> buckets(max_count + 1);
for (const auto & p : counts) {
    buckets[p.second].push_back(p.first);
}

vector<int> ans;
for (int i = max_count; i >= 0 && ans.size() < k; --i) {
    for (const int & num : buckets[i]) {
        ans.push_back(num);
        if (ans.size() == k) {
         break; 
        } 
    } 
}
for (int i =0;i<k;i++){
    printf("%d ", ans[i]);
}


    return 0;
}