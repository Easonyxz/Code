#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
   int n;
   int i, j, k = 1, cnt = 1, q = 1;
   int a[10000] = {0};
   a[1] = 1;
   scanf("%d", &n);

   for (i = 1; i < n + 1; i++)
   {
      for (j = cnt; j > 0; j--)
      {
         a[j] *= i;
         for (q = j; q < cnt + 1; q++)
         {
            if (a[q] > 9)
            {
               k = a[q] / 10;
               a[q] = a[q] % 10;
               a[q + 1] += k;
            }
         }
         if (a[cnt + 1] > 0)
            cnt++;
      }
   }

   for (i = cnt; i > 0; i--)
      printf("%d", a[i]);

   return 0;
}
