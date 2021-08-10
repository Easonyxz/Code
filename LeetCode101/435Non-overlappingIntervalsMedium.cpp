#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <algorithm> 
using namespace std;
#include<vector>

/*给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意:

可以认为区间的终点总是大于它的起点。
区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。

*/

int main()
{
int n;//给定区间个数
scanf("%d",&n);
//创建 n*2 的二维数组 
vector<vector<int>>intervals(n, vector<int>(2)); 
int ans[n][2];
int i,j,k;
for(i=0;i<n;i++){
    for (j=0;j<2;j++){
        scanf("%d",&intervals[i][j]);
    }
}


//把区间按照结尾的大小进行增序排序，每次选择结尾最小且和前一个选
//择的区间不重叠的区间。
sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b) {
return a[1] < b[1];
});


int total = 0, prev = intervals[0][1];
for (int i = 1; i < n; ++i) {
if (intervals[i][0] < prev) {
++total;
} else {
prev = intervals[i][1];
} }

//输出需要移除区间的最小数量
printf("%d\n",total);



    return 0;  
}
