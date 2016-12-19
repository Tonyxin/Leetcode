/*
问题描述：
实现sqrt(x)

解决方法：
采用牛顿方法：
a(n+1)=a(n)+x/a(n);
随着n的增加，会收敛到sqrt(x)
*/

class Solution {
public:
	int mySqrt(int x) {
		double ans = x;              //初始值
		double delta = 0.0001;         //精确度
		while (fabs(pow(ans, 2) - x) > delta) {
			ans = (ans + x / ans) / 2;  //递归，最终的结果会收敛到sqrt(x)
		}
		return ans;
	}
};