/*
����������
���������˳�򣬵�����ʽ���£�
Given a singly linked list L: L0��L1������Ln-1��Ln,
reorder it to: L0��Ln��L1��Ln-1��L2��Ln-2����
Ҫ�󣺲����ö���Ĵ洢�ռ䣬���ı�ڵ��ڵ�ֵ

���������
�������Ϊǰ�������Ժ�һ���������������Ȼ����������ϲ�
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
	//�뷨������һ�������ת��Ȼ���ٺϲ�ǰ������
	void reorderList(ListNode* head) {
		if (!head || !head->next || !head->next->next)
			return;
		ListNode *itr = head->next, *half = head;
		while (itr&&itr->next)          //�õ�������м�ڵ�λ��
		{
			itr = itr->next->next;
			half = half->next;
		}
		//�õ���һ�������
		ListNode *secondList = half->next;
		half->next = NULL;
		//���ò��뷨������һ�������ߵ�˳��
		itr = secondList->next;
		secondList->next = NULL;
		while (itr)
		{
			ListNode *tmp = itr->next;
			itr->next = secondList;
			secondList = itr;
			itr = tmp;
		}
		//��ǰ����������ϲ�
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