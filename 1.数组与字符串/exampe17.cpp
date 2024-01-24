// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/1/24
// @Function	: 长度最小的子数组(暴力解，时间复杂度为：O(n^2))
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int len = nums.size();
        if (len == 0) {                             // 或者返回一个特殊值，表示空数组
            return 0; 
        }

        int minLen = 100000000; // 初始化为一个足够大的值
        for (int i = 0; i < len; i++) {
            int sum = 0;
            for (int j = i; j < len; j++) {
                sum += nums[j];
                if (sum >= target) {
                    minLen = min(minLen, j - i + 1);
                    break; // 如果已经找到一个满足条件的子数组，可以提前结束内部循环
                }
            }
        }
        return (minLen == 100000000) ? 0 : minLen;
    }
};

int main() {
    Solution solution;
    int target = 11;
    vector<int> nums = {1, 1, 1, 1, 1, 1, 1, 1};
    int len = solution.minSubArrayLen(target, nums);
    cout << len << endl;
    return 0;
}
