#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <algorithm> 
using namespace std;
#include<vector>
/*
给定一个二维的非负整数矩阵，每个位置的值表示海拔高度。假设左边和上边是太平洋，右
边和下边是大西洋，求从哪些位置向下流水，可以流到太平洋和大西洋。水只能从海拔高的位置
流到海拔低或相同的位置。
输入输出样例
输入是一个二维的非负整数数组，表示海拔高度。输出是一个二维的数组，其中第二个维度
大小固定为 2，表示满足条件的位置坐标。
Input:
太平洋 ~ ~ ~ ~ ~
~ 1 2 2 3 (5) *
~ 3 2 3 (4) (4) *
~ 2 4 (5) 3 1 *
~ (6) (7) 1 4 5 *
~ (5) 1 1 2 4 *
* * * * * 大西洋
Output: [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]]
*/
vector<int> direction{-1, 0, 1, 0, -1};
void dfs(const vector<vector<int>>& matrix, vector<vector<bool>>& can_reach,int r, int c);
int main(){
vector<vector<int>>matrix(5,vector<int>(5));
{
    matrix[0]={1,2,2,3,5};
    matrix[1]={3,2,3,4,4};
    matrix[2]={2,4,5,3,1};
    matrix[3]={6,7,1,4,5};
    matrix[4]={5,1,1,2,4};
}

if (matrix.empty() || matrix[0].empty()) {
return {};
}
vector<vector<int>> ans;
int m = matrix.size(), n = matrix[0].size();
vector<vector<bool>> can_reach_p(m, vector<bool>(n, false));
vector<vector<bool>> can_reach_a(m, vector<bool>(n, false));
//p从头遍历第一列,a从头遍历最后一列
for (int i = 0; i < m; ++i) {
    dfs(matrix, can_reach_p, i, 0);
    dfs(matrix, can_reach_a, i, n - 1);
    }
//p从头遍历第一行,a从头遍历最后一行
for (int i = 0; i < n; ++i) {
    dfs(matrix, can_reach_p, 0, i);
    dfs(matrix, can_reach_a, m - 1, i);
    }
for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; ++j) {
        if (can_reach_p[i][j] && can_reach_a[i][j]) {
        ans.push_back(vector<int>{i, j});
        } 
    } 
}

for (int i =0;i<ans.size();i++)
printf("%d,%d\n",ans[i][0],ans[i][1]);

    return 0;
}

void dfs(const vector<vector<int>>& matrix, vector<vector<bool>>& can_reach,int r, int c) {
if (can_reach[r][c]) {return; }
can_reach[r][c] = true;
int x, y;
for (int i = 0; i < 4; ++i) {
    x = r + direction[i], y = c + direction[i+1];
    if (x >= 0 && x < matrix.size()&& y >= 0 && y < matrix[0].size() &&matrix[r][c] <= matrix[x][y]) {
        dfs(matrix, can_reach, x, y);
        } 
    } 
}