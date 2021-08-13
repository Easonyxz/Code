#include <stdio.h>
#include <math.h>
#include <algorithm> 
using namespace std;

/*幸运数是波兰数学家乌拉姆命名的。它采用与生成素数类似的“筛法”生成

。
首先从1开始写出自然数1,2,3,4,5,6,....

1 就是第一个幸运数。

我们从2这个数开始。把所有序号能被2整除的项删除，变为：

1 _ 3 _ 5 _ 7 _ 9 ....

把它们缩紧，重新记序，为：

1 3 5 7 9 .... 。这时，3为第2个幸运数，然后把所有能被3整除的序号位置的数删去。注意，是序号位置，
不是那个数本身能否被3整除!! 删除的应该是5，11, 17, ...

此时7为第3个幸运数，然后再删去序号位置能被7整除的(19,39,...)

最后剩下的序列类似：

1, 3, 7, 9, 13, 15, 21, 25, 31, 33, 37, 43, 49, 51, 63, 67, 69, 73, 75, 79, ...
*/
int main()
{
int i,j=1,n,m,cnt=0,k=1,p,t,q=0;

scanf("%d%d",&n,&m);//程序输出 位于m和n之间的幸运数的个数（不包含m和n）。
int ans[m+1]={0};
for (i=0;i<=m;i++){
    ans[i]=i;
}

    for(j=2,i=1,p=j;j<=m&&j!=0&&ans[p]!=0&&p<=m;i++,p=i*j){
        ans[p]=0;
            for(t=1;t<=j-1&&ans[p+t]!=0;q++,t++){
                ans[j+q]=ans[p+t];ans[p+t]=0;
                }
            }k++;q=0;
 
while(j!=0){
    for(j=ans[k],i=1,p=j;j<=m&&p<=m&&ans[p]!=0;i++,p=i*j){
        if(ans[p]==0&&i==1)goto out;ans[p]=0;
            for(t=1;t<=j-1&&ans[p+t]!=0;q++,t++){
                ans[j+q]=ans[p+t];ans[p+t]=0;
                }
            }k++;q=0;
 }



out:for(i=1;ans[i]<m&&ans[i]!=0;i++){
    if(ans[i]>n)cnt++;
    }


printf("%d",cnt);

    return 0;
}