// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/1/20
// @Function	: 计算数组的中心下标，其左侧所有元素相加的和等于右侧所有元素相加的和


#include <iostream>
#include <vector>  // 添加 vector 头文件
#include <numeric> // 添加 accumulate 头文件
using namespace std;

class Solution {
public:
    int FindMidIndes(vector<int> &nums) {
        //nums.begin(), nums.end(),nums.size() 都是vector方法
        //accumulate(start, end, 0)：返回 [start, end) 范围内元素的累积和
        int total = accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (2 * sum + nums[i] == total) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};

int main() {
    Solution solution;                          // 创建 Solution 对象
    vector<int> nums = {1, 2, 3};               // 使用 vector 代替数组
    int index = solution.FindMidIndes(nums);    // 通过对象调用方法
    cout << "该数组的中心下标为：" << index << endl;
    return 0;
}
