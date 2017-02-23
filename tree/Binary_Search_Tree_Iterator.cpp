/*
问题描述：
从小到大遍历二叉搜索树
要求：空间复杂度为O(h)，h为树的深度；时间复杂度为O(1)

解决方法：
使用堆栈保存树的左节点，每输出一次，更新堆栈
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
			root = root->left;            //将树的左节点不断入栈
		}
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		//栈不空，就表示有，时间复杂度为O(1)
		return smallNode.empty() ? 0 : 1;
	}

	/** @return the next smallest number */
	int next() {
		//返回栈顶节点，即为所求，时间复杂度为O(1)
		auto node = smallNode.top();
		auto val = node->val;
		smallNode.pop();
		//如果栈顶节点有右节点，将右节点入栈，并持续将右节点的左孩子入栈
		while (node->right)
		{
			smallNode.push(node->right);
			node->right = node->right->left;
		}
		return val;
	}
	//使用堆栈保存树的左节点，占用空间为O(h),h为树的深度
	stack<TreeNode*> smallNode;
};

/**
* Your BSTIterator will be called like this:
* BSTIterator i = BSTIterator(root);
* while (i.hasNext()) cout << i.next();
*/