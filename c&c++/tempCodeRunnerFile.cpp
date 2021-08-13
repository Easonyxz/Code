#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <algorithm> 
using namespace std;
#include<vector>
#include<string>
#include<iostream>
#include<time.h>
/*
标题：带分数

    100 可以表示为带分数的形式：100 = 3 + 69258 / 714

    还可以表示为：100 = 82 + 3546 / 197

    注意特征：带分数中，数字1~9分别出现且只出现一次（不包含0）。

    类似这样的带分数，100 有 11 种表示法。

题目要求：
从标准输入读入一个正整数N (N<1000*1000)
程序输出该数字用数码1~9不重复不遗漏地组成带分数表示的全部种数。
注意：不要求输出每个表示，只统计有多少表示法！


例如：
用户输入：
100
程序输出：
11

再例如：
用户输入：
105
程序输出：
6
*/

void check(int i,int n,int p,int &cnt,string a);
int main() {
int n,i,j,k,cnt=0,p;
scanf("%d",&n);
string a="123456789";
//clock_t t1 = clock();
do{
for (i=1;i<9;++i){
    //从0开始截取i长度的a
    string b=a.substr(0,i);
    //c_str把字符串转化为char
    //atoi把字符串转化为int
    //c++11可以用stoi
    p=atoi(b.c_str());
    if (p>=n)
    {break;}
    //检查是否等于n
    check(i,n,p,cnt,a);
}
}while (next_permutation(a.begin(),a.end()));

printf("%d",cnt);
//如果要算时间的话
 //clock_t t2 = clock();
   // cout<<"Total time = "<<t2-t1<<endl;
return 0;

}

void check(int i,int n,int p,int &cnt,string a){
  
for (int j=1;j<9-i-1;++j){
  string c=a.substr(i,j);
  string d=a.substr(j+i);
  int s=atoi(c.c_str());
  int q=atoi(d.c_str());
  if (s%q==0&&(p+s/q)==n)
  cnt++; 
    }
}