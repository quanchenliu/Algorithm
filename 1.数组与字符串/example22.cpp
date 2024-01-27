// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/1/24
// @Function	: 将数组 nums中所有 0 移动到数组的末尾，同时保持非零元素的相对顺序（原地操作）
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k = 0;
        int fast = 0,slow = 0;
        for(fast = 0;fast<nums.size();fast++){
            if(nums[fast] == 0){
                k++;
            }
            else{
                nums[fast - k] = nums[fast];
            }
        }
        for(fast = nums.size() - k;fast<nums.size();fast++){
            nums[fast] = 0;
        }
    }
};

int main(){
    Solution solution;
    vector<int> nums = {0};
    solution.moveZeroes(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<' ';
    }
    cout<<endl;
    return 0;
}


















