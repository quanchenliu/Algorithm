// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/1/24
// @Function	: 杨辉三角
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> array(numRows); // 先定义二维数组的行数
        for(int i=0;i<numRows;i++){         // 初始化数组
            array[i].resize(i+1);           // 动态定义二维数组每一行的列数
            array[i][0] = 1;
            array[i][i] = 1;
        }
        if(numRows <= 2){                  
            return array;
        }
        for(int i=2;i<numRows;i++){
            for(int j=1;j<i;j++){
                array[i][j] = array[i-1][j] + array[i-1][j-1];
            }
        }
        return array;
    }
};

int main(){
    Solution solution;
    int numRows = 2;
    vector<vector<int>> generate_array(numRows,vector<int>(numRows,0));
    generate_array = solution.generate(numRows);
    for(int i=0;i<numRows;i++){             // 输出数组
        for(int j=0;j<numRows;j++){
            cout<<generate_array[i][j]<<' ';
        }
        cout<<endl;
    }
    return 0;
}