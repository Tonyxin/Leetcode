/*
问题描述：
将链表调整顺序，调整方式如下：
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
要求：不适用额外的存储空间，不改变节点内的值

解决方法：
将链表分为前后链表，对后一半链表逆序操作，然后将两个链表合并
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
	//想法：将后一半的链表翻转，然后再合并前后链表
	void reorderList(ListNode* head) {
		if (!head || !head->next || !head->next->next)
			return;
		ListNode *itr = head->next, *half = head;
		while (itr&&itr->next)          //得到链表的中间节点位置
		{
			itr = itr->next->next;
			half = half->next;
		}
		//得到后一半的链表
		ListNode *secondList = half->next;
		half->next = NULL;
		//采用插入法，将后一半的链表颠倒顺序
		itr = secondList->next;
		secondList->next = NULL;
		while (itr)
		{
			ListNode *tmp = itr->next;
			itr->next = secondList;
			secondList = itr;
			itr = tmp;
		}
		//将前后两个链表合并
		itr = head;
		while (secondList)
		{
			ListNode *tmp1 = itr->next, *tmp2 = secondList->next;
			itr->next = secondList;
			secondList->next = tmp1;
			itr = tmp1;
			secondList = tmp2;
		}
	}
};