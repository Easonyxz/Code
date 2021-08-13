#include<time.h>
#include<stdlib.h>
#include<stdio.h>
#include <random>
#include <iostream>
int main()
{
    int Rnd,Num,i;
    srand((int)time(0));
	 for(i=0;i<1;i++)
 		{
            Num=rand()%20+1;
               printf("%d\n",Num);
        }
        system("pause");
    return 0;
}
