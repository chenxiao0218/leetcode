#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

/*给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 
求在该柱状图中，能够勾勒出来的矩形的最大面积。
 */

//[2,1,0,2
// stack -1 2 3  n=4
class Solution84 {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        stack<int> index;
        index.push(-1);
        for (int i = 0; i < heights.size(); i++) {

            if (index.top() == -1) index.push(i);
            else {
                //对于高度高于当前栈顶下表对应的高度时，将下标入栈
                //stack -1  k =1-1 
                if (heights[i] >= heights[index.top()]) {
                    index.push(i);
                }
                else {
                    //保留栈内其他元素的右边界k
                    int k = index.top();
                    while (index.top() != -1 && heights[i] < heights[index.top()]) {
                        int p = index.top();
                        index.pop();
                        //pop掉当前元素后，才能找到当前元素的左边界
                        res = max(res, (k - index.top()) * heights[p]);
                    }
                    index.push(i);
                }
            }
            cout << res << endl;;
        }
        int n = heights.size();
        while (index.top() != -1) {
            int k = index.top();
            index.pop();
            cout << "index=" << index.top() << " val=" << heights[k] << endl;
            res = max(res, (n - 1 - index.top()) * heights[k]);
        }
        return res;
    }
};

