// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/3/24
// @Function	: 叠筐

#include <iostream>
#include <vector>

using namespace std;

void diekuang(char pattern, int num, int n, vector<vector<char>>& kuang){
    int mid = n/2;
    int temp = mid - num;
    int i = mid - num;
    int j = mid - num;
    for(int k=0;k<2*num;k++,j++){       // 上行
        kuang[i][j] = pattern;
    }
    for(int k=0;k<2*num;k++,i++){       // 右列 
        kuang[i][j] = pattern;
    }
    for(int k=0;k<2*num;k++,j--){       // 下行 
        kuang[i][j] = pattern;
    }
    for(int k=0;k<2*num;k++,i--){       // 左列 
        kuang[i][j] = pattern;
    }
}

int main(){
    int n;                              // 矩阵大小
    char a,b;                           // a是中心花色字符，b是外筐花色字符
    scanf("%d %c %c", &n, &a, &b);
    vector<vector<char>> kuang(n, vector<char>(n, ' '));
    int mid = n/2;                      // 矩阵中心位置
    kuang[mid][mid] = a;                // 设置中心位置的字符
    for(int i=1;i<=mid;i++){             // 一共有 mid 圈，循环 mid 次
        if(i%2 != 0){
            diekuang(b, i, n, kuang);
        }
        else{
            diekuang(a, i, n, kuang);
        }
    }
    kuang[0][0] = ' ';
    kuang[0][n-1] = ' ';
    kuang[n-1][0] = ' ';
    kuang[n-1][n-1] = ' ';

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<kuang[i][j];
        }
        cout<<endl;
    }

    return 0;
}