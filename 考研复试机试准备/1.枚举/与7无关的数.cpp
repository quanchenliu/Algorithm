// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/3/23
// @Function	: 与7无关的数

#include <iostream>
using namespace std;

bool Relative_7(int x){
    if(x<10 && x==7){
        return true;
    }
    else{
        if(x%7 == 0){               // 被 7整除
            return true;
        }
        while(true){                // 含有 7
            int remain = x%10;
            x = x/10;
            if(remain == 7){
                return true;
            }
        }
    }
}

int main(){
    int n;
    int sum = 0;
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        if(Relative_7(i)){
            sum = sum + i*i;
            printf("sum=%d", sum);
        }
    }
    printf("%d", sum);
    return 0;
}