#include<iostream>
#include<vector>
#include<stack>
#include<deque>

using namespace std;

/*给你二叉树的根结点 root ，请你将它展开为一个单链表：
展开后的单链表应该同样使用 TreeNode ，其中 right 子指针指向链表中下一个结点，而左子指针始终为 null 。
展开后的单链表应该与二叉树 先序遍历 顺序相同。
*/

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
    //笨办法，先遍历一遍把节点都保存到队列中，然后再一个个改指针
    void flatten(TreeNode* root) {
        stack<TreeNode*>help;
        deque<TreeNode*>res;
        TreeNode* p = root;
        if (!p) return;
        help.push(nullptr);

        while (p || !help.empty()) {         
            res.push_front(p);
            if (p->left) help.push(p->left);
            if (p->right) help.push(p->right);
            p = help.top();
            help.pop();
        }

        root->left = nullptr;
        root->right = res.back();
        res.pop_back();
        while(!res.empty()){
            TreeNode* top = res.back();
            res.pop_back();
            top->left = nullptr;
            if (!res.empty()) top->right = res.back();
            else top->right = nullptr;
        }
    }

    //方法2
    //将左子树插入到右子树的地方
//将原来的右子树接到左子树的最右边节点
//考虑新的右子树的根节点，一直重复上边的过程，直到新的右子树为 null
    void flatten2(TreeNode* root) {
        if (!root) return;
        while (root) {
            //找到第一个有左子树的根节点
            if (!root->left) {
                root = root->right;
            }
            //找到左子树的最右节点
            else {
                TreeNode* pre = root->left;
                while (pre->right) pre = pre->right;
                //
                pre->right = root->right;
                root->left = nullptr;
                root = root->right;
            }
        }
    }
};