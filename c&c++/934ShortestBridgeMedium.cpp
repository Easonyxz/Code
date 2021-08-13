#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <algorithm> 
using namespace std;
#include<vector>
#include<queue>
/*
给定一个二维 0-1 矩阵，其中 1 表示陆地，0 表示海洋，每个位置与上下左右相连。已知矩
阵中有且只有两个岛屿，求最少要填海造陆多少个位置才可以将两个岛屿相连。
输入输出样例
输入是一个二维整数数组，输出是一个非负整数，表示需要填海造陆的位置数。
Input:
[[1,1,1,1,1],
[1,0,0,0,1],
[1,0,1,0,1],
[1,0,0,0,1],
[1,1,1,1,1]]
Output: 1
题解
本题实际上是求两个岛屿间的最短距离，因此我们可以先通过任意搜索方法找到其中一个岛
屿，然后利用广度优先搜索，查找其与另一个岛屿的最短距离。
*/
vector<int> direction{-1, 0, 1, 0, -1};
void dfs(queue<pair<int, int>>& points, vector<vector<int>>& grid, int m, int n , int i, int j);
int main()
{
vector<vector<int>> grid(5,vector<int>(5));
{
    grid[0]={1,1,1,1,1};
    grid[1]={1,0,0,0,1};
    grid[2]={1,0,1,0,1};
    grid[3]={1,0,0,0,1};
    grid[4]={1,1,1,1,1};
}
int m = grid.size(), n = grid[0].size();
queue<pair<int, int>> points;
// dfs寻找第一个岛屿，并把1全部赋值为2
bool flipped = false;
for (int i = 0; i < m; ++i) {
if (flipped) break;
    for (int j = 0; j < n; ++j) {
        if (grid[i][j] == 1) {
        dfs(points, grid, m, n, i, j);
        flipped = true;
        break; } 
    } 
}
// bfs寻找第二个岛屿，并把过程中经过的0赋值为2
int x, y;
int level = 0;
while (!points.empty()){
++level;
int n_points = points.size();
while (n_points--) {
    auto [r, c] = points.front();
    points.pop();
        for (int k = 0; k < 4; ++k) {
        x = r + direction[k], y = c + direction[k+1];
            if (x >= 0 && y >= 0 && x < m && y < n) {
            if (grid[x][y] == 2) {
            continue; }
            if (grid[x][y] == 1) {
            printf("%d",level);
            return 0;
            }
            points.push({x, y});
            grid[x][y] = 2;
            } 
        } 
    } 
}
return 0;
}
void dfs(queue<pair<int, int>>& points, vector<vector<int>>& grid, int m, int n , int i, int j) {
if (i < 0 || j < 0 || i == m || j == n || grid[i][j] == 2) {
    return; }
if (grid[i][j] == 0) {
    points.push({i, j});
    return; }
grid[i][j] = 2;
dfs(points, grid, m, n, i - 1, j);
dfs(points, grid, m, n, i + 1, j);
dfs(points, grid, m, n, i, j - 1);
dfs(points, grid, m, n, i, j + 1);
}