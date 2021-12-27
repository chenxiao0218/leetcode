#include<iostream>
#include<vector>
#include<stack>
#include<deque>

using namespace std;

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
    TreeNode* dfs(vector<int>& preorder, int pre_s, int pre_e, vector<int>& inorder, int m_s, int m_e) {
        //ѭ����ֹ���������������ɣ�����Ϊ����ҿ�
        if (pre_s == pre_e) return nullptr;
        int root_val = preorder[pre_s];
        int index;
        //����Ϊ������ ����Ϊ�����  �������ĵ�һ��Ϊ��
        //�ҵ������и���λ�ã���������ֳ���������
        for (int i = m_s; i < m_e; i++) {
            if (inorder[i] == root_val) {
                index = i;
                break;
            }
        }
        //��ǰ���ڵ�
        TreeNode* root = new TreeNode(root_val);
        //��������Ԫ����
        int left_num = index - m_s;
        root->left = dfs(preorder, pre_s + 1, pre_s+1+left_num, inorder, m_s, index);
        root->right = dfs(preorder, pre_s + 1 + left_num, pre_e, inorder, index+1, m_e);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* res;
        res = dfs(preorder, 0, preorder.size(), inorder, 0, inorder.size());
        return res;
    }
};