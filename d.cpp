#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;
#include <vector>
#include <string>
#include <iostream>
#include <queue>

struct point
{
    int x, y, root;
};
point ans[100000];
vector<int> wayx;
vector<int> wayy;
int arr1[] = {-1, 1, 0, 0};
int arr2[] = {0, 0, -1, 1};

vector<int> directionx(arr1, arr1 + 4);
vector<int> directiony(arr2, arr2 + 4);

void print(point p);
void bfs(vector<vector<int>> &maze, int a, int b);
int main()
{

    int n, m;
    scanf("%d %d", &n, &m);
    string t;
    vector<vector<int>> maze(n, vector<int>(m));
    getchar();
    for (int i = 0; i < n; i++)
    {
        getline(cin, t);
        for (int j = 0; j < m; j++)
        {
            maze[i][j] = t[j] - '0';
        }
    }
    vector<string> character;
    character.push_back("UDLR");

    maze[0][0] = 2;
    wayx.push_back(0);
    wayy.push_back(0);
    bfs(maze, 0, 0);

    printf("%d\n", wayx.size() - 1);
    for (int i = 0; i < wayx.size(); i++)
    {
        for (int j = 0; j < 4; j++)
        {

            if ((wayx[i] + directionx[j]) == wayx[i + 1] && (wayy[i] + directiony[j]) == wayy[i + 1])
                cout << character[0][j];
        }
    }

    return 0;
}

void bfs(vector<vector<int>> &maze, int a, int b)
{
    int cnt = 0, k = 0;
    point p;
    p.x = a;
    p.y = b;
    p.root = -1;
    queue<point> q;
    q.push(p);
    ans[0] = p;
    cnt++;
    while (!q.empty())
    {
        point m = q.front();
        q.pop();
        if (p.x == maze.size() - 1 && p.y == maze[0].size() - 1)
        {

            print(p);
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int _x = m.x + directionx[i];
            int _y = m.y + directiony[i];

            if (_x >= 0 && _x < maze.size() && _y >= 0 && _y < maze[0].size() && maze[_x][_y] != 1 && maze[_x][_y] != 2)
            {

                maze[_x][_y] = 2;
                p.x = _x;
                p.y = _y;
                p.root = k;

                q.push(p);

                ans[cnt++] = p;
            }
        }
        k++;
    }
}


void print(point p)
{
    while (p.root != -1)
    {

        print(ans[p.root]);

        wayx.push_back(p.x);
        wayy.push_back(p.y);

        return;
    }
}
