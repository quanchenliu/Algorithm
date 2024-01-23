// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/1/20
// @Function	: 对角线输出
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        size_t rows = mat.size();
        size_t cols = (mat.size() > 0) ? mat[0].size() : 0;
        bool find[rows][cols];
        vector<int> output;
        int k = 0;//用于区别下标变化规律

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(i == 0 || i == rows-1){
                    find[i][j] = true;
                }
                else if(j == 0 || j == cols-1){
                    find[i][j] = true;
                }
            }
        }
        // for(int i=0;i<rows;i++){
        //     for(int j=0;j<cols;j++){
        //         cout<<find[i][j];
        //     }
        //     cout<<endl;
        // }
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(find[i][j]){
                    
                }
            }
        }

        
        return output;
    }
};

int main(){
    Solution solution;
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    solution.findDiagonalOrder(mat);
    return 0;
}
