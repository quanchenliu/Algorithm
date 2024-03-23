// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/3/23
// @Function	: 与7无关的数

#include <iostream>
using namespace std;

bool UnRelative_7(int x){
    if(x<10 && x == 7){                     // 刚好是 7
        return false;
    }
    if(x>=10 && x%7 == 0){                  // 被 7整除
        return false;
    }
    while(true){                            // 含有 7
        int remain = x%10;
        x = x/10;
        if(remain == 7){
            return false;
        }
        if(x == 0){
            break;
        }
    }
    return true;
}

int main(){
    int n;
    int sum = 0;
    scanf("%d", &n);
    for(int i=0;i<=n;i++){
        if(UnRelative_7(i)){
            sum = sum + i*i;
            printf("i=%d, sum=%d\n", i, sum);
        }
    }
    printf("%d", sum);
    return 0;
}