#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        // 使用字符串流分割单词
        istringstream iss(s);            //创建istringstream 对象 iss，并将字符串 s 传递给它。   
        vector<string> words;
        string word;

        while (iss >> word) {           //使用 iss >> word 的形式，从 iss 中逐个提取单词并存储在 word 中
            words.push_back(word);      //然后将每个单词添加到 vector<string> 类型的容器 words 中
        }

        reverse(words.begin(), words.end());        // 反转单词顺序

        // 构建结果字符串
        string result;
        for (const string& w : words) {
            result += w + " ";
        }

        // 移除最后一个空格
        if (!result.empty()) {
            result.pop_back();
        }

        return result;
    }
};

int main() {
    Solution solution;
    string s = "the sky is blue";
    string reversed = solution.reverseWords(s);
    cout << reversed << endl;

    return 0;
}
