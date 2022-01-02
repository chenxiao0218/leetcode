/*给定一个非负整数数组 nums ，你最初位于数组的 第一个下标 
数组中的每个元素代表你在该位置可以跳跃的最大长度。
判断你是否能够到达最后一个下标。*/

/*示例 1：
输入：nums = [2,3,1,1,4]
输出：true
解释：可以先跳 1 步，从下标 0 到达下标 1, 然后再从下标 1 跳 3 步到达最后一个下标。
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//解法一:从后往前,用递归的办法判断能否跳到最后第i个
class Solution {
public:
    bool dfs(vector<int>& nums, int i) {
        if (i == 0) return true;
        int index = i - 1;
        while (index >= 0) {
            if (nums[index] >= i - index) return dfs(nums, index);
            index--;
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        if (nums.size() <= 1) return true;
        else if (nums[0] < 1) return false;
        return dfs(nums, nums.size() - 1);
    }
};

//解法二:从前往后
//假如序列为 1 4 2 5 2 1 1 1
//遍历到4时，4能跳跃的最远距离比1高，基点选择为4；
//遍历到2时，2能跳跃的最远距离比4-1底，基点仍然为4
//遍历到5时，5能跳跃的最远距离比4-2远，基点选择为5，此时 index+nums[index]>=nums.size()，返回true
//若遍历到队列最后时， index+nums[index]<nums.size()，返回false


class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        //当前基点的下标
        int index = 0;

        while (index < nums.size()) {
            if (index + nums[index] >= nums.size() - 1) return true;

            //保留当前基点位置，用于判断有没有下一个基点可以用
            int old_index = index;
            for (int i = old_index; i <= old_index + nums[old_index]; i++) {
                //如果当前节点能跳的更远，更新基点位置
                if (i + nums[i] > index + nums[index]) index = i;

            }
            if (index == old_index)  return false;

        }
        return true;
    }
};