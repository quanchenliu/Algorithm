// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/1/20
// @Function	: 将矩阵旋转90°
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = (matrix.size() > 0) ? matrix[0].size() : 0;
        vector<vector<int>> rotated(cols, vector<int>(rows));
        //cout<<rows<<' '<<cols<<endl;
        
        //先行后列遍历
        for(int i=0;i<rows;i++){                
            for(int j=0;j<cols;j++){
                rotated[i][j] = matrix[rows-1-j][i];
            }
        }
        matrix = rotated;
        //const auto& row 表示在每次迭代中，row 将引用 rotated 中的一行。
        //matrix 是一个二维向量，所以 row 是一个一维向量（行）
        for (const auto& row : matrix) {
            //int num 表示在每次迭代中，num 将取得 row 中的一个元素。
            for (int num : row) {
                cout << num << ' ';
            }
            cout << endl;
        }
    }
};

int main(){
    Solution solution;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    solution.rotate(matrix);
    
    return 0;
}