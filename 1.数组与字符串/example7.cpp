// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/1/22
// @Function	: 查找字符串数组中的最长公共前缀;如果不存在公共前缀，返回空字符串 ""

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string prefix = strs[0];                            // 将第一个字符串设为初始的最长前缀
        
        if (strs.empty()) return "";                        // 如果输入为空，返回空字符串

        // 遍历后续字符串，不断更新最长前缀
        for (int i = 1; i < strs.size(); i++) {
            int j = 0;
            while (j < prefix.size() && j < strs[i].size() && prefix[j] == strs[i][j]){
                ++j;
            }
            prefix = prefix.substr(0, j);                   // 截取出当前最长前缀
            if (prefix.empty())  return "";                 // 如果最长前缀为空，说明不存在公共前缀，直接返回
        }
        return prefix;
    }
};

int main() {
    Solution solution;
    vector<string> strs = {"flower","flow","flight"};
    string maxstr = solution.longestCommonPrefix(strs);
    cout << maxstr << endl; 
    return 0;
}
