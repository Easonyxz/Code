#include<bits/stdc++.h>
//#include <iostream>
//#include <string.h>
//#include <vector>
//#include <algorithm>//min()����ͷ�ļ�
using namespace std;
int main(){
	char str1[1025],str2[1025];//���Ȳ�����1024,������СҪ����Ϊ1024+1,��Ϊ�ַ���ĩβ�п��ַ���
	int n,m,temp;
	while(cin>>str1>>str2){//ѭ�����������ַ���
		m=strlen(str1);
		n=strlen(str2);
		vector<vector<int> > dp(m+1,vector<int>(n+1,0));//����һ��m+1��n+1�еĶ�ά�����¼��ǰ��״ֵ̬
		//��ʼ��
		for(int i=1;i<=m;i++)//dp[i][0]=i������dp[2][0]��ʾһ������Ϊ2���ַ���str1��һ�����ַ���str2����С�༭����Ϊ2�������ν�str1�е��ַ���ӵ�str2�У�
			dp[i][0]=i;
		for(int j=0;j<=n;j++)//dp[0][j]=j������dp[0][1]��ʾһ�����ַ���str1��һ������Ϊ1���ַ���str2����С�༭����Ϊ1�������ν�str2�е��ַ���ӵ�str1�У�
			dp[0][j]=j;
		dp[0][0]=0;//���ַ�������ַ���֮�����С�༭����Ϊ0
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(str2[j-1]==str1[i-1])//ע�⣺�ַ���str1��str2�е������Ǵ�0��ʼ�ģ���1<=i<=m,1<=j<=n,���������i��jҪ��1
					dp[i][j]=dp[i-1][j-1];
				else{
					temp=min(dp[i][j-1],dp[i-1][j]);
					dp[i][j]=min(temp,dp[i-1][j-1])+1;
				}	
			}
		}
		cout<<dp[m][n]<<endl;//���յ�dp[m][n]Ϊ���ַ���֮�����С�༭����
	}
	return 0;
}