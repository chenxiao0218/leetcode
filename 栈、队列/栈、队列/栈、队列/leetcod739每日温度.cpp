#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res;
        res.resize(temperatures.size());
        stack<int> tem;
        for (int i = 0;i<temperatures.size();i++) {
            if (tem.empty()) tem.push(i);
            else {
                //如果当天温度比栈顶底，则仍无法确定栈顶元素什么时候遇到下一个温度更高的一天，入栈
                if (temperatures[i] <= temperatures[tem.top()]) {
                    tem.push(i);
                }
                else {
                    while (!tem.empty() && temperatures[i] > temperatures[tem.top()]) {
                        int k = i - tem.top();
                        res[tem.top()] = k;
                        tem.pop();
                    }
                    tem.push(i);
                }
            }
        }
        return res;
        
    }
};