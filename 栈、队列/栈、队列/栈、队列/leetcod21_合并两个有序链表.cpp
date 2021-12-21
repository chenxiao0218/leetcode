#include<iostream>
using namespace std;

/*将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

//传入的参数是指向首位元素的指针，而非头节点
//解法1 双指针 非常简单
class Solution21 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head1 = list1;
        ListNode* head2 = list2;
        ListNode* res = new ListNode;
        ListNode* tail = res;
        while (head1 && head2) {
            if (head1->val <= head2->val) {
                ListNode* temp = head1->next;
                head1->next = tail->next;
                tail->next = head1;
                tail = head1;
                head1 = temp;
            }
            else {
                ListNode* temp = head2->next;
                head2->next = tail->next;
                tail->next = head2;
                tail = head2;
                head2 = temp;
            }
        }
        while (head1) {
            ListNode* temp = head1->next;
            head1->next = tail->next;
            tail->next = head1;
            tail = head1;
            head1 = temp;
        }
        while (head2) {
            ListNode* temp = head2->next;
            head2->next = tail->next;
            tail->next = head2;
            tail = head2;
            head2 = temp;
        }
        return res->next;
    }
};

//解法2 递归法
//第一个元素排好序，然后让head->next指向再次调用函数的返回值
class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //递归终止条件，当一个链表为空时，只需要指向此时未空链表的头节点即可
        if (!list2) return list1;
        if (!list1) return list2;

        if (list1->val <= list2->val) { list1->next = mergeTwoLists(list1->next, list2); return list1; }
        else { list2->next = mergeTwoLists(list1, list2->next); return list2; }
        

    }
};