/*����һ���Ǹ��������� nums �������λ������� ��һ���±� 
�����е�ÿ��Ԫ�ش������ڸ�λ�ÿ�����Ծ����󳤶ȡ�
�ж����Ƿ��ܹ��������һ���±ꡣ*/

/*ʾ�� 1��
���룺nums = [2,3,1,1,4]
�����true
���ͣ��������� 1 �������±� 0 �����±� 1, Ȼ���ٴ��±� 1 �� 3 ���������һ���±ꡣ
*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//�ⷨһ:�Ӻ���ǰ,�õݹ�İ취�ж��ܷ���������i��
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

//�ⷨ��:��ǰ����
//��������Ϊ 1 4 2 5 2 1 1 1
//������4ʱ��4����Ծ����Զ�����1�ߣ�����ѡ��Ϊ4��
//������2ʱ��2����Ծ����Զ�����4-1�ף�������ȻΪ4
//������5ʱ��5����Ծ����Զ�����4-2Զ������ѡ��Ϊ5����ʱ index+nums[index]>=nums.size()������true
//���������������ʱ�� index+nums[index]<nums.size()������false


class Solution2 {
public:
    bool canJump(vector<int>& nums) {
        //��ǰ������±�
        int index = 0;

        while (index < nums.size()) {
            if (index + nums[index] >= nums.size() - 1) return true;

            //������ǰ����λ�ã������ж���û����һ�����������
            int old_index = index;
            for (int i = old_index; i <= old_index + nums[old_index]; i++) {
                //�����ǰ�ڵ������ĸ�Զ�����»���λ��
                if (i + nums[i] > index + nums[index]) index = i;

            }
            if (index == old_index)  return false;

        }
        return true;
    }
};