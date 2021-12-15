#include<iostream>
#include<vector>
#include<algorithm>

#include<list>


#include < unordered_map >

using namespace std;

typedef struct ListNode {
	int val;
	ListNode* next;
	//ListNode(int x) : val(x), next(NULL) {}

}ListNode;
	//leetcood 1
	class Solution {
	public:
		/*给定一个整数数组 nums 和一个整数目标值 target，
		请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。*/
		//思路1 暴力破解 时间复杂度O(N^2) 不做了 太简单了
		//思路2 先排序，然后用两个指针从头和尾分别进行遍历 但是空间复杂度为O(N)
		vector<int> twoSum(vector<int>& nums, int target) {
			vector<int>res;
			vector<int>help;
			for (int value : nums) {
				help.push_back(value);
			}
			sort(help.begin(), help.end());
			int i = 0, j = help.size() - 1;
			while (i <= j) {
				if (help[i] + help[j] == target) {
					for (int t = 0; t < nums.size(); t++) {
						if (nums[t] == help[i] || nums[t] == help[j]) {
							res.push_back(t);
						}
					}
					break;
				}
				else if (help[i] + help[j] < target) { i++; }
				else j--;
			}
			return res;
		}
		//思路3 哈希表，先不管，等学了再来看
		vector<int> twoSum2(vector<int>& nums, int target) {
			unordered_map<int, int> hashtable;
			for (int i = 0; i < nums.size(); ++i) {
				auto it = hashtable.find(target - nums[i]);
				if (it != hashtable.end()) {
					return { it->second, i };
				}
				hashtable[nums[i]] = i;
			}
			return {};
		}

		//leetcod 15

		/*给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，
		使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。*/
		//第一个元素按顺序遍历，第二个元素，第三个元素按照双指针来做
		vector<vector<int>> threeSum(vector<int>& nums) {
			vector<vector<int>> res;
			if (nums.size() < 3) return res;
			sort(nums.begin(), nums.end());
			int i = 0, j, k;
			while (i < nums.size() - 2 && nums[i] <= 0) {
				j = i + 1;
				k = nums.size() - 1;
				while (j < k) {
					if (nums[i] + nums[j] + nums[k] == 0) {
						res.push_back({ nums[i],nums[j++],nums[k--] });
						while (j < k && nums[k] == nums[k + 1]) k--;
						while (j < k && nums[j] == nums[j - 1]) j++;
					}
					else if (nums[i] + nums[j] + nums[k] < 0) j++;
					else k--;
				}
				i++;
				while (i < nums.size() - 2 && nums[i] == nums[i - 1]) {
					i++;
				}
			}
			return res;
		}
		//leetcod 75
		/*给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
		此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。*/

		//思路：利用快排法，easygame
		void sortColors(vector<int>& nums) {
			int value = 1;
			int less = -1;
			int more = nums.size();
			int i = 0;
			while (i < more) {
				if (nums[i] < value) swap(nums[i++], nums[++less]);
				else if (nums[i] > value) swap(nums[i++], nums[--more]);
				else i++;
			}
		}

		//leetcod 142环形链表
		//给定一个链表，返回链表入环的第一个节点

		ListNode* detectCycle(ListNode* head) {
			ListNode* slow = head, * fast = head;
			if (fast->next == nullptr) return nullptr;

			while (fast->next != nullptr && fast != nullptr) {
				fast = fast->next->next;
				slow = slow->next;
				if (fast == slow) break;
			}
			if (fast == nullptr || fast->next == nullptr) return nullptr;

			ListNode* meet = fast;
			ListNode* res = head;
			while (meet != res) {
				meet = meet->next;
				res = res->next;
			}
			return res;
		}

		//leetcod 234 回文链表
		//给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false
		//思路，算法要求时间复杂度0(n)空间复杂度O（1）
		//将后半部分的数组逆置，然后利用双指针的方式进行判断
		bool isPalindrome(ListNode* head) {
			//先求得链表的长度n
			ListNode* p = head;
			int n = 0;
			while (p->next) {
				p = p->next;
				n++;
			}
			cout << "n=" << n << endl;
			p = head;
			int i = 0;
			//奇数个元素时，中间元素不需要考虑，将中间元素视为前半部分，最后对比时用后半部分指针指向Nullptr作为循环
			//退出条件，即可跳过该元素的对比
			if (n % 2)n++;
			while (i++ < n / 2) p = p->next;
			cout << "p指针指向数组前半的最后一位=" << p->val << endl;
			ListNode* now = p->next;
			p->next = nullptr;
			while (now) {
				ListNode* temp = now->next;
				now->next = p->next;
				p->next = now;
				now = temp;
			}
			//以上完成了后半部分数组的逆置
			//接下里只需要通过两个指针分别从头和后半部分开始顺序遍历即可
			now = head->next;
			p = p->next;
			while (p) {
				//cout << "后半值=" << p->val << endl;
				//cout << "前半值=" << now->val << endl;
				if (p->val != now->val) {
					return false;
				}
				now = now->next;
				p = p->next;
			}
			return true;

		}

		//lettcod 283 移动0
		/*给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
		双指针，一个指针按顺序从头往后，另一个指针跳过所有为0的元素，然后第一个指针遇到0时swap即可*/
		void moveZeroes(vector<int>& nums) {
			int i = 0, j = 0;
			while (j < nums.size()) {
				while (j < nums.size() && !nums[j]) j++;
				//当0处在数组末尾时，如果不做以下判断，接下来的swap语句就会越界
				if (j >= nums.size()) break;
				swap(nums[i++], nums[j++]);
			}
		}

		/*leetcod 19给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
		尝试一趟扫描解决该问题
		思路：使用双指针，先让一个指针往前走n个节点，然后两个指针一起往前走，先走的指针到头了第二个指针就是要删除的pre*/
		ListNode* removeNthFromEnd(ListNode* head, int n) {
			//
			if (!head || !head->next) return nullptr;
			ListNode* fast = new ListNode;
			ListNode* slow = new ListNode;
			ListNode* res = new ListNode;
			res->next = head;
			fast->next = head;
			slow->next = head;
			//ListNode* fast = head, * slow = head;
			while (n--) fast = fast->next;
			//上面的循环fast最大走到最后一个元素，不会走到nullptr
			while (fast->next) {
				fast = fast->next;
				slow = slow->next;
			}
			//下面这步很关键，如果要删除的是首位元素，那么应该直接改变res->next指针
			if (slow->next == res->next) res->next = res->next->next;
			else slow->next = slow->next->next;
			return res->next;
			/*优化方法，将slow初始化为res，fast初始化为head，就不用做if判断
			if (!head||!head->next) return nullptr;
			ListNode *fast = new ListNode;
			ListNode *slow = new ListNode;
			ListNode *res = new ListNode;
			res->next = head;
			fast = head;
			slow = res;
			//ListNode* fast = head, * slow = head;
			while (n--) fast = fast->next;
			//上面的循环fast最大走到最后一个元素，不会走到nullptr
			while (fast) {
				fast = fast->next;
				slow = slow->next;
			}
		   slow->next = slow->next->next;
		   // cout<<"slow->next:value="<<slow->next->val<<endl;

			return res->next;*/
		}

		/*leetcod 148 升序排列链表，注意这个head是指向第一个元素的指针
		 O(n log n) 时间复杂度和常数级空间复杂度*/
		 //借助数组很简单，解答如下,但不满足常数级空间复杂度
		ListNode* sortList(ListNode* head) {
			vector<int> help;
			ListNode* res = head;
			while (head) {
				help.push_back(head->val);
				head = head->next;
			}
			sort(help.begin(), help.end());
			head = res;
			for (int i : help) {
				head->val = i;
				head = head->next;
			}
			return res;
		}
		//不借助数组使用归并排序
		void mergeSort(ListNode* left, ListNode* right) {
			ListNode* head1 = left;
			ListNode* fast1 = head1, * slow1 = head1;
			while (fast1 != right && fast1->next != right) {
				fast1 = fast1->next->next;
				slow1 = slow1->next;
			}
			ListNode* head2 = right;
			ListNode* fast2 = head2, * slow2 = head2;
			while (fast2 && fast2->next) {
				fast2 = fast2->next->next;
				slow2 = slow2->next;
			}


		}
		ListNode* sortList2(ListNode* head) {
			ListNode* fast = head, * slow = head;
			while (fast && fast->next) {
				fast = fast->next->next;
				slow = slow->next;
			}
			mergeSort(head, slow);
			return head;

		}

};


void test01() {
	Solution fun;
	vector<int> mylist = { 0,0,0,0};//-4 -1 -1 0 1 2
	vector<vector<int>> res = fun.threeSum(mylist);
	for (auto i : res) {
		for (auto j : i) {
			cout << j << " ";
		}
		cout << endl;
	}
}

void test02() {
	Solution fun;
	ListNode* head =new ListNode;
	ListNode* t1 = new ListNode;
	ListNode* t2 = new ListNode;
	ListNode* t3 = new ListNode;
	ListNode* t4 = new ListNode;
	t1->val = 1;
	t2->val = 2;
	t3->val = 2;
	t4->val = 1;
	head->next = t4;
	t1->next = t2;
	t2->next = nullptr;
	t3->next = t4;
	
	
}

int main() {
	test01();
		
	system("pause");
	return 0;
}

