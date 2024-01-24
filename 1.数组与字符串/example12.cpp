// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/1/24
// @Function	: 原地字符数组倒序

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        int i = 0,j = len-1,temp ;
        while(i < j){
            temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            i++;j--;
        }
    }
};

int main(){
    Solution soluton;
    vector<char> s = {'l', 'e', 'e', 't', 'c', 'o', 'd', 'e'};
    soluton.reverseString(s);
    for(char c : s){
        cout<<c;
    }
    cout<<endl;
}