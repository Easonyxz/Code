#include <stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main(){
int i,j,c,k,n,Money;
//������Ǯ������Ʒ����
scanf("%d",&Money);
scanf("%d",&n);

i=n+1;j=Money+1;
int Memo[i][j];

int MerchandisePrice[n],MerchandiseValue[n];
//������Ʒ�۸�����Ҫ��
for(i=0;i<n;i++){
  scanf("%d",&MerchandisePrice[i]);
  scanf("%d",&MerchandiseValue[i]);
}

for(i=1;i<n+1;i++){
 for(j=1;j<Money+1;j++){
     if(j >= MerchandisePrice[i-1])
                Memo[i][j] = max(Memo[i-1][j], Memo[i-1][j-MerchandisePrice[i-1]] + MerchandiseValue[i-1]*MerchandisePrice[i-1]);
            else
                Memo[i][j] = Memo[i-1][j];
        }

    }


printf("%d",Memo[i-1][j-1]);



return 0;
}

