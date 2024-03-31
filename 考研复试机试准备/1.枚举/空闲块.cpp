// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/3/31
// @Function	: 空闲块

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct SpaceBlock{
        int locate;
        int length;
        int next;
    };

void AllocateBlock(vector<SpaceBlock> block, vector<int> apply, int N){
    int min_locate=0, min_length=block[0].length;
    int now_locate = 0;
    
    for(int i=0;i<apply.size();i++){                            // 依次为每个申请分配空闲块
        int j = now_locate;                                     // 从当前位置开始遍历空闲链表
        for(int times=0;times<N;times++){                       // 寻找满足条件的最小块
            if(apply[i] <= block[j].length){                    
                if(block[j].length < min_length){               
                    min_length = block[j].length;
                    min_locate = j;
                }                                
            }
            j = (j+1)%N;
            
        }
        cout<<"min_locate="<<block[min_locate].locate<<' '<<"min_length="<<min_length<<endl;
        now_locate = min_locate;                                  // 找到满足要求的最小块，更新当前位置
        block[now_locate].length -= apply[i];                     // 更新当前最小块的长度 
        cout<<"now_locate="<<block[now_locate].locate<<' '<<"now_length="<<block[now_locate].length<<endl;
        if(block[now_locate].length == 0){                        // 若最小块被完全分配，将该块清除出空闲链表
            block[now_locate-1].next = block[now_locate].next;  
            block.erase(now_locate);
            now_locate = (now_locate+1) % N; 
            N--;
        }
        cout<<"now_locate="<<block[now_locate].locate<<' '<<"now_length="<<block[now_locate].length<<endl;
    }
    int j = now_locate;
    for(int i=0;i<N;i++){
        cout<<block[j].locate<<' '<<block[j].length<<endl;
        j = (j+1) % N;
    }
}
int main(){
    int N;
    cin>>N;
    vector<SpaceBlock> block(N);
    vector<int> apply;
    for(int i=0;i<N;i++){
        cin>>block[i].locate;
        cin>>block[i].length;
        block[i].next = i+1;
    }
    block[N-1].next = 0;
   
    int i = 0, a;
    cin>>a;
    while(a != -1){
        apply.push_back(a);
        cin>>a;
    }
   
    AllocateBlock(block, apply, N);

    return 0;
}