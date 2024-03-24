// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/3/24
// @Function	: 叠筐

#include <iostream>
#include <vector>

using namespace std;

void Fuzhi(int k, int i, int j, vector<vector<char>>& kuang, char a, char b){
    if(k%2 == 0){           
        kuang[i][j] = b;
    }
    else{                   
        kuang[i][j] = a;
    }
}

void Pattern(int n, int i, vector<vector<char>>& kuang, char a, char b){
    if(i<=n/2){                     // 1 ~ n/2 行
        for(int j=0;j<i;j++){       // 前 i 个元素，交替，与列号相关
            Fuzhi(j, i, j, kuang, a, b);
        }
        for(int j=i;j<n-1-i;j++){   // 中间 n-2i 个元素，一致，与行号相关
            Fuzhi(i, i, j, kuang, a, b);
        }
        for(int j=n-1-i;j<n;j++){   // 后 i 个元素，交替
            Fuzhi(j, i, j, kuang, a, b);
        }
    }
    else{                           // 后 n/2 行
        for(int j=0;j<n;j++){
            kuang[i][j] = kuang[n/2 - (i-n/2)][j];
        }
    }
}

int main(){
    int n;
    char a,b;
    scanf("%d %c %c", &n, &a, &b);
    
    vector<vector<char>> kuang(n, vector<char>(n, ' '));
    for(int i=0;i<n;i++){
        if(i == 0 || i == n-1){
            if( (n/2)%2 == 0){
                for(int j=1;j<n-1;j++){
                    kuang[i][j] = a;
                }
            }
            else{
                for(int j=1;j<n-1;j++){
                    kuang[i][j] = b;
                }
            }
        }
        else{
            Pattern(n, i, kuang, a, b);
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << kuang[i][j];
        }
        cout << endl;
    }

    return 0;
}