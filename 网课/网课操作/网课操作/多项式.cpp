#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

typedef struct List1 {
	int coel;
	int ex;
}list1;

//������ķ�ʽʵ�ֶ���ʽ�ӷ����˷�
class Solution1 {
public:
	

	//��������ʽ�Ĵ���
	void CreatTwoList(vector<list1>& L1, vector<list1>& L2) {
		int coel = 1;
		int ex = 0;
		cout << "�������һ������ʽ��ϵ�� ָ��,����ϵ��Ϊ0�˳�" << endl;
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
		cout << "������ڶ�������ʽ��ϵ�� ָ��,����ϵ��Ϊ0�˳�" << endl;
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


	//����ʽ���
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

	//�ж϶���ʽ���Ƿ��и�ָ�����Ԫ��,���ڷ����±꣬�����ڷ���-1
	int JudgeIfExit(vector<list1>& L, int x) {
		if (!L.size()) return -1;
		for (int i = 0; i < L.size(); i++) {
			if (L[i].ex == x) return i;
		}
		return -1;
	}

	//����ʽ���
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
//����ʽ���\������
void test01() {
	Solution1 fun;
	vector<list1> L1;
	vector<list1> L2;
	fun.CreatTwoList(L1,L2);
	sort(L1.begin(), L1.end(), cmpTwoList);
	sort(L2.begin(), L2.end(), cmpTwoList);
	vector<list1> res = fun.AddTwoList(L1, L2);
	cout << "��������ʽ�ĺ�����" << endl;
	for (auto i : res) {
		cout << i.coel << "x^" << i.ex << " ";
	}
	cout << endl;

	vector<list1>res2 = fun.MultipTwoList(L1, L2);
	sort(res.begin(), res.end());
	cout << "��������ʽ�Ļ�����" << endl;
	for (auto i : res2) {
		cout << i.coel << "x^" << i.ex << " ";
	}
	
}

//����ʽ�������

int main() {
	test01();

	system("pause");
	return 0;
}