#include<stdio.h>
//一个整数的“反置数”指的是把该整数的每一位数字的顺序颠倒过来所得到的另一个整数。
//如果一个整数的末尾是以0结尾，那么在它的反置数当中，这些0就被省略掉了。
//比如说，1245的反置数是5421，而1200的反置数是21。请编写一个程序，输入两个整数，
//然后计算这两个整数的反置数之和sum，然后再把sum的反置数打印出来。
//要求：由于在本题中需要多次去计算一个整数的反置数，因此必须把这部分代码抽象为一个函数的形式。
int swap(int x)
{   
    
    int q=1;
    int p=0;
    int mask = 1;
    int t =x;
     while ( t>9 ) {
        t /=10;
        mask *=10;
    }

while ( mask > 0 ){
    int d = x / mask;
     p+=d*q;
            x%=mask;
            mask /=10;
            q*=10;
}

    
     return p;
}

int main()
{
int i;
int j;
int sum;

scanf("%d", &i);
scanf("%d", &j);
sum=swap(i)+swap(j);
printf("%d",swap(sum));
return 0;
}