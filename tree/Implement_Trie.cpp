/*
����������
ʵ�ּ����ĵ��ʲ��ҡ����롢ǰ׺ƥ��

���������
ÿ���ڵ㺬��Trie* child[23]����Ӧָ��'abc....z'��������ڣ���child[x-'a']ָ����һ�ڵ㣬Ϊ��ΪNULL;
���ǵ��͵��Կռ任ʱ�䣻
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
			word_exist[word[0] - 'a'] = 1;      //��ʾ�е���
		//��Ա�����ĵݹ�
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
		//��Ա�����ĵݹ�
		return alphabet[word[0] - 'a']->search(word.substr(1, word.size() - 1));
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		if (!prefix.size())    return true;
		if (!alphabet[prefix[0] - 'a'])
			return false;
		//��Ա�����ĵݹ�
		return alphabet[prefix[0] - 'a']->startsWith(prefix.substr(1, prefix.size() - 1));
	}

	vector<bool> word_exist;    //��ʾ�Ƿ��е���
	vector<Trie*> alphabet;     //��ʾ26��Ӣ����ĸ��ÿ��Ӣ����ĸ��Ӧ������������������Ϊ��
};

/**
* Your Trie object will be instantiated and called as such:
* Trie obj = new Trie();
* obj.insert(word);
* bool param_2 = obj.search(word);
* bool param_3 = obj.startsWith(prefix);
*/