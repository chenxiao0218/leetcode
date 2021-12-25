#include<iostream>
#include<vector>
#include<stack>

using namespace std;

typedef struct mytree {
	int val=0;
	struct mytree* lson=nullptr;
	struct mytree* rson = nullptr;
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

