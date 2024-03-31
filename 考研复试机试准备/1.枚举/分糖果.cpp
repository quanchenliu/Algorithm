// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/3/27
// @Function	: 分糖果
#include <iostream>
#include <vector>

using namespace std;
bool CheckCandy(vector<int> candy){
    int first = candy[0];
    for(int i=1;i<candy.size();i++){            // judge whether all the element are equal
        if(first != candy[i]){
            return false;
        }
    }
    return true;
}
void ShareTheCandy(int student_num, vector<int> &candy){
    int epochs=0, candy_num=0;
    while(!CheckCandy(candy)){                       // check whether all the element are equal
        //cout<<++epochs<<endl;
        epochs++;
        vector<int> half_candy(student_num, 0);
        for(int i=0;i<student_num;i++){            // half of the candy
            half_candy[i] = candy[i]/2;
        }
        for(int i=0;i<student_num;i++){            // add the half-candy
            candy[i] -= half_candy[i];
            candy[(i+1) % student_num] += half_candy[i];
        }
        for(int i=0;i<student_num;i++){            // if candy[i] is odd
            if(candy[i] % 2 != 0){
                candy[i]++;
            }
        }
    }
    cout<<epochs<<' '<<candy[0]<<endl;
}

int main(){
    int student_num;    
    while(scanf("%d", &student_num) != EOF){
        vector<int> candy(student_num);
        if(student_num == 0){
            break;
        }
        for(int i=0;i<student_num;i++){
            scanf("%d", &candy[i]);
        }
        //cout<<"candy size:"<<candy.size()<<endl;
        ShareTheCandy(student_num, candy);
    }
    return 0;
}