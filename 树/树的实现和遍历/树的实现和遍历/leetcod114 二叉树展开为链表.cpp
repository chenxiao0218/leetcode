#include<iostream>
#include<vector>
#include<stack>
#include<deque>

using namespace std;

/*����������ĸ���� root �����㽫��չ��Ϊһ��������
չ����ĵ�����Ӧ��ͬ��ʹ�� TreeNode ������ right ��ָ��ָ����������һ����㣬������ָ��ʼ��Ϊ null ��
չ����ĵ�����Ӧ��������� ������� ˳����ͬ��
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
    //���취���ȱ���һ��ѽڵ㶼���浽�����У�Ȼ����һ������ָ��
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

    //����2
    //�����������뵽�������ĵط�
//��ԭ�����������ӵ������������ұ߽ڵ�
//�����µ��������ĸ��ڵ㣬һֱ�ظ��ϱߵĹ��̣�ֱ���µ�������Ϊ null
    void flatten2(TreeNode* root) {
        if (!root) return;
        while (root) {
            //�ҵ���һ�����������ĸ��ڵ�
            if (!root->left) {
                root = root->right;
            }
            //�ҵ������������ҽڵ�
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