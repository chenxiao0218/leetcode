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

//给定一个二叉树，检查它是否是镜像对称的。


class Solution {
public:
   //递归
    bool dfs(TreeNode* left, TreeNode* right) {
        if (!left && !right) return true;
        if (!left || !right) return false;
        if (left->val != right->val) return false;
        return dfs(left->left, right->right) && dfs(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        return dfs(root->left, root->right);
    }

    //迭代
    bool isSymmetric2(TreeNode* root) {
        deque<TreeNode*>help;
        if (!root) return true;
        if (!root->left && !root->right) return true;
        if (!root->left || !root->right) return false;
        help.push_back(root->left);
        help.push_back(root->right);
        while (!help.empty()) {
            TreeNode* tleft = help.front();
            help.pop_front();
            TreeNode* tright = help.front();
            help.pop_front();
            if (tleft->val != tright->val)return false;

            if (!tleft->left && !tright->right);
            else if (!tleft->left || !tright->right) return false;
            else {
                help.push_back(tleft->left);
                help.push_back(tright->right);
            }

            if (!tleft->right && !tright->left);
            else if (!tleft->right || !tright->left) return false;
            else {
                help.push_back(tleft->right);
                help.push_back(tright->left);
            }
        }
        return true;
    }
};