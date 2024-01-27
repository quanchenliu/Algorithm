// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/1/24
// @Function	: 杨辉三角(输出第 i 行)
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> generate(int rowIndex) {
        int numRows = rowIndex + 1;
        vector<vector<int>> array(numRows); // 先定义二维数组的行数
        vector<int> array_index(numRows);
        for(int i=0;i<numRows;i++){         // 初始化数组
            array[i].resize(i+1);           // 动态定义二维数组每一行的列数
            array[i][0] = 1;
            array[i][i] = 1;
        }
        if(numRows <= 2){
            for(int i=0;i<numRows;i++){
                array_index[i] = array[rowIndex][i];
            }                  
            return array_index;
        }
        for(int i=2;i<numRows;i++){
            for(int j=1;j<i;j++){
                array[i][j] = array[i-1][j] + array[i-1][j-1];
            }
        }
        for(int i=0;i<numRows;i++){
            array_index[i] = array[rowIndex][i];
        }
        return array_index;
    }
};

int main(){
    Solution solution;
    int rowIndex = 1;
    vector<int> generate_array(rowIndex+1);
    generate_array = solution.generate(rowIndex);
    for(int i=0;i<rowIndex+1;i++){
        cout<<generate_array[i]<<' ';
    }
    cout<<endl;
    return 0;
}