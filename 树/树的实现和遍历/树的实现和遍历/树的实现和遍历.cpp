#include<iostream>
#include<vector>
#include<stack>

using namespace std;

typedef struct mytree {
	int val=0;
	struct mytree* lson=nullptr;
	struct mytree* rson = nullptr;
}mytree;

//����ݹ����
void lprtree(mytree* p) {
	if (!p) return;
	lprtree(p->lson);
	cout << p->val << endl;
	lprtree(p->rson);
}
//����ǵݹ����
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
//����ݹ����
void prtree(mytree* p) {
	if (!p) return;
	cout << p->val << endl;
	prtree(p->lson);
	prtree(p->rson);
}
//����ǵݹ����
void pprtree(mytree* p) {
	stack<mytree*> help;
	help.push(nullptr);
	while (p ||!help.empty()) {
		cout << p->val << endl;
		//������ջ˳����ˣ��������˳��ת�󣬿��Եõ���������ķǵݹ��㷨
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
//����ݹ����
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
	cout << "����ݹ����" << endl;
	rprtree(t1);
	cout << "�ǵݹ����" << endl;
	pprtree(t1);
	//cout << "����ݹ����" << endl;
	//rprtree(t1);
}

int main() {
	test01();

	system("pause");
	return 0;
}