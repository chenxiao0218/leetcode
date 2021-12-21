#include<iostream>
#include<stack>
#include<string>
#include<vector>
#include<deque>
using namespace std;

class Solution239 {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        //������а��ݼ���˳������Ԫ���±꣬��ͷ���±����ǰ����Ԫ�ص��±�
        deque<int> windows;
        vector<int> res;
        int n = nums.size();
        if (nums.empty()) return res;
        //�ȹ����һ�����ڣ���Ŀ������k<=n������ֱ�ӹ���һ��k���ȵĴ���
        for (int i = 0; i < k; i++) {
            while (!windows.empty() && nums[i] >= nums[windows.back()]) {
                windows.pop_back();
            }
            windows.push_back(i);
        }
        //�ѵ�һ�����ڵĴ𰸱�����res
        res.push_back(nums[windows.front()]);

        //Ȼ��ʼ��ǰ�ƶ����ڣ�ֱ����������ͷ
        for (int i = k; i < n; i++) {
            //�����������Ԫ�ص��±��Ѿ����ڴ������˾ͽ��䵯��
            if (windows.front() <= i - k) windows.pop_front();
            //whileѭ��������һ��������Ϊ�˱�֤windows�ڵ��±�����Ԫ�����ϸ�ݼ�
            //�Ӷ���֤sums[windows.front()]Ϊ�����ڵ����ֵ
            while (!windows.empty() && nums[i] >= nums[windows.back()]) {
                windows.pop_back();
            }
            windows.push_back(i);
            res.push_back(nums[windows.front()]);
        }
        return res;
    }
};