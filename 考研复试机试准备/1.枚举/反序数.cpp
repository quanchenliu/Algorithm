// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/3/23
// @Function	: 反序数

#include <iostream>
using namespace std;

int main(){
    for(int order = 1000;order<10000;order++){
        int d = order%10;                   // 个位数
        int c = (order%100 - d) / 10;       // 十位数
        int b = (order/100) % 10;           // 百位数
        int a = order/1000;                 //千位数
        int re_order = d*1000 + c*100 + b*10 + a;
        
        if (re_order == 9*order){
            printf("%d", order);
        }
    }
    return 0;
}