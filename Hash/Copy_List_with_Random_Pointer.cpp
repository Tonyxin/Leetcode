/*
����������
�����������ָ�룬�ֱ�ָ����һ���ڵ������ڵ㣬ʵ�ֶ���������

���������
����DFS+hash�ķ�ʽ��
hashʵ��ԭ��������������ڵ�֮���һһӳ�䣻
DFS��ʽʵ�ֶԸ����ڵ�ı�����
*/

/**
* Definition for singly-linked list with a random pointer.
* struct RandomListNode {
*     int label;
*     RandomListNode *next, *random;
*     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
* };
*/
class Solution {
public:
	//hash��ʵ��ԭ�ڵ㵽�½ڵ��һһӳ��
	unordered_map<RandomListNode*, RandomListNode*> hash;
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head)   return NULL;
		if (hash.find(head) == hash.end())		//���֮ǰû�з��ʹ��ýڵ㣬��newһ��
		{
			hash[head] = new RandomListNode(head->label);
			hash[head]->next = copyRandomList(head->next);
			hash[head]->random = copyRandomList(head->random);
		}
		//֮ǰ�з��ʣ���ֱ�ӷ���
		return hash[head];
	}
};