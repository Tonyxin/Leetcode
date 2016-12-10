/*
����������
ʵ��pow(x, n)��Ҫ��ʱ�临�Ӷȵ�

���������
��ָ��nչ����
n=a0*2^0+a1*2^1+a2*2^2+a3*2^3+a4*2^4+a5*2^5+...
ai=0��1
����2^m=(2^m-1)^2;
���Կɶ�n����������λ������1λ�룬�õ�ai��ֵ��
��ai==1��ans=ans*x;
ÿ��ѭ��,x=x^2
*/

class Solution {
public:
	double myPow(double x, int n) {
		if (x == 0 && n <= 0)		//�ȴ����������
			return 0;
		if (n<0)
			x = 1 / x;
		unsigned int k = abs(n);		//����Ӧ����unsigend����ֹn=-2^31
		double ans = 1;
		while (k)
		{
			if (k & 1)						//��ai==1ʱ���Ÿ��Ľ��
				ans = ans*x;
			x = x*x;
			k = k >> 1;
		}
		return ans;
	}
};