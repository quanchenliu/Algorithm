// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/1/24
// @Function	: 快慢指针

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int fast=0,slow=0;
        for(fast=0;fast<len;fast++){
            if(nums[fast] != val){
                nums[slow] = nums[fast];
                slow++;
            }
        }
        return slow;
    }
};

int main(){
    Solution solution ;
    vector<int> nums = {3,2,2,3};
    int val = 3;
    int len = solution.removeElement(nums,val);
    for(int i=0;i<len;i++){
        cout<<nums[i];
    }
    cout<<endl;
    return 0;
}