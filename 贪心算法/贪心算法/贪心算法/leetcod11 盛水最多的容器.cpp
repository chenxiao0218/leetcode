#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。在坐标内画 n 条垂直线，
垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0) 。找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
说明：你不能倾斜容器。
*/

class Solution {
public:
    //思路正确，但时间复杂度为O(n^2),超出时间限制
    int maxArea(vector<int>& height) {
        int i = 0; int j = 0;
        int n = height.size();
        
        int max = 0;
        while (i < n - 1) {
            int area = 0;
            for (j = 1; j < n; j++) {
                if (height[j] >= height[i]) {
                    area = height[i] * (j - 1);
                    if (area > max) max = area;
                }
            }
            i++;
        }
        return max;
    }
    //使用两个指针，一个指向数组头部，一个指向数组尾部，把height较小的指针往中间移动
    int maxArea2(vector<int>& height) {
        int i = 0;
        int j = height.size() - 1;
        int max = 0;
        while (i != j) {
            int area = min(height[i], height[j]) * (j - i);
            if (area > max) max = area;
            if (height[i] <= height[j]) i++;
            else j--;
        }
        return max;
    }
};