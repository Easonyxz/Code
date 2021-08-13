#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;
#include <vector>
#include <iostream>
#include <string>

const int maxn = 50010;
vector<int> A(maxn,0);
int n;
int lowbit(int n);
int getsum(int x);
void update(int x, int num);

int main()
{


printf("%d",6-lowbit(6));


  return 0;
}


int lowbit(int n)
{
  return n & (-n);
}

int getsum(int x)
{
  int s = 0;

  while (x > 0)
  {

    s += A[x];

    x -= lowbit(x);
  }

  return s;
}

void update(int x, int num)
{

  while (x <= n)
  {

    A[x] += num;

    x += lowbit(x);
  }
}