/*
问题描述：
给定一组正整数a1 a2 a3 a4  ... an
任取两个值ai，aj
规定area(ij)=min(ai,aj)*|j-i|
寻找最大的area

解决方法：
见Container With Most Water.txt文件
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