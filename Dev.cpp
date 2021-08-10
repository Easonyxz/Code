#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;
#include <vector>



int main()
{
  
int year=1,mouth=1,day=1;
scanf("%d %d",&mouth,&day);
int cnt=48;
while(year<3){
    day+=cnt;
    if(day>30){int s=day/30;mouth+=s;day%=30;}
    if(mouth>12){year++;mouth-=12;}
    printf("%dÄê--%dÔÂ--%dÈÕ\n",year,mouth,day);
}
system("pause");

    return 0;
}
