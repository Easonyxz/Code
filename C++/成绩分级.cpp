#include <iostream>
#include<stdio.h>
#include <algorithm> 
using namespace std; 
#include<vector>
 


int main(){
    
int i,j,k,n;
scanf("%d", &n);if(n>100||n<0) return 0;
i=n/10;
switch(i){
    case 10:printf("A"); break;
    case 9:printf("A"); break;
    case 8:printf("B"); break;
    case 7:printf("C"); break;
    case 6:printf("D"); break;
    default:printf("E"); break;
}


return 0;
}