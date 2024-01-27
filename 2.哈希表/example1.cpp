// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/1/24
// @Function	: 不使用任何内建的哈希表库设计一个哈希集合（HashSet）。

#include <iostream>
#include <vector>  // 添加 vector 头文件
using namespace std;

class MyHashSet {
private:
    static const int size = 1000;
    vector<vector<int>> hashSet;

    int hashFunction(int key) {         // 哈希函数，决定 key 在哈希表中的位置
        return key % size;
    }

public:
    // MyHashSet() 是构造函数，调用 hashSet(size) 初始化二维 vector。
    MyHashSet() : hashSet(size) {}

    void add(int key) {
        int hashValue = hashFunction(key);
        for (int i : hashSet[hashValue]) {          // key 值已经存在
            if (i == key) {
                return; 
            }
        }
        hashSet[hashValue].push_back(key);          // 加入新的 key 值
    }

    void remove(int key) {
        int hashValue = hashFunction(key);
        // 用 auto 推断出 list 的类型为 vector<int>&
        auto& list = hashSet[hashValue];

        // it 不是直接的数值，而是一个指向 vector 元素的迭代器。*it 表示取迭代器指向的当前元素的值
        // ++it：迭代器自增，将其指向下一个元素。
        for (auto it = list.begin(); it != list.end(); ++it) {   
            if (*it == key) {
                list.erase(it);
                return; 
            }
        }
    }

    bool contains(int key) {
        int hashValue = hashFunction(key);
        for (int i : hashSet[hashValue]) {              // Key found
            if (i == key) {
                return true; 
            }
        }
        return false;                                   // Key not found
    }
};

int main() {
    MyHashSet myHashSet;
    myHashSet.add(1);
    myHashSet.add(2);

    // cout << boolalpha：boolalpha 意味着将布尔值的输出格式设置为 "true" 或 "false"，而不是默认的 1 或 0。
    //这意味着在输出布尔值时，将以 "true" 或 "false" 的形式显示，而不是以数字形式显示。
    cout << boolalpha;
    
    cout << myHashSet.contains(1) << endl;  // true
    cout << myHashSet.contains(3) << endl;  // false

    myHashSet.add(3);
    cout << myHashSet.contains(3) << endl;  // true

    myHashSet.remove(2);
    cout << myHashSet.contains(2) << endl;  // false

    return 0;
}
