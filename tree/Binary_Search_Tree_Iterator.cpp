/*
����������
��С�����������������
Ҫ�󣺿ռ临�Ӷ�ΪO(h)��hΪ������ȣ�ʱ�临�Ӷ�ΪO(1)

���������
ʹ�ö�ջ����������ڵ㣬ÿ���һ�Σ����¶�ջ
*/

/**
* Definition for binary tree
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class BSTIterator {
public:
	BSTIterator(TreeNode *root) {
		while (root)
		{
			smallNode.push(root);
			root = root->left;            //��������ڵ㲻����ջ
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		//ջ���գ��ͱ�ʾ�У�ʱ�临�Ӷ�ΪO(1)
		return smallNode.empty() ? 0 : 1;
	}

	/** @return the next smallest number */
	int next() {
		//����ջ���ڵ㣬��Ϊ����ʱ�临�Ӷ�ΪO(1)
		auto node = smallNode.top();
		auto val = node->val;
		smallNode.pop();
		//���ջ���ڵ����ҽڵ㣬���ҽڵ���ջ�����������ҽڵ��������ջ
		while (node->right)
		{
			smallNode.push(node->right);
			node->right = node->right->left;
		}
		return val;
	}
	//ʹ�ö�ջ����������ڵ㣬ռ�ÿռ�ΪO(h),hΪ�������
	stack<TreeNode*> smallNode;
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/