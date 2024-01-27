// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/1/24
// @Function	: 反转字符串中的单词
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverse_word(string& s, int i, int j){
        for(int t = i; t <= (j+i)/2;t++){
            swap(s[t], s[j+i-t]);
        }
    }

    string reverseWords(string s) {
        int i = 0, j = 0;
        for(;j< s.size();j++){
            if(s[j] == ' '){
                reverse_word(s, i, j-1);
                i = j+1;
            }
        }
        reverse_word(s, i, j-1);
        return s;
    }
};

int main(){
    Solution solution;
    string s = "Let's take LeetCode contest";       // s'teL ekat edoCteeL tsetnoc
    s = solution.reverseWords(s);
    cout<<s<<endl;
    return 0;
}