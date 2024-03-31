// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/3/25
// @Function	: 矩阵转置

#include <iostream>
#include <vector>
using namespace std;
bool Spin0(vector<vector<int>> a, vector<vector<int>> b, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] != b[i][j]){
                return false;
            }
        }
    }
    return true;
}
bool Spin90(vector<vector<int>> a, vector<vector<int>> b, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] != b[j][n-1-i]){
                return false;
            }
        }
    }
    return true;
}
bool Spin180(vector<vector<int>> a, vector<vector<int>> b, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] != b[n-1-i][n-1-j]){
                return false;
            }
        }
    }
    return true;
}
bool Spin270(vector<vector<int>> a, vector<vector<int>> b, int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j] != b[n-1-j][i]){
                return false;
            }
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;

    vector<vector<int>> a(n,vector<int>(n)), b(n,vector<int>(n));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>b[i][j];
        }
    }

    int angle = 0;
    if(Spin0(a, b, n)){
        angle = 0;
        cout<<angle<<endl;
        return 0;
    }
    if(Spin90(a, b, n)){
        angle = 90;
        cout<<angle<<endl;
        return 0;
    }
    if(Spin180(a, b, n)){
        angle = 180;
        cout<<angle<<endl;
        return 0;
    }
    if(Spin270(a, b, n)){
        angle = 270;
        cout<<angle<<endl;
        return 0;
    }
    angle = -1;
    cout<<angle<<endl;
    return 0;
}