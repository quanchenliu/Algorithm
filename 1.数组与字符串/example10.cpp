// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/1/23
// @Function	: 字符串模式匹配（暴力解）

#include <iostream>
#include <string>
using namespace std;

class Solution{

public:
    int findindex_violent(string s, string t){
        int i,j;
        for( i=0;i<s.size();i++){
            for( j=0;j<t.size();j++){
                if(s[i+j] != t[j]){
                    break;
                }
            }
            if(j == t.size()){
                break;
            }
        }
        if(j == t.size())
            return i;
        else        
            return -1;
    }    
};

int main(){
    Solution solution;
    string s = "ACTGPACTGKACTGPACY";
    string t = "ACTGPACY";
    int index = solution.findindex_violent(s,t);
    cout<<"子串第一次出现的位置为："<<index<<endl;
    return 0;
}