/*
问题描述：
给一个已经排序好的单向链表，去除重复的节点
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

解决方法：
采用递归方式进行，寻找第一个节点p，使得p->last->val！=p->val;
如果p->val！=p->next->val，则将p加入链表，并且p->next=deleteDuplicates(p->next)递归；
如果p->val==p->next->val，则向后找到第一个节点q，使得q->last->val！=q->val，直接递归
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
		if (!head || !head->next) return head;				//head节点的特点是与其前一个节点的val不同	
		int val = head->val;		
		ListNode* p = head->next;							
		//如果head->val!=head->next->val，保存head，并对head->next向下递归
		if (p->val != val) {											
			head->next = deleteDuplicates(p);
			return head;
		}
		//如果head->val==head->next->val，找到下一个节点（其与前一个节点val不同，再次循环）
		else {			
			while (p && p->val == val) p = p->next;
			return deleteDuplicates(p);
		}
	}
};