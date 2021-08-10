#include<stdio.h>
//　给定一个N阶矩阵A，输出A的M次幂（M是非负整数）
int main()
{
int i;
int j;
int n;
int p;
int q;
int l;
int m;


scanf("%d",&i);
if(i>30||i<0)return 0;
scanf("%d",&j);
if(j>5||j<0)return 0;
int matrix[i][i];
int matrix1[i][i];
int matrix2[i][i];

for (n=0;n<i;n++){
    for (l=0;l<i;l++){
        matrix2[n][l]=0;
    }}
for (n=0;n<i;n++){ matrix2[n][n]=1;}
if(j==0) goto out;


for (n=0;n<i;n++){
    for (p=0;p<i;p++){
 scanf("%d",&matrix[n][p]);
}
}

for(q=0;q<j;q++){
    for (n=0;n<i;n++){
    for (l=0;l<i;l++){
        matrix1[n][l]=0;
    }}
 for (n =0;n <i;n++){
         for (m=0;m<i;m++){
              for (l=0;l<i;l++){
 matrix1[n][m]+=(matrix2[n][l]*matrix[l][m]);
         }
}
} 
  for (n =0;n <i;n++){
         for (m=0;m<i;m++){matrix2[n][m]=matrix1[n][m];}
      

}
}

out:
for (n=0;n<i;n++){
    for (p=0;p<i;p++){
        if(p==i-1)printf("%d",matrix2[n][p]);
        else printf("%d ",matrix2[n][p]);
}printf("\n");
}
return 0;
}
