#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <algorithm> 
using namespace std;
#include<vector>
/*
5 800
200 36
100 16	
300 45
600 60
250 10
*/

int main()
{   

int n,i,j,volume,price=0;

//输入物品数量和背包总体积

scanf("%d%d", &n,&volume);
double CostPerformance[n],p,k;
int MerchandiseVolume[n];
int MerchandisePrice[n];

//创建 n*2的二维数组
vector<vector<double>>intervals(n, vector<double>(2)); 
//输入物品体积和价格
for (i=0;i<n;i++){
 scanf("%d",&MerchandiseVolume[i]);
 scanf("%d", &MerchandisePrice[i]);
 CostPerformance[i]=(double)MerchandisePrice[i]*1.0/(double)MerchandiseVolume[i]*1.0;
}

//标记性价比和原本物品的序号
for (i=0;i<n;i++){
    intervals[i][0]=CostPerformance[i];
    intervals[i][1]=i;
}

//按性价比排名
sort(intervals.begin(), intervals.end());

for (i=n-1;i>=0;i--){
    if (MerchandiseVolume[(int)intervals[i][1]]<=volume){volume-=MerchandiseVolume[(int)intervals[i][1]];price+=MerchandisePrice[(int)intervals[i][1]];}
    else {p=((double)volume/(double)MerchandiseVolume[(int)intervals[i][1]]);k=(p*MerchandisePrice[(int)intervals[i][1]]);price+=k;break;}

}


 printf("%d",price);



	return 0;
}

