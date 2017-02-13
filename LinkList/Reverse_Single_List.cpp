/*
����������
����������ת��

���������
ʹ������ָ�룬ָ��ǰ����㡢���ڵ㡢��̽ڵ�
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
		//p1ָ��ǰ����㣬p2ָ�򱾽ڵ㣬p3ָ���̽ڵ�
		ListNode *p1, *p2, *p3;
		p1 = head;
		p2 = p1->next;
		while (p2)
		{
			p3 = p2->next;			//���ҵ���̽ڵ�
			p2->next = p1;			//�������ͺ�̽ڵ㷴ת
			p1 = p2;						//�ƶ�p1,p2
			p2 = p3;
		}
		head->next = NULL;
		head = p1;
		return head;
	}

};