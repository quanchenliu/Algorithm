// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/1/24
// @Function	: 原地删除重复元素
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int r=0;
        int fast = 0, slow = 0;
        for(fast = 1;fast<nums.size();fast++){
            if(nums[fast] == nums[slow]){
                r++;
            }
            else{
                nums[fast - r] = nums[fast];
                slow = fast;
            }
        }
        return nums.size() - r;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    int k;
    k = solution.removeDuplicates(nums);
    cout<<"k = "<<k<<"; "<<endl;
    for(int i=0;i<k;i++){
        cout<<nums[i]<<' ';
    }
    cout<<endl;
    return 0;
}