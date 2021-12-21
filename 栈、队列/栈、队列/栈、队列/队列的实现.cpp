
#include<iostream>

using namespace std;

//ѭ�����е�����ʵ��
#define Max 6
//rearָ�����һ��Ԫ�ص���һ��λ�ã�frontָ���һ��Ԫ�ص�λ��
typedef struct ListQueue {
	int front;
	int rear;
	int mylist[Max];
	void InitQueue() {
		front = 0;
		rear = 0;
	}

	bool IsEmpty() {
		if (front == rear) return true;
		else return false;
	}

	bool IsFull() {
		if ((rear + 1) % Max == front) return true;
		else return false;
	}

	//���
	void InQueue(int x) {
		if (IsFull()) {
			cout << "the queue is full" << endl;
			//cout << "front=" << front << endl;
			//cout << "rear=" << rear << endl;
			return;
		}
		mylist[(rear++) % Max] = x;
	}
	//����
	int OutQueue() {
		int res;
		if (IsEmpty()) {
			cout << "empty queue" << endl;
			res = -1;
		}
		res = mylist[front];
		front = (front + 1) % Max;
		return res;	
	}
	//��ö���Ԫ��
	int GetHead() {
		int res;
		if (IsEmpty()) {
			cout << "empty queue" << endl;
			res = -1;
		}
		res = mylist[front%Max];
		return res;
	}
}VQ;

//���е�����ʵ�֣���������ռ����չ����˲���Ҫѭ��
//����βָ��ָ��rear ���в��������ͷָ��ָ��front�����в������

typedef struct thequeue {
	int val;
	struct thequeue* next;
}member;

class MyQueue {
public:
	member* front = new member;
	member* rear = front;

	void InitQueue() {
		front->next = nullptr;
		rear = front;
	}

	bool Isempty() {
		if (front->next == nullptr) return true;
		return false;
	}
	//��ȡͷԪ��
	int GetHead() {
		if (Isempty()) {
			cout << "empty queue" << endl;
			return -1;
		}
		return front->next->val;
	}
	//���
	void InQueue(int x) {
		member* temp = new member;
		temp->val = x;
		rear->next = temp;
		temp->next = nullptr;
		rear = temp;
		
	}
	//����
	int OutQueue() {
		if (Isempty()) {
			cout << "empty queue" << endl;
			return -1;
		}
		int res = front->next->val;
		member* p = front->next;
		front->next = p->next;
		delete p;
		//���ɾ�������Ϊ�գ���Ҫ��βָ��ָ��ͷ�ڵ�
		if (Isempty()) rear = front;
		return res;
	}

};

void test01() {
	MyQueue myqueue;
	myqueue.InitQueue();
	for (int i = 0; i < 7; i++) {
		myqueue.InQueue(i);
	}
	for (int i = 0; i < 10; i++) {
		int res = myqueue.GetHead();
		cout << "��ǰͷԪ��Ϊ" << endl;
		cout << res << endl;
		myqueue.OutQueue();
		myqueue.InQueue(i + 10);
	}
}
