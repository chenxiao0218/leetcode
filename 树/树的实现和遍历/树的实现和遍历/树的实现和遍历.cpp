#include<iostream>
#include<vector>
#include<stack>

using namespace std;

typedef struct treenode {
	int val;
	treenode* lson;
	treenode* rson;

	treenode() : val(0), lson(nullptr), rson(nullptr) {}
	treenode(int x) : val(x), lson(nullptr), rson(nullptr) {}
	treenode(int x, treenode* left, treenode* right) : val(x), lson(left), rson(right) {}
}mytree;

//中序递归遍历
void lprtree(mytree* p) {
	if (!p) return;
	lprtree(p->lson);
	cout << p->val << endl;
	lprtree(p->rson);
}
//中序非递归遍历
void llrtree(mytree* p) {
	stack<mytree*>help;
	while (p || !help.empty()) {
		while (p) {
			help.push(p);
			p = p->lson;
		}
		if (!help.empty()) {
			cout << help.top()->val << endl;
			p = help.top()->rson;
			help.pop();
			
		}
	}
}
//先序递归遍历
void prtree(mytree* p) {
	if (!p) return;
	cout << p->val << endl;
	prtree(p->lson);
	prtree(p->rson);
}
//先序非递归遍历
void pprtree(mytree* p) {
	stack<mytree*> help;
	help.push(nullptr);
	while (p ||!help.empty()) {
		cout << p->val << endl;
		//这里入栈顺序错了，但以这个顺序翻转后，可以得到后序遍历的非递归算法
		if (p->lson)help.push(p->lson);
		if(p->rson) help.push(p->rson);
		
		p = help.top();
		help.pop();
	}
}
void pprtree2(mytree* p) {
	stack<mytree*>help;
	while (p || !help.empty()) {
		while (p) {
			cout << p->val << endl;
			help.push(p);
			p = p->lson;
		}
		if(!help.empty()){
			auto top = help.top();
			p = top->rson;
			help.pop();
		}
	}
}
//后序递归遍历
void rprtree(mytree* p) {
	if (!p) return;
	rprtree(p->lson);
	rprtree(p->rson);
	cout << p->val << endl;
}

//后续非递归遍历   先序 根左右   后序  左右根
void afterprt(mytree* p) {
	stack<mytree*> res;
	stack<mytree*> help;
	while (p || !help.empty()) {
		stack<mytree*> res;
		stack<mytree*> help;
		help.push(nullptr);
		while (p || !help.empty()) {
			res.push(p);
			if (p->lson)help.push(p->lson);
			if (p->rson) help.push(p->rson);
			p = help.top();
			help.pop();
		}
		while (!res.empty()) {
			cout << res.top()->val << " ";
			res.pop();
		}
		cout << endl;
		
	}
}


void afterprt2(mytree* p) {
	stack<mytree*>help;
	stack<mytree*> res;
	while (p || !help.empty()) {
		while (p) {
			res.push(p);
			help.push(p);
			p = p->rson;
		}
		if (!help.empty()) {
			auto top = help.top();
			p = top->lson;
			help.pop();
		}
	}
	while (!res.empty()) {
		cout << res.top()->val << " ";
		res.pop();
	}
	cout << endl;
}
void test011() {

	mytree* t9 = new mytree(9);
	mytree* t10 = new mytree(10);
	mytree* t8 = new mytree(8);
	mytree* t4 = new mytree(4, t8, nullptr);
	mytree* t5 = new mytree(5);
	mytree* t7 = new mytree(7);
	mytree* t6 = new mytree(6, t9, t10);
	mytree* t2 = new mytree(2, t4, t5);
	mytree* t3 = new mytree(3, t6, t7);
	mytree* t1 = new mytree(1, t2, t3);


	afterprt2(t1);
	afterprt(t1);

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