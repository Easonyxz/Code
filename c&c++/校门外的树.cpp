#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>

int main()
{

   int i, j, k, n, m, cnt;
   scanf("%d", &n);
   int a[n + 1];
   cnt = n + 1;
   for (i = 0; i < n; i++)
      a[i] = 1;
   scanf("%d", &m);
   int ans[m][2];
   for (i = 0; i < m; i++)
      for (j = 0; j < 2; j++)
      {
         scanf("%d", &ans[i][j]);
         if (ans[i][j] == 0)
            cnt--;
      }
   for (i = 0; i < m; i++)
   {
      for (k = ans[i][0] - 1; k < ans[i][1]; k++)
      {
         int *l = &a[k];
         if (*l == 1)
            cnt--;
         *l = 0;
      }
   }

   printf("%d", cnt);

   return 0;
}