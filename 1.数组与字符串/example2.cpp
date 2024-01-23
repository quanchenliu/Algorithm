// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/1/20
// @Function	: 查找元素下标，若元素不在数组中，则返回该元素应插入的位置下标

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0,high = nums.size() - 1;
        int mid = (low + high)/2;

        while(low <= high){
            mid = low + (high - low)/2;     //在处理大整数范围的情况下，这样处理能够避免整数溢出
            //cout<<low<<' '<<mid<<' '<<high<<endl;
            if(nums[mid] == target){        //找到目标值，返回索引
                return mid;
            }
            else if(nums[mid] < target){    //目标值在右半部分
                low = mid+1;
            }
            else if(nums[mid] > target){    //目标值在左半部分
                high = mid-1;
            }
            //cout<<low<<' '<<mid<<' '<<high<<endl;
        }

        return high+1;
    }
};


int main(){
    Solution solution;
    vector<int> nums = {1,3,5,6};
    int target,answer;
    cin>>target;
    answer = solution.searchInsert(nums,target);
    cout<<answer<<endl;
    return 0;
}