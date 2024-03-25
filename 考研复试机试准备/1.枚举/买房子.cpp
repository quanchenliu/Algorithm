// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/3/25
// @Function	: 买房子
#include <iostream>
#include <vector>
using namespace std;

int main(){
    float income, price, rate, acc;

    while(scanf("%f %f", &income, &rate) != EOF){

        int year_count = 1;
        price = 200;
        acc = income;
        while(1){
            if(acc>=price && year_count<=21){
                cout<<year_count<<endl;
                break;
            }
            price = price + price * (rate/100);
            acc = acc + income;
            cout<<price<<' '<<acc<<endl;
            
            if(year_count>21){
                cout<<"Impossible"<<endl;
                break;
            }
            year_count++;
        }
    }
}