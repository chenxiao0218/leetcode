#include<iostream>
#include<vector>
#include<stack>
#include<deque>

using namespace std;

//给你一个二叉树，请你返回其按 层序遍历 得到的节点值。 （即逐层地，从左到右访问所有节点）。

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
            //该题的难点是如何判断到了下一层
            //通过每次循环前计算当前队列中的元素个数（即这一层的元素个数来做中断
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