/*
����������
ʵ��sqrt(x)

���������
����ţ�ٷ�����
a(n+1)=a(n)+x/a(n);
����n�����ӣ���������sqrt(x)
*/

class Solution {
public:
	int mySqrt(int x) {
		double ans = x;              //��ʼֵ
		double delta = 0.0001;         //��ȷ��
		while (fabs(pow(ans, 2) - x) > delta) {
			ans = (ans + x / ans) / 2;  //�ݹ飬���յĽ����������sqrt(x)
		}
		return ans;
	}
};