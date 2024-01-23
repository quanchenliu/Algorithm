// -*- coding: utf-8 -*-
// @Author  	: quanchenliu
// @Time	   	: 2024/1/20
// @Function	: 合并区间

#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    if (intervals.empty()) {
        return {};
    }

    // 按照区间的起始位置进行排序
    //Lambda 表达式的参数是两个 vector<int> 类型的引用（a 和 b），返回值是一个布尔值。
    //该 Lambda 表达式表示比较两个区间的起始位置：若 a[0] < b[0]，则返回 true，表示 a 应该排在 b 前面，否则返回 false
    sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });

    vector<vector<int>> merged;
    merged.push_back(intervals[0]);     //将排序后的区间集合中的第一个区间添加到新的合并区间集合 merged 中

    for (int i = 1; i < intervals.size(); ++i) {
        //merged.back()[1]：函数返回 merged 最后一个合并的区间，并通过 [1] 取得最后一个合并区间的结束位置。
        if (merged.back()[1] >= intervals[i][0]) {
            merged.back()[1] = max(merged.back()[1], intervals[i][1]);      // 合并重叠的区间
        } 
        else {
            // 不重叠，添加新区间
            merged.push_back(intervals[i]);
        }
    }
    return merged;
}
