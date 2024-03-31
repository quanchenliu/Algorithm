// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/3/23
// @Function	: 对称平方数

#include <iostream>
using namespace std;

int Reverse(int x){
    int reverse = 0;
    int remain;
    if(x<10){
        return x;
    }
    while (true){
        remain = x % 10;
        x = x / 10;
        reverse = reverse*10 + remain; 
        if(x == 0){
            break;
        } 
    }
    return reverse;
}

int main(){
    int n_square, reverse;
    for(int n=0;n<=256;n++){
        n_square = n*n;
        reverse = Reverse(n_square);
        // printf("n_square=%d, reverse=%d\n", n_square,reverse);
        if(reverse == n_square){
            printf("%d\n", n);
        }
    }
    return 0;
}