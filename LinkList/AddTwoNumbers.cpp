/*
问题描述：
对两个单向链表对应节点值进行求和，结果为1个新链表
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

解决方法：
采用递归方式进行，保存进位值
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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		return add(l1, l2, 0);
	}
private:
	ListNode* add(ListNode *lhs, ListNode *rhs, int c);			
};

ListNode* Solution::add(ListNode *lhs, ListNode *rhs, int c)
{
	ListNode *tempNode = NULL;
	if (lhs == NULL&&rhs == NULL)				//如果相加的两个节点均为NULL，递归结束
	{
		if (c)
			tempNode = new ListNode(1);
	}
	else
	{
		int val_tmp = (lhs == NULL ? 0 : lhs->val) + (rhs == NULL ? 0 : rhs->val) + c;
		tempNode = new ListNode(val_tmp % 10);
		c = val_tmp / 10;
		//链表向后递推，添加进位项进行递归操作
		tempNode->next = add((lhs == NULL ? NULL : lhs->next), (rhs == NULL ? NULL : rhs->next), c);			
	}
	return tempNode;
}