#include<iostream>
#include<vector>
#include<stack>

using namespace std;

typedef struct treenode {
     int val;
     treenode *left;
     treenode *right;
     treenode() : val(0), left(nullptr), right(nullptr) {}
     treenode(int x) : val(x), left(nullptr), right(nullptr) {}
     treenode(int x, treenode *left, treenode *right) : val(x), left(left), right(right) {}
 }mytree;
//给定一个二叉树的根节点 root ，返回它的 中序 遍历。
class Solution {
public:
	//迭代算法
	vector<int> inorderTraversal(mytree* root) {
		vector<int> res;
		stack<mytree*> help;
		while (!help.empty() || root) {
			while (root)
			{
				help.push(root);
				root = root->left;
			}
			root = help.top();
			help.pop();
			res.push_back(root->val);
			if (root->right) root = root->right;
			//如果不做这个赋值操作，会一直循环下去，一直等于第一个遍历到的右节点
			else root = nullptr;
		}
		return res;
	}
	
	//递归算法
	void digui(mytree* root, vector<int>& res) {
		if (!root) return;
		digui(root->left,res);
		res.push_back(root->val);
		digui(root->right, res);
	}
	vector<int> inorderTraversal2(mytree* root) {
		vector<int> res;
		digui(root, res);
		return res;

	}
};

void test01() {
	mytree* t1 = new mytree;
	mytree* t2 = new mytree;
	mytree* t3 = new mytree;
	mytree* t4 = new mytree;
	mytree* t5 = new mytree;
	mytree* t6 = new mytree;
	mytree* t7 = new mytree;
	t1->val = 1;
	t2->val = 2;
	t3->val = 3;
	t4->val = 4;
	t5->val = 5;
	t6->val = 6;
	t7->val = 7;
	t1->left = t2;
	t1->right = t3;
	t2->left = t4;
	t2->right = t5;
	t3->left = t6;
	t3->right = t7;

}

int main() {
	test01();

	system("pause");
	return 0;
}