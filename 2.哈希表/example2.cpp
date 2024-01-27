// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/1/24
// @Function	: 不使用任何内建的哈希表库设计一个哈希映射（HashMap）。

#include <iostream>
#include <vector>
using namespace std;

class MyHashMap {
private:
    static const int size = 1000001;  // 选择一个足够大的素数作为哈希表的大小
    vector<int> hashMap;

public:
    MyHashMap() : hashMap(size, -1) {}

    void put(int key, int value) {
        hashMap[key] = value;
    }

    int get(int key) {
        return hashMap[key];
    }

    void remove(int key) {
        hashMap[key] = -1;
    }
};

int main() {
    MyHashMap myHashMap;
    myHashMap.put(1, 1);
    myHashMap.put(2, 2);
    cout << myHashMap.get(1) << endl;  // 返回 1
    cout << myHashMap.get(3) << endl;  // 返回 -1
    myHashMap.put(2, 1);
    cout << myHashMap.get(2) << endl;  // 返回 1
    myHashMap.remove(2);
    cout << myHashMap.get(2) << endl;  // 返回 -1
    return 0;
}
