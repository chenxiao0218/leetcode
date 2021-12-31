#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

/*���� n ���Ǹ����� a1��a2��...��an��ÿ�������������е�һ���� (i, ai) ���������ڻ� n ����ֱ�ߣ�
��ֱ�� i �������˵�ֱ�Ϊ (i, ai) �� (i, 0) ���ҳ����е������ߣ�ʹ�������� x �Ṳͬ���ɵ�����������������ˮ��
˵�����㲻����б������
*/

class Solution {
public:
    //˼·��ȷ����ʱ�临�Ӷ�ΪO(n^2),����ʱ������
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
    //ʹ������ָ�룬һ��ָ������ͷ����һ��ָ������β������height��С��ָ�����м��ƶ�
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