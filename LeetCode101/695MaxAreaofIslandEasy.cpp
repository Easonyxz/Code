#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;
#include <vector>
/*
深度优先搜索（depth-first seach，DFS）在搜索到一个新的节点时，立即对该新节点进行遍历；

给定一个二维的 0-1 矩阵，其中 0 表示海洋，1 表示陆地。单独的或相邻的陆地可以形成岛
屿，每个格子只与其上下左右四个格子相邻。求最大的岛屿面积。
输入是一个二维数组，输出是一个整数，表示最大的岛屿面积。
Input:
[[1,0,1,1,0,1,0,1],
[1,0,1,1,0,1,1,1],
[0,0,0,0,0,0,0,1]]
Output: 6
最大的岛屿面积为 6，位于最右侧。
1 0 1 1 0 1 0 1
1 0 1 1 0 1 1 1
0 0 0 0 0 0 0 1
*/
//对于四个方向的遍历，可以创造一个数组 [-1, 0, 1, 0, -1]，每相
//邻两位即为上下左右四个方向之一
vector<int> direction{-1, 0, 1, 0, -1};
int dfs(vector<vector<int>> &grid, int r, int c);

int main()
{
    int a = 3;
    vector<vector<int>> grid(a, vector<int>());
    {
        grid[0] = {1, 0, 1, 1, 0, 1, 0, 1};
        grid[1] = {1, 0, 1, 1, 0, 1, 1, 1};
        grid[2] = {0, 0, 0, 0, 0, 0, 0, 1};
    }
    if (grid.empty() || grid[0].empty())
        return 0;
    int max_area = 0;
    //grid.size()为grid的个数
    for (int i = 0; i < grid.size(); ++i)
    {
        for (int j = 0; j < grid[0].size(); ++j)
        {
            if (grid[i][j] == 1)
            {
                max_area = max(max_area, dfs(grid, i, j));
            }
        }
    }
    printf("%d", max_area);
    return 0;
}

// 辅函数
int dfs(vector<vector<int>> &grid, int r, int c)
{

    if (grid[r][c] == 0)
        return 0;
    grid[r][c] = 0;
    int x, y, area = 1;

    for (int i = 0; i < 4; ++i)
    {
        x = r + direction[i], y = c + direction[i + 1];
        if (x >= 0 && x < grid.size() && y >= 0 && y < grid[0].size())
        {
            area += dfs(grid, x, y);
        }
    }
    return area;
}