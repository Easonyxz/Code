#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
/*
给定一个起始字符串和一个终止字符串，以及一个单词表，求是否可以将起始字符串每次改
一个字符，直到改成终止字符串，且所有中间的修改过程表示的字符串都可以在单词表里找到。
若存在，输出需要修改次数最少的所有更改方式。

输入是两个字符串，输出是一个二维字符串数组，表示每种字符串修改方式。
*/
/*// Input: beginWord = "hit", endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
// Output:
// [["hit","hot","dot","dog","cog"],*/
/*
hit cog 
hot dot dog lot log cog
*/
void backtracking(const string &src, const string &dst, unordered_map<string, vector<string>> &next, vector<string> &path, vector<vector<string>> &ans)
{
    if (src == dst)
    {
        ans.push_back(path);
        return;
    }
    for (const auto &s : next[src])
    {
        path.push_back(s);
        backtracking(s, dst, next, path, ans);
        path.pop_back();
    }
}

int main()
{
    string beginWord, endWord;
    vector<string> wordList;
    string x;
    cin >> beginWord >> endWord;
    for (int i = 0; i < 6; i++)
    {
        cin >> x;
        wordList.push_back(x);
    }
    vector<vector<string>> ans;
    unordered_set<string> dict;
    for (const auto &w : wordList)
    {
        dict.insert(w);
    }
    if (!dict.count(endWord))
    {
        return 0;
    }
    dict.erase(beginWord);
    dict.erase(endWord);
    unordered_set<string> q1{beginWord}, q2{endWord};
    unordered_map<string, vector<string>> next;
    bool reserved = false, found = false;
    while (!q1.empty())
    {
        unordered_set<string> q;
        for (const auto &w : q1)
        {
            string s = w;
            for (size_t i = 0; i < s.size(); i++)
            {
                char ch = s[i];
                for (int j = 0; j < 26; j++)
                {
                    s[i] = j + 'a';
                    if (q2.count(s))
                    {
                        reserved ? next[s].push_back(w) : next[w].push_back(s);
                        found = true;
                    }
                    if (dict.count(s))
                    {
                        reserved ? next[s].push_back(w) : next[w].push_back(s);
                        q.insert(s);
                    }
                }
                s[i] = ch;
            }
        }
        if (found)
        {
            break;
        }
        for (const auto &w : q)
        {
            dict.erase(w);
        }
        if (q.size() <= q2.size())
        {
            q1 = q;
        }
        else
        {
            reserved = !reserved;
            q1 = q2;
            q2 = q;
        }
    }
    if (found)
    {
        vector<string> path = {beginWord};
        backtracking(beginWord, endWord, next, path, ans);
    }
    if (ans.size() > 0)
    {
        for (int i = 0; i < ans.size(); i++)
        {
            for (int j = 0; j < ans[i].size(); j++)
            {
                cout << ans[i][j] << endl;
            }
        }
    }

    return 0;
}
