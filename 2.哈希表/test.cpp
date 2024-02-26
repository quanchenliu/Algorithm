#include <iostream>
#include <vector>
using namespace std;

int main(){
    // 定义并初始化一个 vector 容器
    vector<int> vi;
    for(int i=0;i<=5;i++){
        vi.push_back(i);                        // 在 vector 容器的末尾添加元素 i
    }

    // 使用迭代器访问并输出
    vector<int>::iterator it = vi.begin();      // vi.begin(): 用于取 vi 的首元素地址
    for(int i=0;i<5;i++){
        cout<<*(it + i)<<' ';
    }
    cout<<endl;
    return 0;
}