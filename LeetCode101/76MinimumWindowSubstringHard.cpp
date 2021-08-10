#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include <algorithm> 
#include<iostream>
using namespace std;
#include<vector>
#include<string>
/*
给定两个字符串 S 和 T，求 S 中包含 T 所有字符的最短连续子字符串的长度，同时要求时间
复杂度不得超过 O(n)。
本题使用滑动窗口求解，即两个指针 l 和 r 都是从最左端向最右端移动，且 l 的位置一定在
r 的左边或重合。注意本题虽然在 for 循环里出现了一个 while 循环，但是因为 while 循环负责移
动 l 指针，且 l 只会从左到右移动一次，因此总时间复杂度仍然是 O(n)。本题使用了长度为 128
的数组来映射字符，也可以用哈希表替代；其中 chars 表示目前每个字符缺少的数量，flag 表示
每个字符是否在 T 中存在。
Input: S = "ADOBECODEBANC", T = "ABC"   
Output: "BANC"
ADOBECODEBANC
ABC
*/
int main()
{ 
string S,T,U;
getline(cin,S);
getline(cin,T);
vector<int> chars(128, 0);
vector<bool> flag(128, false);
// 先统计T中的字符情况
for(int i = 0; i < T.size(); ++i) {
   flag[T[i]] = true;
   ++chars[T[i]];
   }
// 移动滑动窗口，不断更改统计数据
int cnt = 0, l = 0, min_l = 0, min_size = S.size() + 1;
for (int r = 0; r < S.size(); ++r) {
   if (flag[S[r]]) {
      if (--chars[S[r]] >= 0) {
      ++cnt;
      }
// 若目前滑动窗口已包含T中全部字符，
// 则尝试将l右移，在不影响结果的情况下获得最短子字符串
   while (cnt == T.size()) {
      if (r - l + 1 < min_size) {
      min_l = l;
      min_size = r - l + 1;
      }
      if (flag[S[l]] && ++chars[S[l]] > 0) {
      --cnt;
      }
      ++l;
      } 
   } 
}
//获得字符串S中从第min_l位开始的长度为min_size的字符串
U=min_size > S.size()? "": S.substr(min_l, min_size);
cout<<U<<endl;
   return 0;
}