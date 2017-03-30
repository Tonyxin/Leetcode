/*
����������
��һ������coins����Ǯ�������������Ϊamount����Ҫcoins��Ԫ����С����

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)
Example 2:
coins = [2], amount = 3
return -1.

���������
���ö�̬�滮dp[i] = min(dp[i], dp[i - coins[j]] + 1)�����i����С�����������i-coins[j]����С����+1�õ�
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