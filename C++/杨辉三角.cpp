#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
  int n;
  long long i, j, k, l;

  scanf("%d", &n);

  int a[n];
  int b[n];
  for (i = 0; i < n; i++)
  {
    a[i] = 1;
    b[i] = 1;
  }

  if (n == 1)
  {
    printf("1");
    return 0;
  }
  if (n == 2)
  {
    printf("1\n1 1");
    return 0;
  }
  printf("1\n1 1\n");
  for (i = 3; i < n + 1; i++)
  {
    for (j = 1; j < i - 1; j++)
    {
      b[j] = a[j - 1] + a[j];
    }
    for (k = 1; k < j; k++)
    {
      a[k] = b[k];
    }
    for (l = 0; l < i; l++)
      printf("%lld ", b[l]);
    printf("\n");
  }

  return 0;
}
