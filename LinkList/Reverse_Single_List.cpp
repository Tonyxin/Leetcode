/*
问题描述：
将单向链表转置

解决方法：
使用三个指针，指向前驱结点、本节点、后继节点
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
	ListNode* reverse(ListNode* head) {
		if (!head || !head->next)
			return head;
		//p1指向前驱结点，p2指向本节点，p3指向后继节点
		ListNode *p1, *p2, *p3;
		p1 = head;
		p2 = p1->next;
		while (p2)
		{
			p3 = p2->next;			//先找到后继节点
			p2->next = p1;			//将本结点和后继节点反转
			p1 = p2;						//移动p1,p2
			p2 = p3;
		}
		head->next = NULL;
		head = p1;
		return head;
	}

};