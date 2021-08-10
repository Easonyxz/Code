#include<stdio.h>
#include<math.h>
#include<string.h>
double PI=3.14159265358979323;

int main()
{
    int n;
    double x;
    scanf("%d", &n);
    x=PI*pow(n,2);
    printf("%0.7lf", x);


return 0;
}
