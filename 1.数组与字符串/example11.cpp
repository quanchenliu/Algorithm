// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/1/22
// @Function	: 字符串模式匹配（暴力解）

#include <iostream>
#include <string>
using namespace std;

class Solution{
public:
    void get_next(int next[],string t){
        int i=1,j=0;
        next[1] = 0;
        while(i<t.size()){
            if(j == 0 || t[i] == t[j]){
                i++;j++;
            }
            else{
                j = next[j];
            }
        }
    }
    int Index_KMP(string s,string t){
        int i = 0,j = 0;
        int next[t.size()+1];
        get_next(next,t);
        while(i<=s.size() && j<=t.size()){
            if(j == 0 || s[i] == t[j]){
                i++;j++;
            }
            else    
                j = next[j];
        }
        if(j > t.size())
            return i - t.size();
        else
            return 0;
    }
};

int main(){
    Solution solution;
    string s = "ACTGPACTGKACTGPACY";
    string t = "ACTGPACY";
    int index = solution.Index_KMP(s,t);
    cout<<"子串出现的位置："<<index<<endl;
    return 0;
}