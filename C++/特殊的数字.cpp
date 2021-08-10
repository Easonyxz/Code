#include<stdio.h>
#include<math.h>
//153是一个非常特殊的数，它等于它的每位数字的立方和，即153=1*1*1+5*5*5+3*3*3。
//编程求所有满足这种条件的三位十进制数。
int main()
{
    int n;
    int n1;
    int n2;
    int n3;

  for(n=100;n<1000;n++){
      n1=n/100;
      n2=n/10%10;
      n3=n%10;
      if(pow(n1,3)+pow(n2,3)+pow(n3,3)==n)
      printf("%d\n",n);
  }



return 0;
}