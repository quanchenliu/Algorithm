// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/1/22
// @Function	: 子串倒序

#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


class Solution {
public:
    string reverseWords(string s) {
        string reverse_str = "";
        string str[10000],reverse[10000];
        int len = s.size();
        int i = 0,j = 0,num = 0;

        for(int k=0;k<len;k++){                          // 以空格为中断符，将原字符串变为字符数组
            if(s[k] != ' '){
                str[i] = str[i] + s[k];
                j++;
                //cout<<str[i]<<' '<<s[k]<<endl;
            }
            else{
                i++;j=0;
            }
        }
    
        for(int m=0;m<=i;m++){                          //消去字符串数组中的空白内容
            if(!str[m].empty()){
                reverse[num] = str[m];
                num++;
            }
        }

        for(int m=num-1;m>=0;m--){                              //完成单词拼接及倒序
            if(m != 0){
                reverse_str = reverse_str + reverse[m] +' ';
            }
            else{
                reverse_str = reverse_str + reverse[m];
            }
        }
        return reverse_str;
    }
};

int main() {
    Solution solution;
    string s = "a good   example";
    //string s = "the sky is blue";
    //string s = "  hello world  ";
    string strs = solution.reverseWords(s);
    cout <<"新的字符串为:"<<"\""<<strs<<"\""<<endl;
    return 0;
}