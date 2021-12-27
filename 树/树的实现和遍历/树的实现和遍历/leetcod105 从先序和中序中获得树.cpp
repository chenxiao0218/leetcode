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
        //循环终止条件，先序遍历完成，集合为左闭右开
        if (pre_s == pre_e) return nullptr;
        int root_val = preorder[pre_s];
        int index;
        //先序为根左右 中序为左根右  因此先序的第一个为根
        //找到中序中根的位置，即将中序分成左右子树
        for (int i = m_s; i < m_e; i++) {
            if (inorder[i] == root_val) {
                index = i;
                break;
            }
        }
        //当前根节点
        TreeNode* root = new TreeNode(root_val);
        //左子树的元素量
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