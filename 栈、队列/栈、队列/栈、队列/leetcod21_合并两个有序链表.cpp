#include<iostream>
using namespace std;

/*��������������ϲ�Ϊһ���µ� ���� �������ء���������ͨ��ƴ�Ӹ�����������������нڵ���ɵġ�*/
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

//����Ĳ�����ָ����λԪ�ص�ָ�룬����ͷ�ڵ�
//�ⷨ1 ˫ָ�� �ǳ���
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

//�ⷨ2 �ݹ鷨
//��һ��Ԫ���ź���Ȼ����head->nextָ���ٴε��ú����ķ���ֵ
class Solution2 {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        //�ݹ���ֹ��������һ������Ϊ��ʱ��ֻ��Ҫָ���ʱδ�������ͷ�ڵ㼴��
        if (!list2) return list1;
        if (!list1) return list2;

        if (list1->val <= list2->val) { list1->next = mergeTwoLists(list1->next, list2); return list1; }
        else { list2->next = mergeTwoLists(list1, list2->next); return list2; }
        

    }
};