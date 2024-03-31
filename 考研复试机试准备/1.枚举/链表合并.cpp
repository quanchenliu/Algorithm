// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/3/31
// @Function	: 链表合并

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

void Union(int s1, int s2, int S1[], int S2[]){
    int S[s1+s2];
    int i=0, j=0, k=0;
    while(i<s1 && j<s2){
        if(S1[i] <= S2[j]){
            S[k++] = S1[i++];
        }
        else{
            S[k++] = S2[j++];
        }
        cout<<S[k-1]<<' ';
    }
    cout<<endl;
    cout<<i<<' '<<j<<endl;
    
    if(i >= s1){
        for(;j<s2;j++){
            S[k++] = S2[j];
            cout<<S[k-1]<<' ';
        }     
    }
    cout<<endl;
    if(j >= s2){
        for(;i<s1;i++){
            S[k++] = S1[i];
            cout<<S[k-1]<<' ';
        }
    }
    cout<<endl;
    
    for(int t=0;t<s1+s2;t++){
        cout<<S[t]<<' ';
    }
    cout<<endl;
}

int main(){
    int s1, s2;
    cin>>s1;
    int S1[s1];
    for(int i=0;i<s1;i++){
        cin>>S1[i];
    }

    cin>>s2;
    int S2[s2];
    for(int i=0;i<s2;i++){
        cin>>S2[i];
    }
    Union(s1, s2, S1, S2);
    return 0;
}