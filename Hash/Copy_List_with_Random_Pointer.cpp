/*
问题描述：
链表带有两个指针，分别指向下一个节点和随机节点，实现对链表的深拷贝

解决方法：
采用DFS+hash的方式；
hash实现原链表到新链表各个节点之间的一一映射；
DFS方式实现对各个节点的遍历；
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
	//hash表实现原节点到新节点的一一映射
	unordered_map<RandomListNode*, RandomListNode*> hash;
	RandomListNode *copyRandomList(RandomListNode *head) {
		if (!head)   return NULL;
		if (hash.find(head) == hash.end())		//如果之前没有访问果该节点，就new一个
		{
			hash[head] = new RandomListNode(head->label);
			hash[head]->next = copyRandomList(head->next);
			hash[head]->random = copyRandomList(head->random);
		}
		//之前有访问，就直接返回
		return hash[head];
	}
};