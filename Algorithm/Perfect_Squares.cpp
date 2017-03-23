/*
����������
��һ������n���������n����ȫƽ��������С����f(n)

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

���������
���ö�̬�滮���õ�1��2��3��4��5������i������n�Ľ��f(i)
����f(i)��
	���i����ȫƽ��������f(i)=1��
	����f(i)=min(f(1)+f(i-1)��f(2)+f(i-2)��f(3)+f(i-3)������)
*/

class Solution {
public:
	int numSquares(int n) {
		if (n <= 0)    return 0;
		vector<int> dp{ 0 };
		int m = 1;
		while (m <= n)
		{
			bool mark = 0;
			for (int i = 1; i*i <= m; i++)
			{
				if (i*i == m)
				{
					dp.push_back(1);
					m++;
					mark = 1;
					break;
				}//if
			}//for
			if (mark)    continue;
			int tmp = m;
			for (int i = 1; i <= m / 2; i++)
			{
				if (dp[i] + dp[m - i]<tmp)
					tmp = dp[i] + dp[m - i];
			}//for
			dp.push_back(tmp);
			m++;
		}//while
		return dp[n];
	}
};