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


//����˼·��ʵһ�������ǵݹ�
//��ǰ���ڵ�����=�������������max(L,R)+1
//��ǰ�ڵ���·��Ϊ���������ĸ������� L+R
//��һ��ȫ�ֱ���res���������ȣ��������res����и���
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
            res.push_back(0);
            res.push_back(max(left_len, left[2]));

        }
        else if (root->right) {
            vector<int> right = dfs(root->right);
            int right_len = 1 + max(right[0], right[1]);
            res.push_back(0);
            res.push_back(right_len);
            res.push_back(max(right_len, right[2]));
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


class Solution {
public:
    int res;
    int dfs(TreeNode* root) {
        if (!root) return 0;
        int L = dfs(root->left);
        int R = dfs(root->right);
        res = max(res, L + R);
        return max(L, R) + 1;

    }
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }
};