#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct List1 {
	int coel;
	int ex;
}list1;

//用数组的方式实现多项式加法、乘法
class Solution1 {
public:
	

	//两个多项式的创建
	void CreatTwoList(vector<list1>& L1, vector<list1>& L2) {
		int coel = 1;
		int ex = 0;
		cout << "请输入第一个多项式的系数 指数,输入系数为0退出" << endl;
		cin >> coel;
		cin >> ex;
		while (coel) {
			list1 temp;
			temp.coel = coel;
			temp.ex = ex;
			L1.push_back(temp);
			cin >> coel;
			cin >> ex;
		}
		//system("cls");
		cout << "请输入第二个多项式的系数 指数,输入系数为0退出" << endl;
		cin >> coel;
		cin >> ex;
		while (coel) {
			list1 temp;
			temp.coel = coel;
			temp.ex = ex;
			L2.push_back(temp);
			cin >> coel;
			cin >> ex;
		}
	}


	//多项式求和
	vector<list1> AddTwoList(vector<list1>& L1, vector<list1>& L2) {
		vector<list1> res;
		int i = 0, j = 0;
		while (i < L1.size() && j < L2.size()) {
			list1 temp;
			if (L1[i].ex == L2[j].ex) {
				temp.ex = L1[i].ex;
				temp.coel = L1[i++].coel + L2[j++].coel;
			}
			else if (L1[i].ex < L2[j].ex) temp = L2[j++];
			else temp = L1[i++];
			res.push_back(temp);
		}
		while (i < L1.size())res.push_back(L1[i++]);
		while (j < L2.size())res.push_back(L2[j++]);
		return res;
	}

	//判断多项式内是否有该指数项的元素,存在返回下标，不存在返回-1
	int JudgeIfExit(vector<list1>& L, int x) {
		if (!L.size()) return -1;
		for (int i = 0; i < L.size(); i++) {
			if (L[i].ex == x) return i;
		}
		return -1;
	}

	//多项式求积
	vector<list1> MultipTwoList(vector<list1>& L1, vector<list1>& L2) {
		vector<list1> res;
		for (auto i : L1) {
			for (auto j : L2) {
				list1 temp;
				temp.coel = i.coel * j.coel;
				temp.ex = i.ex + j.ex;
				int flag = JudgeIfExit(res, temp.ex);
				if (flag == -1) res.push_back(temp);
				else res[flag].coel += temp.coel;
			}
		}
		return res;
	}

};

bool cmpTwoList(list1 L1, list1 L2) {
	return L1.ex > L2.ex;
}
//多项式求和\积测试
void test01() {
	Solution1 fun;
	vector<list1> L1;
	vector<list1> L2;
	fun.CreatTwoList(L1,L2);
	sort(L1.begin(), L1.end(), cmpTwoList);
	sort(L2.begin(), L2.end(), cmpTwoList);
	vector<list1> res = fun.AddTwoList(L1, L2);
	cout << "两个多项式的和如下" << endl;
	for (auto i : res) {
		cout << i.coel << "x^" << i.ex << " ";
	}
	cout << endl;

	vector<list1>res2 = fun.MultipTwoList(L1, L2);
	sort(res.begin(), res.end());
	cout << "两个多项式的积如下" << endl;
	for (auto i : res2) {
		cout << i.coel << "x^" << i.ex << " ";
	}
	
}

//多项式求积测试

int main() {
	test01();

	system("pause");
	return 0;
}