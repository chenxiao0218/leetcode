
#include<iostream>

using namespace std;

//循环队列的数组实现
#define Max 6
//rear指向最后一个元素的下一个位置，front指向第一个元素的位置
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

	//入队
	void InQueue(int x) {
		if (IsFull()) {
			cout << "the queue is full" << endl;
			//cout << "front=" << front << endl;
			//cout << "rear=" << rear << endl;
			return;
		}
		mylist[(rear++) % Max] = x;
	}
	//出队
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
	//获得队首元素
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

//队列的链表实现，由于链表空间可扩展，因此不需要循环
//链表尾指针指向rear 进行插入操作，头指针指向front，进行插入操作

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
	//获取头元素
	int GetHead() {
		if (Isempty()) {
			cout << "empty queue" << endl;
			return -1;
		}
		return front->next->val;
	}
	//入队
	void InQueue(int x) {
		member* temp = new member;
		temp->val = x;
		rear->next = temp;
		temp->next = nullptr;
		rear = temp;
		
	}
	//出队
	int OutQueue() {
		if (Isempty()) {
			cout << "empty queue" << endl;
			return -1;
		}
		int res = front->next->val;
		member* p = front->next;
		front->next = p->next;
		delete p;
		//如果删除后队列为空，需要将尾指针指向头节点
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
		cout << "当前头元素为" << endl;
		cout << res << endl;
		myqueue.OutQueue();
		myqueue.InQueue(i + 10);
	}
}
