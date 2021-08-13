#include <stdio.h>


int main(){

int Volume,Price,KnapsackVolume,n,i,j,c,k;
scanf("%d", &n);//输入商品数量
scanf("%d",&KnapsackVolume);//输入背包体积
i=n+1;j=KnapsackVolume+1;
int Memo[i][j],Rec[i][j];
int MerchandiseVolume[n];
int MerchandisePrice[n];

for (i=0;i<n;i++){
 scanf("%d",&MerchandiseVolume[i]);//输入物品体积和价格
 scanf("%d", &MerchandisePrice[i]);
}
for (i=0;i<n+1;i++){              //初始化
    for (j=0;j<KnapsackVolume+1;j++){
    Memo[i][j]=0;Rec[i][j]=0;
    }
}


for(i=1;i<n+1;i++){
 for(c=1;c<KnapsackVolume+1;c++){
    if( MerchandiseVolume[i-1]<=c && Memo[i-1][c-MerchandiseVolume[i-1]]+MerchandisePrice[i-1]>Memo[i-1][c])
        {Memo[i][c]=Memo[i-1][c-MerchandiseVolume[i-1]]+MerchandisePrice[i-1];Rec[i][c]=1;}
    else { Memo[i][c]=Memo[i-1][c];Rec[i][c]=0;}

    }
}
/*
//输出最优解方案
k=KnapsackVolume;
for(i=n;i>0&&K>0;i--){//倒序判断是否选择该商品
    if(Rec[i][k]==1){printf("%d\n",i);k=k-MerchandiseVolume[i-1];}
}*/
printf("%d",Memo[n][KnapsackVolume]);




return 0;
}

