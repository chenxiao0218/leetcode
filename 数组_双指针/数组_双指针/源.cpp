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

		//不借助数组使用归并排序(从上到下，仍然是O(n)级别的空间复杂度
		ListNode* mergeSort(ListNode* left, ListNode* right) {
			ListNode* res = new ListNode;
			ListNode* tail = res;
			//头插法
			while (left && right) {
				if (left->val <= right->val) {
					tail->next = left;
					left = left->next;
				}
				else {
					tail->next = right;
					right = right->next;
				}
				tail = tail->next;
			}
			if (left) tail->next = left;
			if (right) tail->next = right;
			return res->next;
		}
		ListNode* sortList2(ListNode* head, ListNode* tail) {
			if (!head) return nullptr;
			//递归到最后只剩下一个元素的情况，要将next指向null，这样合并两个链表的时候才有终止条件
			//这里判断只剩下一个元素的条件注意表示head->next==nullptr
			if (head->next==tail) {
				head->next = nullptr;
				return head;
			}
			//注意寻找中点的时候条件是fast!=tail，而不是nullptr
			//由于一开始传进来的tail也是nullptr，因此区间选择为左闭右开
			ListNode* slow = head, * fast = head;
			while (fast->next!=tail) {
				fast = fast->next;
				slow = slow->next;
				if (fast->next!=tail)fast = fast->next;
			}
			//此时slow指针必定指向中间元素（奇数个元素）或中间元素的下一位（偶数个元素），所以区间为左闭右开

			//该递归将一直堆到栈中，直到剩下一个元素时，开始排序，开始释放栈
			return mergeSort(sortList2(head, slow), sortList2(slow, tail));
			//套娃形式如下
//mergeSort(mergeSort(sortList2(head, slow), sortList2(slow, tail))，mergeSort(sortList2(head, slow), sortList2(slow, tail)))
		}
		ListNode* sortList2(ListNode* head) {
			return sortList2(head, nullptr);
		}

		//尝试归并排序，并且使用常数的空间复杂度，自底向上递归
		ListNode* sortList3(ListNode* head) {
			if (!head || !head->next) return head;
			int len = 0;
			//先求数组的长度
			ListNode* p = head;
			while (p) {
				p = p->next;
				len++;
			}
			//定义一个数组大小的控制量，一开始排序一个（本身），然后排序相邻两个数，再是四个，最后一组数可以小于这个数
			int range = 1;
			ListNode* res = new ListNode;
			res->next = head;
			for (range = 1; range <= len; range <<= 1) {
				//利用尾插法记录结果
				ListNode* tail = res;
				//记录当前指向的
				ListNode* cur = res->next;
				while (cur) {
					ListNode* head1 = cur;
					for (int i = 1; i < range && cur->next; i++) cur = cur->next;
					//将head2指向下一位，然后从cur处断开指针,注意这里head2会可能是nullptr，当cur为最后一位时
					ListNode* head2 = cur->next;
					cur->next = nullptr;
					cur = head2;
					for (int i = 1; cur && i < range && cur->next; i++) cur = cur->next;
					//设置head2的断点,想让temp默认等于null
					ListNode* temp = nullptr;

					if (cur) {
						temp = cur->next;
						cur->next = nullptr;

					}
					ListNode* merged = mergeSort(head1, head2);
					tail->next = merged;
					//将tail指向已经排完序的数组的最后一位
					while (tail->next) {
						tail = tail->next;
					}
					cur = temp;
				}
			}
			return res->next;
		}
		//leetcod4 寻找两个正序数组拼接后的中位数
		//思路1 用额外的数组空间，然后双指针插入排序，返回中间位即可，时间复杂度m+n 空间复杂度m+n
		//思路2 寻找中位数，假设两个数组一共有sum个数，那么中位数即第k(k=sum/2)小的那个数，通过二分法可快速求得
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2, int k) {
			//k为第几个数，而不是下标
			int index1 = 0, index2 = 0;
			int this1 = 0, this2 = 0;
			int m = nums1.size() - 1, n = nums2.size() - 1;
			//分别求两个数组的第k/2个元素，比较两者大小，较小的那个数组前k/2-1个元素必然不会是中位数，就可以丢掉
			while (true) {
				if (index1 > m) return nums2[index2 + k - 1];
				if (index2 > n)return nums1[index1 + k - 1];
				if (k == 1) return min(nums1[index1], nums2[index2]);

				this1 = min(index1 + k / 2 - 1, m);
				this2 = min(index2 + k / 2 - 1, n);
				if (nums1[this1] <= nums2[this2]) {
					k = k - this1 - 1+index1;
					index1 = this1 + 1;
					
				}
				else {
					k = k - this2 - 1+index2;
					index2 = this2 + 1;
					
				}
			}

		}
		double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
			int len = nums1.size() + nums2.size();
			//数组总长度为奇数的情况下找到第（len+1)/2小的元素就是中位数
			if (len % 2) return findMedianSortedArrays(nums1, nums2, (len + 1) / 2);
			//偶数情况下返回中间两个数的平均数
			double less1 = findMedianSortedArrays(nums1, nums2, len / 2);
			double less2 = findMedianSortedArrays(nums1, nums2, len / 2 + 1);
			return (less1 + less2) / 2;
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

