//
// Created by zhengwei.
//
/*
生命之树

在X森林里，上帝创建了生命之树。

他给每棵树的每个节点（叶子也称为一个节点）上，都标了一个整数，代表这个点的和谐值。
上帝要在这棵树内选出一个非空节点集S，使得对于S中的任意两个点a,b，都存在一个点列 {a, v1, v2, ..., vk, b}
 使得这个点列中的每个点都是S里面的元素，且序列中相邻两个点间有一条边相连。

在这个前提下，上帝要使得S中的点所对应的整数的和尽量大。
这个最大的和就是上帝给生命之树的评分。

经过atm的努力，他已经知道了上帝给每棵树上每个节点上的整数。但是由于 atm 不擅长计算，他不知道怎样有效的求评分。
 他需要你为他写一个程序来计算一棵树的分数。

「输入格式」
第一行一个整数 n 表示这棵树有 n 个节点。
第二行 n 个整数，依次表示每个节点的评分。
接下来 n-1 行，每行 2 个整数 u, v，表示存在一条 u 到 v 的边。由于这是一棵树，所以是不存在环的。

「输出格式」
输出一行一个数，表示上帝给这棵树的分数。

「样例输入」
5
1 -2 -3 4 5
4 2
3 1
1 2
2 5

「样例输出」
8

「数据范围」
对于 30% 的数据，n <= 10
对于 100% 的数据，0 < n <= 10^5, 每个节点的评分的绝对值不超过 10^6 。

资源约定：
峰值内存消耗 < 256M
CPU消耗  < 3000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

所有代码放在同一个源文件中，调试通过后，拷贝提交该源码。

注意: main函数需要返回0
注意: 只使用ANSI C/ANSI C++ 标准，不要调用依赖于编译环境或操作系统的特殊函数。
注意: 所有依赖的函数必须明确地在源文件中 #include <xxx>， 不能通过工程设置而省略常用头文件。

提交时，注意选择所期望的编译器类型。
*/
#include <iostream>
#include <vector>

using namespace std;
int n;
const int MaxN = 1e5;
long long w[MaxN + 1];//每个点的权重
//long long ww[MaxN + 1];//每个点作为根节点时能得到的最大权和
long long ans;
vector<int> g[MaxN + 1];//邻接表

/*以root为根，算出最大的权和*/
void dfs(int root, int fa) {
//    ww[root] = w[root];
    for (int i = 0; i < g[root].size(); ++i) {
        int son = g[root][i];//其中一个孩子
        if (son != fa) {
            dfs(son, root);
            if (w[son] > 0)
                w[root] += w[son];
        }
    }
    if (w[root] > ans)ans = w[root];
}

int main(int argc, const char *argv[]) {
    freopen("/Users/zhengwei/workspace/lanqiaobei2019/src/2015_Java_B/data10/in8.txt","r",stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &w[i]);
    }
    for (int j = 0; j < n - 1; ++j) {
        int u, v;
        scanf("%d %d", &u, &v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
//    输入处理完成
    dfs(1, 0);
    printf("%lld\n", ans);
    return 0;
}