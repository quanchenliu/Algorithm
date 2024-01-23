// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/1/20
// @Function	: 若a[i][j]=0,则将第i行和第j列的元素清零
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = (matrix.size() > 0) ? matrix[0].size() : 0;
        vector<vector<int>> rotated(rows, vector<int>(cols));
        rotated = matrix;
        cout<<rows<<' '<<cols<<endl;
        
        //先行后列遍历
        for(int i=0;i<rows;i++){                    //遍历一行 
            for(int j=0;j<cols;j++){                //遍历一列
                if(matrix[i][j] == 0){
                    for(int k=0;k<cols;k++){        //修改一行
                        rotated[i][k] = 0;
                    }
                    for(int k=0;k<rows;k++){        //修改一列
                        rotated[k][j] = 0;           
                    }
                }
            }
        }
        matrix = rotated;
    }
};

int main(){
    Solution solution;
    //vector<vector<int>> matrix = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    solution.setZeroes(matrix);
    return 0;
}
