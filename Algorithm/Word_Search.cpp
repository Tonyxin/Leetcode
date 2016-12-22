/*
问题描述：
给一个字符二维矩阵M和一个字符串s，判断M中相邻的元素能否组成s，相邻是上下左右相邻
For example,
Given board =
[
['A','B','C','E'],
['S','F','C','S'],
['A','D','E','E']
]
word = "ABCCED", -> returns true,
word = "SEE", -> returns true,
word = "ABCB", -> returns false.

解决方法：
其实就是路径搜索，采用DPL（深度优先搜索算法），从某一点向外寻找，进行递归搜索
*/

class Solution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		int length = word.size();
		int m = board.size();
		if (!m)  return false;
		int n = board[0].size();
		if (!n)  return false;
		if (word == "")   return false;
		char c1 = word[0];
		vector<pair<int, int>> pos_c1;
		for (int i = 0; i<m; i++)
		{
			for (int j = 0; j<n; j++)
			{
				if (board[i][j] == c1)
					pos_c1.push_back(make_pair(i, j));
			}//for
		}//for
		for (const auto &pos : pos_c1)
		{
			if (recur(board, word, pos, 0))
				return true;
		}
		return false;
	}
private:
	bool recur(vector<vector<char>> &board, string &word, pair<int, int> pos, int index)
	{
		if (board[pos.first][pos.second] != word[index])
			return false;
		index++;
		if (index == word.length())    return true;
		//注意，同一层次，不应该修改矩阵的值，先将其保存
		auto tmp = board[pos.first][pos.second];
		//为了防止下一层次重复使用该点，将其置0
		board[pos.first][pos.second] = 0;
		if (pos.first>0)
		{
			if (recur(board, word, make_pair(pos.first - 1, pos.second), index))
				return true;
		}
		if (pos.first<board.size() - 1)
		{
			if (recur(board, word, make_pair(pos.first + 1, pos.second), index))
				return true;
		}
		if (pos.second>0)
		{
			if (recur(board, word, make_pair(pos.first, pos.second - 1), index))
				return true;
		}
		if (pos.second<board[0].size() - 1)
		{
			if (recur(board, word, make_pair(pos.first, pos.second + 1), index))
				return true;
		}
		//同一层次，不应该修改矩阵值，将其恢复
		board[pos.first][pos.second] = tmp;
		return false;
	}
};