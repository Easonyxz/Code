//
// Created by zhengwei.
//


/*
奖券数目

        有些人很迷信数字，比如带“4”的数字，认为和“死”谐音，就觉得不吉利。
虽然这些说法纯属无稽之谈，但有时还要迎合大众的需求。
 某抽奖活动的奖券号码是5位数（10000-99999），要求其中不要出现带“4”的号码，主办单位请你计算一下，
 如果任何两张奖券不重号，最多可发出奖券多少张。

请提交该数字（一个整数），不要写任何多余的内容或说明性文字。
*/
#include <iostream>
#include <sstream>
#include <string>
using namespace std;

void i2s(int num, string &str) {
    stringstream ss;
    ss << num;
    ss >> str;
}

int main(int argc, const char * argv[]) {
    int ans=0;
    for (int i = 10000; i <=99999 ; ++i) {
        string s;
        i2s(i,s);
        if(s.find('4')==string::npos)ans++;
    }
    cout<<ans<<endl;
    return 0;
}