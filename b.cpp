#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <algorithm> 
using namespace std;
#include<vector>
#include<numeric>


int main()
{
double in=0.1,pmt=100;
for (int i=0;i<19;i++){
   pmt*=(1+in);
   pmt+=100;
}

printf("%lf",pmt);
    return 0;   
}