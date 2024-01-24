// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/1/24
// @Function	: 最大连续 1的个数

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = nums.size();
        int fast = 0,maxnum = 0,num = 0;
        for(fast=0;fast<len;fast++){
            if(nums[fast] == 1){
                num++;
            }
            else{
                if(num > maxnum){
                    maxnum = num;
                }
                num = 0;
            }
            if(num > maxnum){
                maxnum = num;
            }
        }
        return maxnum;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {1,0,1,1,0,1};
    int maxnum = solution.findMaxConsecutiveOnes(nums);
    cout<<"该数组最大的连续1的个数为："<<maxnum<<endl;
    return 0;
}