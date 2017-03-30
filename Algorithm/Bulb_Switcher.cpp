/*
����������
��nյ�ƣ���ʼʱȫ��
��1�Σ����0յת����
��2�Σ����1յת����
��3�Σ����2յת����
...
��n�Σ����n-1յת����
��������ŵĵƸ���

Given n = 3.
At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off].
So you should return 1, because there is only one bulb is on.

���������
������1~n���������ж��ٸ�����
����6��������1��2��3��6��
����4��������1��2��4
ֻ�����Ӹ���Ϊ�����ĵ����ţ���ֻ����ȫƽ����������Ҫ��
1~n�У��ж��ٸ���ȫƽ���������ж��ٸ�������
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