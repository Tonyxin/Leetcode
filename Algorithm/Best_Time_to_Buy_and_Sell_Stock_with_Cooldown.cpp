/*
问题描述：
给一个数组表示股票当天的价格，对股票进行买卖，得到收益的最大值
要求：
	1、要买之前，必须将手里的股票卖出去；
	2、卖之后要休息一天；
Example:
	prices = [1, 2, 3, 0, 2]
	maxProfit = 3
	transactions = [buy, sell, cooldown, buy, sell]

解决方法：
使用状态机表示某一天的买卖状态
s1为初始状态，s1买(buy)后为s2，s2卖(sell)后为s3，s3停(colddown)一天后为s1
s1(colddown)为s1，s2(colddown)为s2
应当注意s1[0]=0,s2[0]=0-prices[0],s3[0]不存在，表示为INT_MIN
*/

class Solution {
public:
	int maxProfit(vector<int>& prices) {
		int size = prices.size();
		if (!size)   return 0;
		//表示各天、各状态的最大收益
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