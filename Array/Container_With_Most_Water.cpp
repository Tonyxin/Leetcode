/*
����������
����һ��������a1 a2 a3 a4  ... an
��ȡ����ֵai��aj
�涨area(ij)=min(ai,aj)*|j-i|
Ѱ������area

���������
��Container With Most Water.txt�ļ�
*/

class Solution {
public:
	int maxArea(vector<int>& height) {
		if (height.size()<2)
			return 0;
		int maxarea = 0;
		int i = 0;
		int j = height.size() - 1;
		while (i<j)
		{
			int h = min(height[i], height[j]);
			int area = h*(j - i);
			if (area>maxarea)    maxarea = area;
			if (height[i] <= h) i++;
			else    j--;
		}
		return maxarea;
	}
};