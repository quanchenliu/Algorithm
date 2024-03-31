// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/3/24
// @Function	: xxx定律

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int n;
    int i=0;
    while(scanf("%d", &n) != EOF){
        while(n != 1){
            i++;
            if(n%2 == 0){
                n = n/2;
            }
            else{
                n = (3*n + 1)/2;
            }
        }
        printf("%d", i);
    }
    return 0;
}