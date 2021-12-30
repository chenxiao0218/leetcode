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
void test011() {
	xiansuo fun;
	mytree* t9 = new mytree(9);
	mytree* t10 = new mytree(10);
	mytree* t8 = new mytree(8);
	mytree* t4 = new mytree(4,t8,nullptr);
	mytree* t5 = new mytree(5);
	mytree* t7 = new mytree(7);
	mytree* t6 = new mytree(6,t9,t10);
	mytree* t2 = new mytree(2,t4,t5);
	mytree* t3 = new mytree(3,t6,t7);
	mytree* t1 = new mytree(1, t2, t3);


	fun.Creattree(t1);
	fun.Prttree(t1);
	
	//mytree* res = fun.FindNext(t1);
	//cout << "res.val="<<res->val << endl;
	//cout << t1->flag_right << endl;
	//cout << fun.FirstNode(t1)->val << endl;
	//cout << "res.left_flag=" << res->flag_left << endl;

}

int main() {
	test011();

	system("pause");
	return 0;
}