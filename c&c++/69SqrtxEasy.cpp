#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <algorithm> 
using namespace std;
#include<vector>
//给定一个非负整数，求它的开方，向下取整。
int main()
{ 
    int a;scanf("%d", &a);
/*
这道题还有一种更快的算法——牛顿迭代法，其公式为 xn+1 = xn − f (xn)/ f ′(xn)。给
定 f (x) = x2 − a = 0，这里的迭代公式为 xn+1 = (xn + a/xn)/2，
*/
long x = a;
while (x * x > a) {
x = (x + a / x) / 2;
}
 printf("%ld",x);   
    
    return 0;
}