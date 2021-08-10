#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <queue>

int main(){
int target,i;
vector<int>numbers;


do{
        scanf("%d",&i);
        numbers.push_back(i);
    }while(getchar()!='\n');
	printf("Case %d",numbers[0]);
	return 0;
}
