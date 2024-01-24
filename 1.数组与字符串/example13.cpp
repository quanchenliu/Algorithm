// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/1/24
// @Function	: 给定长度为 2n 的整数数组 nums ，你的任务是将这些数分成 n 对, 
//                例如 (a1, b1), (a2, b2), ..., (an, bn) ，使得从 1 到 n 的 min(ai, bi) 总和最大。
//                返回该最大总和 。

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void qSortArray(vector<int>& array, int start, int last){
        int low = start;
        int high = last;
        if (low < high){
            while (low < high){
                while (array[low] <= array[start] && low < last){       //满足小于基准的条件，指针右移
                    low++;
                }
                while (array[high] >= array[start] && high > start){    //满足大于基准的条件，指针左移
                    high--;
                }
                if (low < high){
                    swap(array[low], array[high]);                      //交换两个不满足条件的元素
                }
                else{
                    break;
                }
            }
            swap(array[start], array[high]);                            //插入基准元素
            qSortArray(array, start, high - 1);
            qSortArray(array, high + 1, last);
        }
    }
    int arrayPairSum(vector<int>& nums) {
        int len = nums.size();
        int min = 0;
        qSortArray(nums,0,len-1);
        for(int i=0;i<len;i+=2){
            min += nums[i];
        }
        return min;
    }
};

int main(){
    Solution solution;
    vector<int> a = {1,4,3,2};
    int min = solution.arrayPairSum(a);
    cout<<min<<endl;
    return 0;
}