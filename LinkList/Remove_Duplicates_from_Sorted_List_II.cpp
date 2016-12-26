/*
����������
��һ���Ѿ�����õĵ�������ȥ���ظ��Ľڵ�
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

���������
���õݹ鷽ʽ���У�Ѱ�ҵ�һ���ڵ�p��ʹ��p->last->val��=p->val;
���p->val��=p->next->val����p������������p->next=deleteDuplicates(p->next)�ݹ飻
���p->val==p->next->val��������ҵ���һ���ڵ�q��ʹ��q->last->val��=q->val��ֱ�ӵݹ�
*/


/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		if (!head || !head->next) return head;				//head�ڵ���ص�������ǰһ���ڵ��val��ͬ	
		int val = head->val;		
		ListNode* p = head->next;							
		//���head->val!=head->next->val������head������head->next���µݹ�
		if (p->val != val) {											
			head->next = deleteDuplicates(p);
			return head;
		}
		//���head->val==head->next->val���ҵ���һ���ڵ㣨����ǰһ���ڵ�val��ͬ���ٴ�ѭ����
		else {			
			while (p && p->val == val) p = p->next;
			return deleteDuplicates(p);
		}
	}
};