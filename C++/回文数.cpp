#include<stdio.h>

int main()
{
    /*1221是一个非常特殊的数，它从左边读和从右边读是一样的，
    编程求所有这样的四位十进制数。*/
 int i,i1,i2,i3,i4;
 for(i=1000;i<10000;i++){
i1=(i/1000);
i2=(i/100%10);
i3=(i/10%10);
i4=(i-i1*1000-i2*100-i3*10);
 if(i1==i4&&i2==i3)
 printf("%d\n",i);
 }

return 0;
}
