#include <iostream>
#include<stdio.h>
#include <algorithm> 
using namespace std; 
#include<iostream>
#include<vector>
 
using namespace std;
 
int fun(int n,int v,vector<int> weight,vector<int> price,vector<int> res){
    for(int i=1;i<=n;++i){
        for(int j=v;j>=weight[i];--j){//ע��j�����v��ʼ
                res[j] = max(res[j-weight[i]]+price[i],res[j]);
        }
    }
    return res[v];
}
 
int main(){
    int n,v;//nΪ��Ʒ������vΪ�������
    cin>>n>>v;
    
    vector<int> weight(n+1,0);
    vector<int> price(n+1,0);
    vector<int> res(v+1);
    
    for(int i=1;i<=n;++i){
        cin>>weight[i]>>price[i];//�����������ͼ۸�
    }
    
    int ans = fun(n,v,weight,price,res);
    cout<<ans<<endl;
    
    return 0;
}