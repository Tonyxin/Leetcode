/*
问题描述：
由n盏灯，开始时全灭；
第1次，间隔0盏转化；
第2次，间隔1盏转化；
第3次，间隔2盏转化；
...
第n次，间隔n-1盏转化；
求最后亮着的灯个数

Given n = 3.
At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off].
So you should return 1, because there is only one bulb is on.

解决方法：
就是求1~n，各个数有多少个因子
比如6，因子由1、2、3、6；
比如4，因子有1、2、4
只有因子个数为奇数的灯亮着，而只有完全平方数才满足要求
1~n中，有多少个完全平方数，就有多少个灯亮着
*/

class Solution {
public:
	int bulbSwitch(int n) {
		int ans = 0;
		for (int i = 1; i*i <= n; i++)
			ans++;
		return ans;
	}
};