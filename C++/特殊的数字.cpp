#include<stdio.h>
#include<math.h>
//153��һ���ǳ��������������������ÿλ���ֵ������ͣ���153=1*1*1+5*5*5+3*3*3��
//�������������������������λʮ��������
int main()
{
    int n;
    int n1;
    int n2;
    int n3;

  for(n=100;n<1000;n++){
      n1=n/100;
      n2=n/10%10;
      n3=n%10;
      if(pow(n1,3)+pow(n2,3)+pow(n3,3)==n)
      printf("%d\n",n);
  }



return 0;
}