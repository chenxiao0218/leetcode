#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

/*���� n ���Ǹ�������������ʾ��״ͼ�и������ӵĸ߶ȡ�ÿ�����ӱ˴����ڣ��ҿ��Ϊ 1 
���ڸ���״ͼ�У��ܹ����ճ����ľ��ε���������
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
                //���ڸ߶ȸ��ڵ�ǰջ���±��Ӧ�ĸ߶�ʱ�����±���ջ
                //stack -1  k =1-1 
                if (heights[i] >= heights[index.top()]) {
                    index.push(i);
                }
                else {
                    //����ջ������Ԫ�ص��ұ߽�k
                    int k = index.top();
                    while (index.top() != -1 && heights[i] < heights[index.top()]) {
                        int p = index.top();
                        index.pop();
                        //pop����ǰԪ�غ󣬲����ҵ���ǰԪ�ص���߽�
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

