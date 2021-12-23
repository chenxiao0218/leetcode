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
void llprtree(mytree* p) {
	stack<int> help;
	while (p) {

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
	do {
			
			cout << p->val << endl;
			if(p->rson)help.push(p->rson);
			if (p->lson)help.push(p->lson);
			p = help.top();
			help.pop();
	} while (!help.empty());
}
//右序递归遍历
void rprtree(mytree* p) {
	if (!p) return;
	rprtree(p->lson);
	rprtree(p->rson);
	cout << p->val << endl;
}


void test01() {
	mytree *t1 = new mytree;
	mytree *t2 = new mytree;
	mytree *t3 = new mytree;
	mytree *t4 = new mytree;
	mytree *t5 = new mytree;
	mytree *t6 = new mytree;
	mytree *t7 = new mytree;
	t1->val = 1;
	t2->val = 2;
	t3->val = 3;
	t4->val = 4;
	t5->val = 5;
	t6->val = 6;
	t7->val = 7;
	t1->lson = t2;
	t1->rson = t3;
	t2->lson = t4;
	t2->rson = t5;
	t3->lson = t6;
	t3->rson = t7;
	cout << "中序递归遍历" << endl;
	prtree(t1);
	cout << "非递归遍历" << endl;
	pprtree(t1);
	//cout << "右序递归遍历" << endl;
	//rprtree(t1);
}

int main() {
	test01();

	system("pause");
	return 0;
}