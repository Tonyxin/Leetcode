/*
����������
��һ�������ʾ��Ʊ����ļ۸񣬶Թ�Ʊ�����������õ���������ֵ
Ҫ��
	1��Ҫ��֮ǰ�����뽫����Ĺ�Ʊ����ȥ��
	2����֮��Ҫ��Ϣһ�죻
Example:
	prices = [1, 2, 3, 0, 2]
	maxProfit = 3
	transactions = [buy, sell, cooldown, buy, sell]

���������
ʹ��״̬����ʾĳһ�������״̬
s1Ϊ��ʼ״̬��s1��(buy)��Ϊs2��s2��(sell)��Ϊs3��s3ͣ(colddown)һ���Ϊs1
s1(colddown)Ϊs1��s2(colddown)Ϊs2
Ӧ��ע��s1[0]=0,s2[0]=0-prices[0],s3[0]�����ڣ���ʾΪINT_MIN
*/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int size = prices.size();
		if (!size)   return 0;
		//��ʾ���졢��״̬���������
		vector<int> s1(size, 0);
		vector<int> s2(size, 0);
		vector<int> s3(size, 0);
		s1[0] = 0;
		s2[0] = -prices[0];
		s3[0] = INT_MIN;
		for (int i = 1; i<size; i++)
		{
			s1[i] = max(s1[i - 1], s3[i - 1]);			
			s2[i] = max(s1[i - 1] - prices[i], s2[i - 1]);
			s3[i] = s2[i - 1] + prices[i];
		}
		return max(s1[size - 1], max(s2[size - 1], s3[size - 1]));
	}
};