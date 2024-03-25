// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/3/23
// @Function	: 水仙花数

#include <iostream>
#include <cmath>
using namespace std;

int flower_num(int x){
    int flower = 0;
    int remain = 0;
    while(true){
        remain = x % 10;
        x = x / 10;
        flower = flower + pow(remain, 3);
        if(x == 0){
            break;
        }
    }
    return flower;
}

void Judge(int min, int max){
    int a[max-min+1] = {0};
    int k=0;
    for(int i = min; i <= max; i++){
        if(i == flower_num(i)){
            a[k] = i;
            k++;
        }
    }
    if(k == 0){
        printf("no\n");
        return ;
    }
    for(int i=0;i<k;i++){
        if(i<k-1){
            printf("%d ", a[i]);
        }
        else if(i == k-1){
            printf("%d\n", a[i]);
        }
    }
}

int main(){
    int a[10][2];
    int i, j;
    for(i = 0; i < 10; i++){ // 输入测试数据
        for(j = 0; j < 2; j++){
            scanf("%d", &a[i][j]);
        }
        if(a[i][0] == 0 && a[i][1] == 0){
            break;
        }
    }

    for(int k = 0; k < i; k++){
        Judge(a[k][0], a[k][1]);
    }
    return 0;
}