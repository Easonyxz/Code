//
// Created by zhengwei.
//
/*
标题：小朋友排队

    n 个小朋友站成一排。现在要把他们按身高从低到高的顺序排列，但是每次只能交换位置相邻的两个小朋友。

    每个小朋友都有一个不高兴的程度。开始的时候，所有小朋友的不高兴程度都是0。

    如果某个小朋友第一次被要求交换，则他的不高兴程度增加1，如果第二次要求他交换，则他的不高兴程度增加2（即不高兴程度为3），依次类推。
    当要求某个小朋友第k次交换时，他的不高兴程度增加k。

    请问，要让所有小朋友按从低到高排队，他们的不高兴程度之和最小是多少。

    如果有两个小朋友身高一样，则他们谁站在谁前面是没有关系的。

【数据格式】

    输入的第一行包含一个整数n，表示小朋友的个数。
    第二行包含 n 个整数 H1 H2 … Hn，分别表示每个小朋友的身高。
    输出一行，包含一个整数，表示小朋友的不高兴程度和的最小值。

例如，输入：
3
3 2 1
程序应该输出：
9

【样例说明】
   首先交换身高为3和2的小朋友，再交换身高为3和1的小朋友，再交换身高为2和1的小朋友，每个小朋友的不高兴程度都是3，总和为9。


【数据规模与约定】
    对于10%的数据， 1<=n<=10；
    对于30%的数据， 1<=n<=1000；
    对于50%的数据， 1<=n<=10000；
    对于100%的数据，1<=n<=100000，0<=Hi<=1000000。


资源约定：
峰值内存消耗 < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。
*/
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int lowbit(int n) {
    return n - (n & (n - 1));
}

/**
 * 原始数组的i位置增加v后，更新c数组
 * @param i
 * @param v
 * @param c
 */
void updata(int n, int i, int v, int c[]) {

    for (int k = i; k <= n; k += lowbit(k)) {
        c[k] += v;
    }
}

int getSum(int c[], int i) {
    int sum = 0;
    for (int k = i; k >= 1; k -= lowbit(k)) {
        sum += c[k];
    }
    return sum;
}

int h[100000];
long long cnt[100000];//记录每个孩子的交换次数
int c[1000000 + 1];

int main(int argc, const char *argv[]) {
//    int arr[]={1,2,3,4,5,6,7,8};
//    int c[9];
//    memset(c,0, sizeof(c));
//    for (int i = 0; i < 8; ++i) {
//        updata(9,i+1,arr[i],c);
//    }
//    cout<<getSum(c,5)<<endl;
//    cout<<getSum(c,6)<<endl;
//    cout<<getSum(c,7)-getSum(c,4)<<endl;
//    freopen("/Users/zhengwei/Desktop/其他/input8 (1).txt", "r", stdin);
    int n;
    scanf("%d", &n);

//    memset(cnt,0,sizeof(cnt));
    int maxH = -1;
    for (int i = 0; i < n; ++i) {
        scanf("%d", &h[i]);
        if (h[i] > maxH)maxH = h[i];
    }

    for (int i = 0; i < n; ++i) {
        updata(maxH + 1, h[i] + 1, 1, c);//在响应位置计数变为1，其实就是用树状数组维护数据出现的个数
        //
        int sum = getSum(c, h[i] + 1);//小于等于h[i]+1的数据的个数
        cnt[i] += (i + 1) - sum;//得到的就是当前数据左侧比数据大的数的个数
    }

    memset(c, 0, sizeof(c));
    for (int i = n - 1; i >= 0; --i) {
        updata(maxH + 1, h[i] + 1, 1, c);//在响应位置计数变为1，其实就是用树状数组维护数据出现的个数
        //
//        int sum = getSum(c, h[i] + 1);//小于等于h[i]+1的数据的个数
//        int self = getSum(c,h[i]+1)-getSum(c,h[i]);
//        cnt[i] += sum-self;//上一步求出小于等于h的个数，扣掉自己的个数，得到的就是当前数据右侧比数据小的数的个数
        cnt[i] += getSum(c, h[i]);//求出小于h[i]+1 的数据的个数
    }
    long long ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (cnt[i] * (cnt[i] + 1) / 2);
    }
    printf("%lli\n", ans);
    return 0;
}