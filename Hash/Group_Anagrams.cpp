/*
����������
��һЩstring����string��������ĸ��ͬ�����һ��
For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
Return:
[
["ate", "eat","tea"],
["nat","tan"],
["bat"]
]
���������
������������
��ÿ��string����ĸ���򣬽���string��vector<string>��ϣӳ��
*/

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> result;
		int n = strs.size();
		if (!n)  return result;
		map<string, vector<string>> map_s2vs;
		for (auto str : strs)
		{
			string src_str = str;
			sort(str.begin(), str.end());
			map_s2vs[str].push_back(src_str);
		}
		for (auto itr = map_s2vs.begin(); itr != map_s2vs.end(); itr++)
			result.push_back((*itr).second);
		return result;
	}
};
