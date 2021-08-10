#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <algorithm> 
using namespace std;
#include<vector>
/*
给定一个整数 n 和一个整数 k，求在 1 到 n 中选取 k 个数字的所有组合方法。

输入是两个正整数 n 和 k，输出是一个二维数组，表示所有组合方式。
Input: n = 4, k = 2
Output: [[2,4], [3,4], [2,3], [1,2], [1,3], [1,4]]
这里二维数组的每个维度都可以以任意顺序输出
*/
void backtracking(vector<vector<int>>& ans, vector<int>& comb, int& count, int pos, int n, int k);

int main() {  
int n, k,i,j;
scanf("%d %d",&n,&k);
vector<vector<int>> ans;
vector<int> comb(k, 0);
int count = 0;
backtracking(ans, comb, count, 1, n, k);
for ( i = 0; i < ans.size(); i++)
{
    for ( j = 0; j< ans[0].size(); j++)
    {
        printf("%d", ans[i][j]);
    }
    printf("\n");
}

    return 0;
}

void backtracking(vector<vector<int>>& ans, vector<int>& comb, int& count, int pos, int n, int k) {
if (count == k) {
    ans.push_back(comb);
    return; }
for (int i = pos; i <= n; ++i) {
    comb[count++] = i; // 修改当前节点状态
    backtracking(ans, comb, count, i + 1, n, k); // 递归子节点
    --count; // 回改当前节点状态 
    } 
}