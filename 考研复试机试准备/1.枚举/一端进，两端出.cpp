// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/3/31
// @Function	: 一端进，两端出

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

bool check(vector<int> a, vector<int> b){
    int length = a.size();
    int q[length];
    int front = 0, rear = -1;
    for(int i=0, j=0;i<length;i++){
        q[++rear] = a[i];
        
        // 通过内嵌的 while 循环，不断地检查当前队列头部元素是否与序列 b 中的元素相同
        while(front <= rear){
            if(q[front] == b[j]){           // 头部元素已经匹配，并将其从队列中弹出
                j++;front++;                
            }
            else if(q[rear] == b[j]){       // 如果不匹配，则判断队列尾部元素是否与当前元素相同
                j++;rear--;                 // 将尾部元素从队列中弹出
            }
            else{
                break;
            }
        }
    }
    return front > rear;
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<int> a(n), b(n);
    for (int i=0;i<n;i++){
        cin >> a[i];
    } 

    while (k--){
        for(int i=0;i<n;i++){
            cin>>b[i];
        } 
        if (check(a, b)){
            cout<<"yes"<<endl;
        } 
        else{
            cout<<"no"<<endl;
        } 
    }
    return 0;
}
