/*
问题描述：
一个字符串由A、C、G、T组成，假设一个基因片段由10个连续字符组成，寻找所有出现1次以上的子串
For example,
Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
Return:
["AAAAACCCCC", "CCCCCAAAAA"].

解决方法：
1、A、C、G、T的后三位均不相同，因此采用后三位对字符进行标志‘
2、10个连续字符的后三位抽出来，组成一个int类型数字，最为关键字
3、构造hash表，map<int,int>，关键字->出现次数，出现次数>=1就满足条件
*/

class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string> ans;
		int size = s.size();
		if (size <= 10) return ans;
		unordered_map<int, int> hash;
		int key = 0, i = 0;
		for (; i<10; i++)
			key = key << 3 | s[i] & 7;
		for (; i <= size; i++)
		{
			if (hash.find(key) == hash.end())
				hash[key] = 0;
			else
				hash[key]++;
			if (hash[key] == 1)
				ans.push_back(s.substr(i - 10, 10));
			key = key << 3 & 0x3FFFFFFF | s[i] & 7;
		}
		return ans;
	}
};
