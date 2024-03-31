// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/3/27
// @Function	: 完数和盈数
#include <iostream>
#include <vector>

using namespace std;

void PRINT(vector<int> output){
    for(int i=0;i<output.size();i++){
        if(i != output.size()-1){
            cout<<output[i]<<' ';
        }
        else{
            cout<<output[i]<<endl;
        }
    }
}

int Judge(int x){
    vector<int> factor;
    int sum = 0;
    //cout<<x<<' ';
    for(int i=1;i<x;i++){
        if(x % i == 0){                 // if i is the factor of x
            factor.push_back(i);
        }
    }
    for(int i=0;i<factor.size();i++){
        sum += factor[i];
    }
    //cout<<sum<<endl;
    if(sum == x){
        return 1;
    }
    else if(sum > x){
        return 2;
    }
    return 0;
}

int main(){
    vector<int> wan,ying;

    for(int i=2;i<=60;i++){
        if(Judge(i) == 1){
            wan.push_back(i);           // if x is perfect number
        }
        else if(Judge(i) == 2){
            ying.push_back(i);
        }
    }

    cout<<"E: ";
    PRINT(wan);
    cout<<"G: ";
    PRINT(ying);
    return 0;
}