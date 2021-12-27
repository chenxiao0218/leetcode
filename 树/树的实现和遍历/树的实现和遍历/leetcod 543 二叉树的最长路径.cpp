#include<iostream>
#include<vector>
#include<stack>
#include<deque>
#include<math.h>

using namespace std;

typedef struct treenode {
    int val;
    treenode* left;
    treenode* right;
    treenode() : val(0), left(nullptr), right(nullptr) {}
    treenode(int x) : val(x), left(nullptr), right(nullptr) {}
    treenode(int x, treenode* left, treenode* right) : val(x), left(left), right(right) {}
}TreeNode;

//����һ�ö�����������Ҫ��������ֱ�����ȡ�һ�ö�������ֱ�������������������·�������е����ֵ��
//����·�����ܴ���Ҳ���ܲ���������㡣

class Solution {
public:
    vector<int> dfs(TreeNode* root) {
        vector<int> res;
       
        if (root->left && root->right) {
            vector<int> left = dfs(root->left);
            vector<int> right = dfs(root->right);
            int left_len = 1 + max(left[0], left[1]);
            int right_len = 1 + max(right[0], right[1]);
            res.push_back(left_len);
            res.push_back(right_len);
            int max_len = max(left[2], right[2]);
            if (right_len + left_len > max_len) res.push_back(right_len + left_len);
            else res.push_back(max_len);
            
        }
        else if (root->left) {
            vector<int> left = dfs(root->left);
            int left_len = 1 + max(left[0], left[1]);
            res.push_back(left_len);
            res.push_back(left[2] + 1);
            res.push_back(0);
        }
        else if (root->right) {
            vector<int> right = dfs(root->right);
            int right_len = 1 + max(right[0], right[1]);
            res.push_back(0);
            res.push_back(right_len);
            res.push_back(right[2] + 1);
        }
        else {
            res.push_back(0);
            res.push_back(0);
            res.push_back(0);
        }
        return res;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int len = 0;
        len = dfs(root)[2];
        return len;
    }
};