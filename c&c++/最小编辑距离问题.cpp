#include<bits/stdc++.h>
//#include <iostream>
//#include <string.h>
//#include <vector>
//#include <algorithm>//min()包含头文件
using namespace std;
int main(){
	char str1[1025],str2[1025];//长度不超过1024,长度最小要声明为1024+1,因为字符串末尾有空字符。
	int n,m,temp;
	while(cin>>str1>>str2){//循环输入两个字符串
		m=strlen(str1);
		n=strlen(str2);
		vector<vector<int> > dp(m+1,vector<int>(n+1,0));//生成一个m+1行n+1列的二维矩阵记录当前的状态值
		//初始化
		for(int i=1;i<=m;i++)//dp[i][0]=i，例如dp[2][0]表示一个长度为2的字符串str1与一个空字符串str2的最小编辑距离为2（即依次将str1中的字符添加到str2中）
			dp[i][0]=i;
		for(int j=0;j<=n;j++)//dp[0][j]=j，例如dp[0][1]表示一个空字符串str1与一个长度为1的字符串str2的最小编辑距离为1（即依次将str2中的字符添加到str1中）
			dp[0][j]=j;
		dp[0][0]=0;//空字符串与空字符串之间的最小编辑距离为0
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(str2[j-1]==str1[i-1])//注意：字符串str1和str2中的索引是从0开始的，而1<=i<=m,1<=j<=n,所以这里的i和j要减1
					dp[i][j]=dp[i-1][j-1];
				else{
					temp=min(dp[i][j-1],dp[i-1][j]);
					dp[i][j]=min(temp,dp[i-1][j-1])+1;
				}	
			}
		}
		cout<<dp[m][n]<<endl;//最终的dp[m][n]为两字符串之间的最小编辑距离
	}
	return 0;
}