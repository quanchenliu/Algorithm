// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/3/27
// @Function	: 剩下的树

#include <iostream>
#include <vector>

using namespace std;

void DeleteTrees(vector<int> &Tree,vector<int> &m){
    for(int i=m[0];i<=m[1];i++){
        Tree[i] = 0;
    }
}
int main(){
    int L,M,num=0;
    cin>>L>>M;
    vector<int> Tree(L+1, 1);
    vector<int> m(2);
    int i=0;
    while(i<M){
        cin>>m[0]>>m[1];      
        DeleteTrees(Tree, m);
        i++;
    }
    for(int i=0;i<L+1;i++){
        if(Tree[i] == 1){
            num++;
        }
    }
    cout<<num<<endl;
    return 0;
}