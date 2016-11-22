/*
����������
���������������Ӧ�ڵ�ֵ������ͣ����Ϊ1��������
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

���������
���õݹ鷽ʽ���У������λֵ
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
	if (lhs == NULL&&rhs == NULL)				//�����ӵ������ڵ��ΪNULL���ݹ����
	{
		if (c)
			tempNode = new ListNode(1);
	}
	else
	{
		int val_tmp = (lhs == NULL ? 0 : lhs->val) + (rhs == NULL ? 0 : rhs->val) + c;
		tempNode = new ListNode(val_tmp % 10);
		c = val_tmp / 10;
		//���������ƣ���ӽ�λ����еݹ����
		tempNode->next = add((lhs == NULL ? NULL : lhs->next), (rhs == NULL ? NULL : rhs->next), c);			
	}
	return tempNode;
}