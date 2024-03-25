// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/3/25
// @Function	: 特殊乘法

#include <iostream>

using namespace std;

int main(){
    int a, b;
    scanf("%d %d", &a, &b);
    int a_re, b_re, sum, b_temp;
    sum = 0;
    b_temp = b;
    while(true){
        a_re = a%10;
        a = a/10;
        while(true){
            b_re = b%10;
            b = b/10;
            sum = a_re * b_re + sum;
            if(b == 0){
                break;
            }
        }
        b = b_temp;
        if(a == 0){
            break;
        }
    }
    cout<<sum<<endl;
    return 0;
}