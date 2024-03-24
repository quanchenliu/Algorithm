// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/3/24
// @Function	: 打印菱形图案

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

void f(int n,int i){
    for(int j=0;j<2*(n-i);j++){
        printf("%c", ' ');
    }
    for(int j=0;j<=i;j++){
        printf("%d ", j);
    }
    for(int j=i-1;j>=0;j--){
        printf("%d ", j);
    }
    printf("\n");
}
void PRINT(int n){
    for(int i=0;i<=n;i++){
        f(n, i);
    }
    for(int i=n-1;i>=0;i--){
        f(n, i);
    }
}
int main(){
    int n;
    scanf("%d", &n);
    PRINT(n);
    return 0;
}