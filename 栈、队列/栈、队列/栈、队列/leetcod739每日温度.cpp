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
                //��������¶ȱ�ջ���ף������޷�ȷ��ջ��Ԫ��ʲôʱ��������һ���¶ȸ��ߵ�һ�죬��ջ
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