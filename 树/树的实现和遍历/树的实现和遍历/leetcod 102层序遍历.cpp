#include<iostream>
#include<vector>
#include<stack>
#include<deque>

using namespace std;

//����һ�������������㷵���䰴 ������� �õ��Ľڵ�ֵ�� �������أ������ҷ������нڵ㣩��

typedef struct treenode {
    int val;
    treenode* left;
    treenode* right;
    treenode() : val(0), left(nullptr), right(nullptr) {}
    treenode(int x) : val(x), left(nullptr), right(nullptr) {}
    treenode(int x, treenode* left, treenode* right) : val(x), left(left), right(right) {}
}TreeNode;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        
        deque<TreeNode*> help;
        if (!root) return res;
        help.push_back(root);
        while (!help.empty())
        {
            int n = help.size();
            vector<int> temp;
            //������ѵ�������жϵ�����һ��
            //ͨ��ÿ��ѭ��ǰ���㵱ǰ�����е�Ԫ�ظ���������һ���Ԫ�ظ��������ж�
            for (size_t i = 0; i < n; i++)
            {
                TreeNode* tt = help.back();
                help.pop_back();
                if (tt->left) help.push_front(tt->left);
                if (tt->right) help.push_front(tt->right);
                temp.push_back(tt->val);
            }
            res.push_back(temp);
            temp.clear();

        }
        return res;
    }
};