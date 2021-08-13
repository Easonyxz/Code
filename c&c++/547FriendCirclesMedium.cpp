#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <algorithm> 
using namespace std;
#include<vector>
/*
给定一个二维的 0-1 矩阵，如果第 (i, j) 位置是 1，则表示第 i 个人和第 j 个人是朋友。已知
朋友关系是可以传递的，即如果 a 是 b 的朋友，b 是 c 的朋友，那么 a 和 c 也是朋友，换言之这
三个人处于同一个朋友圈之内。求一共有多少个朋友圈。
输入是一个二维数组，输出是一个整数，表示朋友圈数量。因为朋友关系具有对称性，该二
维数组为对称矩阵。同时，因为自己是自己的朋友，对角线上的值全部为 1。
Input:
[[1,1,0],
[1,1,0],
[0,0,1]]
Output: 2
在这个样例中，[1,2] 处于一个朋友圈，[3] 处于一个朋友圈。

*/
void dfs(vector<vector<int>>& friends, int i, vector<bool>& visited);
int main()
{   
vector<vector<int>>friends(4,vector<int>(4));
{
    friends[0]={1,0,1,0};
    friends[1]={0,1,1,0};
    friends[2]={1,1,1,0};
    friends[3]={0,0,0,1};
}
int n = friends.size(), count = 0;
vector<bool> visited(n, false);
for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
    dfs(friends, i, visited);
    ++count;
    } 
}
 printf("%d",count);   
    
    return 0;
}

void dfs(vector<vector<int>>& friends, int i, vector<bool>& visited) {
visited[i] = true;
for (int k = 0; k < friends.size(); ++k) {
    if (friends[i][k] == 1 && !visited[k]) {
    dfs(friends, k, visited);
        } 
    } 
}