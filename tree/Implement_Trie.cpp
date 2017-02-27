/*
问题描述：
实现键树的单词查找、插入、前缀匹配

解决方法：
每个节点含有Trie* child[23]，对应指向'abc....z'，如果存在，则child[x-'a']指向下一节点，为则为NULL;
就是典型的以空间换时间；
*/


class Trie {
public:
	/** Initialize your data structure here. */
	Trie() {
		for (int i = 0; i<26; i++)
		{
			alphabet.push_back(NULL);
			word_exist.push_back(0);
		}
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		if (!word.size())
			return;
		if (!alphabet[word[0] - 'a'])
			alphabet[word[0] - 'a'] = new Trie();

		if (word.size() == 1)
			word_exist[word[0] - 'a'] = 1;      //表示有单词
		//成员函数的递归
		alphabet[word[0] - 'a']->insert(word.substr(1, word.size() - 1));
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		if (!word.size())    return true;
		if (!alphabet[word[0] - 'a'])
			return false;

		if (word.size() == 1 && word_exist[word[0] - 'a'] == 1)
			return true;
		if (word.size() == 1 && word_exist[word[0] - 'a'] == 0)
			return false;
		//成员函数的递归
		return alphabet[word[0] - 'a']->search(word.substr(1, word.size() - 1));
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		if (!prefix.size())    return true;
		if (!alphabet[prefix[0] - 'a'])
			return false;
		//成员函数的递归
		return alphabet[prefix[0] - 'a']->startsWith(prefix.substr(1, prefix.size() - 1));
	}

	vector<bool> word_exist;    //表示是否有单词
	vector<Trie*> alphabet;     //表示26个英文字母，每个英文字母对应子树，存在则子树不为空
};

/**
* Your Trie object will be instantiated and called as such:
* Trie obj = new Trie();
* obj.insert(word);
* bool param_2 = obj.search(word);
* bool param_3 = obj.startsWith(prefix);
*/