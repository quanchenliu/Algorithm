// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/3/23
// @Function	: 约数的个数

#include <iostream>
using namespace std;
int Num(int x){
    int num = 0;
    for(int i=1;i*i<=x;i++){
        if (x % i == 0){
            if (i * i == x) // 区别所在,重点理解
                num++;
            else
                num += 2;
        }
    }
    return num;
}

int main(){
    int n;                          // 进行数据的输入
    scanf("%d", &n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d", &a[i]);
    }
    
    int num[n];
    for(int i=0;i<n;i++){
        num[i] = Num(a[i]);
        printf("%d\n", num[i]);
    }
    return 0;
}