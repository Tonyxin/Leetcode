/*
问题描述：
实现pow(x, n)，要求时间复杂度低

解决方法：
将指数n展开成
n=a0*2^0+a1*2^1+a2*2^2+a3*2^3+a4*2^4+a5*2^5+...
ai=0或1
由于2^m=(2^m-1)^2;
所以可对n进行向左移位操作和1位与，得到ai的值；
当ai==1，ans=ans*x;
每次循环,x=x^2
*/

class Solution {
public:
	double myPow(double x, int n) {
		if (x == 0 && n <= 0)		//先处理特殊情况
			return 0;
		if (n<0)
			x = 1 / x;
		unsigned int k = abs(n);		//这里应该是unsigend，防止n=-2^31
		double ans = 1;
		while (k)
		{
			if (k & 1)						//当ai==1时，才更改结果
				ans = ans*x;
			x = x*x;
			k = k >> 1;
		}
		return ans;
	}
};