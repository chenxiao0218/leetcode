#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<deque>
using namespace std;

class Solution239 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //这个队列按递减的顺序保留了元素下标，队头的下标代表当前最大的元素的下标
        deque<int> windows;
        vector<int> res;
        int n = nums.size();
        if (nums.empty()) return res;
        //先构造出一个窗口，题目限制了k<=n，所以直接构建一个k长度的窗口
        for (int i = 0; i < k; i++) {
            while (!windows.empty() && nums[i] >= nums[windows.back()]) {
                windows.pop_back();
            }
            windows.push_back(i);
        }
        //把第一个窗口的答案保留至res
        res.push_back(nums[windows.front()]);

        //然后开始向前移动窗口，直到窗口碰到头
        for (int i = k; i < n; i++) {
            //如果现在最大的元素的下标已经不在窗口内了就将其弹出
            if (windows.front() <= i - k) windows.pop_front();
            //while循环和上面一样，就是为了保证windows内的下标代表的元素是严格递减
            //从而保证sums[windows.front()]为窗口内的最大值
            while (!windows.empty() && nums[i] >= nums[windows.back()]) {
                windows.pop_back();
            }
            windows.push_back(i);
            res.push_back(nums[windows.front()]);
        }
        return res;
    }
};