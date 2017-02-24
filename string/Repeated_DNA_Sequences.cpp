/*
����������
һ���ַ�����A��C��G��T��ɣ�����һ������Ƭ����10�������ַ���ɣ�Ѱ�����г���1�����ϵ��Ӵ�
For example,
Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
Return:
["AAAAACCCCC", "CCCCCAAAAA"].

���������
1��A��C��G��T�ĺ���λ������ͬ����˲��ú���λ���ַ����б�־��
2��10�������ַ��ĺ���λ����������һ��int�������֣���Ϊ�ؼ���
3������hash��map<int,int>���ؼ���->���ִ��������ִ���>=1����������
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
