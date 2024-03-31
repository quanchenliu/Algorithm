#include <iostream>
#include <vector>
#include <deque>
using namespace std;

struct SpaceBlock{
    int locate;
    int length;
    int next;
};

void AllocateBlock(vector<SpaceBlock>& block, vector<int> apply, int N){
    int now_locate = 0;
    
    for(int i = 0; i < apply.size(); i++){
        int min_locate = now_locate;                    // 记录最小空闲块下标
        int min_length = block[now_locate].length;      // 记录最小空闲块长度
        int apply_length = apply[i];
        
        cout<<"apply_length="<<apply_length<<' ';
        cout << "now_locate=" << block[now_locate].locate << ' ' ;
        cout<< "now_length=" << block[now_locate].length << endl;

        for(int times = 0; times < N; times++){
            // 找到满足要求的最小块，并更新最小标记
            if(apply_length <= block[now_locate].length && block[now_locate].length < min_length){
                min_length = block[now_locate].length;
                min_locate = now_locate;
                //cout << "min_locate=" << block[min_locate].locate << ' ' << "min_length=" << min_length << endl;
            }
            now_locate = (now_locate + 1) % N;
        }
        now_locate = min_locate;
        block[now_locate].length -= apply_length;

        cout << "min_locate=" << block[min_locate].locate << ' ' << "min_length=" << min_length << endl;
        cout << "now_locate=" << block[now_locate].locate << ' ' << "now_length=" << block[now_locate].length << endl;
        
        if(block[now_locate].length <= 0){                  // 若最小空闲块被完全分配
            block.erase(block.begin() + now_locate);
            now_locate = block[min_locate].next;            // 当前位置变为最小空闲块指向的下一空闲块
            block[min_locate-1].next = now_locate;
            cout<<now_locate<<endl;
            N--;
            int j = now_locate;
            for(int i = 0; i < N; i++){
                cout << block[j].locate << ' ' << block[j].length << endl;
                j = (j+1) % N;
            }
            
        }
        cout << "now_locate=" << block[now_locate].locate << ' '<< "now_length=" << block[now_locate].length << endl;

    }
    
    int j = now_locate;
    for(int i = 0; i < N; i++){
        cout << block[j].locate << ' ' << block[j].length << endl;
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