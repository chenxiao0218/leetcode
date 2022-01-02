#include<iostream>
#include<vector>
#include<stack>
#include<deque>

using namespace std;

typedef struct treenode {
    int val;
    treenode* left;
    int flag_left=0;
    treenode* right;
    int flag_right=0;
    treenode() : val(0), left(nullptr), right(nullptr) {}
    treenode(int x) : val(x), left(nullptr), right(nullptr) {}
    treenode(int x, treenode* left, treenode* right) : val(x), left(left), right(right) {}
}mytree;

mytree* pre = nullptr;
class xiansuo {
public:
	
	//将一颗二叉树构建为线索二叉树
	void Creattree(mytree* root) {
		if (!root) return;
		Creattree(root->left);
		if (!root->left) {
			root->left = pre;
			root->flag_left = 1;
		}
		if (pre && !pre->right) {
			pre->right = root;
			pre->flag_right = 1;
		}
		pre = root;
		Creattree(root->right);
	}

	mytree* FirstNode(mytree* root) {
		while (root->left != nullptr&&!root->flag_left) root = root->left;
		return root;
	}
	//查找后驱元素
	mytree* FindNext(mytree* root) {
		if (root->right == nullptr) {
			//cout << "last root" << endl;
			return nullptr;
		}
		if (root->flag_right) return root->right;
		else return FirstNode(root->right);
	}

	//遍历二叉线索树
	void Prttree(mytree* root) {
		if (!root) return;
		while (root->left != nullptr&&!root->flag_left) root = root->left;
		while (root) {
			cout << root->val << endl;
			root = FindNext(root);
		}
	}


};

//1 2 3 4 5 6 7 8 0 0 0 9 10
//8 4 2 5 1 9 6 10 3 7
