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

class xiansuo {
public:
	mytree* pre = nullptr;
	void Creattree(mytree* root) {
		Creattree(root, pre);
	}
	void Creattree(mytree* root, mytree* pre) {
		if (!root) return;
		Creattree(root->left, pre);
		if (!root->left) {
			root->left = pre;
			root->flag_left = 1;
		}
		if (pre && !pre->right) {
			pre->right = root;
			pre->flag_right = 1;
		}
		pre = root;
		Creattree(root->right, pre);
	}

	mytree* FirstNode(mytree* root) {
		while (root->left != nullptr) root = root->left;
		return root;
	}
	mytree* FindNext(mytree* root) {
		if (root->right == nullptr) {
			cout << "last root" << endl;
			return nullptr;
		}
		if (root->flag_right) return root->right;
		else return FirstNode(root->right);
	}
};


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
	cout << t8->right << endl;
	while (t8->right) {
		cout << t8->val << " ";
		t8 = t8->right;
	}
	/*mytree* res = FindNext(t1);
	cout << "res.val="<<res->val << endl;
	cout << "res.left_flag=" << res->flag_left << endl;*/

}

int main() {
	test011();

	system("pause");
	return 0;
}