// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/1/24
// @Function	: 略

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int len = numbers.size(), i = 0, j = len - 1;
        vector<int> sum;
        while (i < j) {
            if (numbers[i] + numbers[j] < target) {
                i++;
            } else if (numbers[i] + numbers[j] > target) {
                j--;
            } else {
                sum.push_back(i + 1);
                sum.push_back(j + 1);
                return sum;
            }
        }
        for(j=i;j<len;j++){
            if(numbers[i] + numbers[j] == target){
                sum.push_back(i+1);
                sum.push_back(j+1);
                return sum;
            }
        }
        return sum;
    }
};

int main() {
    Solution solution;
    vector<int> a = {-1,0};
    vector<int> b = solution.twoSum(a,-1);
    // 输出结果
    cout << "Indices: ";
    for (int num : b) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
