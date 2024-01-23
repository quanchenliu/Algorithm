// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/1/22
// @Function	: 最长回文子串

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string strs = "";
        int len = s.length();
        int maxlen = 0;                 

        for(int i=0;i<len;i++){                         //遍历所有的子串
            for(int j=i;j<len;j++){                     //遍历从i开始的所有子串
                int len = j - i + 1;                    //记录当前子串的长度
                
                if(len > maxlen){                       
                    int start = i,end = j;
                    while(start < end){                 //判断子串是否是回文串

                        if(s[start] ==  s[end]){
                            start++;end--;
                        }
                        else break;
                    }
                    
                    if(start >= end){                    //若子串是回文串
                        maxlen = len;                   //更新最长回文子串长度记录
                        strs = s.substr(i,len);         //更新回文串记录
                    }   
                }
            }
        }
        return strs;
    }
};

int main() {
    Solution solution;
    string s = "babad";
    string strs = solution.longestPalindrome(s);
    cout <<"最大回文子串为: "<< strs << endl; 
    return 0;
}