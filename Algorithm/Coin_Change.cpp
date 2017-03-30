/*
问题描述：
给一个数组coins（零钱），求组成总数为amount，需要coins中元素最小个数

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)
Example 2:
coins = [2], amount = 3
return -1.

解决方法：
采用动态规划dp[i] = min(dp[i], dp[i - coins[j]] + 1)，组成i的最小个数可由组成i-coins[j]的最小个数+1得到
*/

class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		int n = coins.size();
		if (!n)  return -1;
		vector<int> dp(amount + 1, amount + 1);
		dp[0] = 0;
		for (auto &c : coins)
		{
			if (c <= amount)
				dp[c] = 1;
		}
		for (int i = 1; i <= amount; i++)
		{
			if (dp[i] == amount + 1)
			{
				for (int j = 0; j<coins.size(); j++)
				{
					if (coins[j] <= i)
						dp[i] = min(dp[i], dp[i - coins[j]] + 1);
				}//for
			}//if
		}//for
		if (dp[amount] == amount + 1)
			return -1;
		return dp[amount];
	}
};