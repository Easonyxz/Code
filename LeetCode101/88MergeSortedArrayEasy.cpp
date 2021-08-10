#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <algorithm> 
using namespace std;
#include<vector>
//给定两个有序数组，把两个数组合并为一个。
/*
1 2 3 0 0 0
3
2 5 6
3
*/
int main()
{   
//输入是两个数组和它们分别的长度 m 和 n。其中第一个数组的长度被延长至 m + n，
//多出的n 位被 0 填补。
int m,n,i,j;
vector<int>num1;
vector<int>num2;
do{
        scanf("%d",&i);
        num1.push_back(i);
    }while(getchar()!='\n');
scanf("%d",&m);
do{
        scanf("%d",&i);
        num2.push_back(i);
    }while(getchar()!='\n');
scanf("%d",&n);
/*
因为这两个数组已经排好序，我们可以把两个指针分别放在两个数组的末尾，
即 nums1 的 m − 1 位和 nums2 的 n − 1 位。每次将较大的那个数字复制到 nums1 的后边，然后向前移动一位。
因为我们也要定位 nums1 的末尾，所以我们还需要第三个指针，以便复制。
在以下的代码里，我们直接利用 m 和 n 当作两个数组的指针，再额外创立一个 pos 指针，起
始位置为 m +n−1。每次向前移动 m 或 n 的时候，也要向前移动 pos。这里需要注意，如果 nums1
的数字已经复制完，不要忘记把 nums2 的数字继续复制；如果 nums2 的数字已经复制完，剩余
nums1 的数字不需要改变，因为它们已经被排好序。
*/
int pos = m-- + n-- - 1;
while (m >= 0 && n >= 0) {
//num1[m]是否比num2[n]大，是的话num1[pos]=num1[m],pos--,m--不是的话等于num2[n],pos--.n--
num1[pos--] = num1[m] > num2[n]? num1[m--]: num2[n--];
}
while (n >= 0) {
num1[pos--] = num2[n--];
} 

for(j=0;j<num1.size();j++)printf("%d ",num1[j]);

	return 0;
}
