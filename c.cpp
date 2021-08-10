#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
/*
8
1 2 3 4 5 6 7 8
*/

vector<int> binaryIndexedTree;
vector<int> arr;
int n;
int lowbit(int n);
void upData(int x, int y);
int getsum(int x);

int main()
{
  int k;
  binaryIndexedTree.push_back(-1);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d", &k);
    arr.push_back(k);
    binaryIndexedTree.push_back(k);
  }

  for (int i = 1; i <= n; i++)
  {
    int j = i + (i & -i);
    if (j < n + 1)
    {
      binaryIndexedTree[j] += binaryIndexedTree[i];
    }
  }

  for (int i = 1; i < binaryIndexedTree.size(); i++)
  {
    printf("%d ", binaryIndexedTree[i]);
  }
  printf("\n");
  upData(1, 6);
printf("%d\n",lowbit(1));
  for (int i = 1; i < binaryIndexedTree.size(); i++)
  {
    printf("%d ", binaryIndexedTree[i]);
  }

  return 0;
}

int lowbit(int n)
{
  return n & (-n);
}

void upData(int x, int y)
{
  
  for (int i =x; i <= n; i += lowbit(i))
    binaryIndexedTree[i] += y;
}
int getsum(int x)
{
  int ans = 0;
  for (int i = x; i > 0; i -= lowbit(i))
    ans += binaryIndexedTree[i];
  return ans;
}