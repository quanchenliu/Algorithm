// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/3/23
// @Function	: 一个枚举问题的示例

#include <iostream>
using namespace std;

int main(){
    for(int a=0;a<10;a++){
        for(int b=0;b<10;b++){
            for(int c=0;c<10;c++){
                int x1 = a*100 + b*10 +c;
                int x2 = b*100 + c*10 +c;
                int x = x1 + x2;
                if(x == 532){
                    printf("a=%d, b=%d, c=%d", a, b, c);
                }
            }
        }
    }
    
    return 0;
}