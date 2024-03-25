// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/3/25
// @Function	: 递推数列

#include <iostream>

using namespace std;

int define_array(int a0,int a1,int p,int q, int n){
    //cout<<p<<' '<<q<<endl;
    long long int a[n+1] = {0};
    a[0] = a0;
    a[1] = a1;
    //cout<<a[0]<<' '<<a[1]<<' ';
    for(int i=2;i<=n;i++){
        a[i] = (p*a[i-1] + q*a[i-2])%10000;
        //cout<<a[i]<<' ';
    }
    //cout<<endl;
    a[0] = a[0]%10000;
    a[1] = a[1]%10000;
    return a[n];
}
int main(){
    int a0, a1, p, q, k;
    cin>>a0>>a1>>p>>q>>k;
    long long int an = define_array(a0, a1, p, q, k);
    cout<<an<<endl;
    return 0;
}