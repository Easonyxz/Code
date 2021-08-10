#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <algorithm> 
using namespace std;
#include<vector>
/*
6.3 回溯法
回溯法（backtracking）是优先搜索的一种特殊情况，又称为试探法，常用于需要记录节点状
态的深度优先搜索。通常来说，排列、组合、选择类问题使用回溯法比较方便。
顾名思义，回溯法的核心是回溯。在搜索到某一节点的时候，如果我们发现目前的节点（及
其子节点）并不是需求目标时，我们回退到原来的节点继续搜索，并且把在目前节点修改的状态 还原。这样的好处是我们可以始终只对图的总状态进行修改，而非每次遍历时新建一个图来储存
状态。在具体的写法上，它与普通的深度优先搜索一样，都有 [修改当前节点状态]→[递归子节
点] 的步骤，只是多了回溯的步骤，变成了 [修改当前节点状态]→[递归子节点]→[回改当前节点
状态]。
没有接触过回溯法的读者可能会不明白我在讲什么，这也完全正常，希望以下几道题可以让
您理解回溯法。如果还是不明白，可以记住两个小诀窍，一是按引用传状态，二是所有的状态修 改在递归完成后回改。
回溯法修改一般有两种情况，一种是修改最后一位输出，比如排列组合；一种是修改访问标
记，比如矩阵里搜字符串
给定一个无重复数字的整数数组，求其所有的排列方式。
*/

void backtracking(vector<int> &nums, int level, vector<vector<int>> &ans) ;

int main()
{
    int n;
vector<int> nums;
do{
   scanf("%d",&n);
   nums.push_back(n);
}while (getchar()!='\n');
/*利用next_permutation函数进行全排列
do{
    for (int i=0;i<nums.size();i++)
    printf("%d",nums[i] );
    printf("\n");
}while (next_permutation(nums.begin(),nums.end()));
*/

vector<vector<int>> ans;
backtracking(nums, 0, ans);

for (int i =0;i<ans.size();i++){
    for(int j=0;j<ans[0].size();j++){
        printf("%d", ans[i][j]);
    }printf("\n");
    
}
    return 0;
}
void backtracking(vector<int> &nums, int level, vector<vector<int>> &ans) {
if (level == nums.size() - 1) {
    ans.push_back(nums);
    return; }
for (int i = level; i < nums.size(); i++) {
    swap(nums[i], nums[level]); // 修改当前节点状态
    backtracking(nums, level+1, ans); // 递归子节点
    swap(nums[i], nums[level]); // 回改当前节点状态 
    } 
}