/*
����������
����һ��������������s��һ������t������s�е���t��Ԫ�ط�Χ
For example,
Given [5, 7, 7, 8, 8, 10] and target value 8,
return [3, 4].

���������
���ö��������㷨��binary search������ΧΪi��j
Ѱ����߽�λ�ã�
mid=(i+j)/2;							//Ѱ����߽磬Ӧ�þ��������ȷ��������Χ
s[mid]>t��j=--mid;
s[mid]<t��i=++mid;
s[mid]=t��j=mid;
Ѱ���ұ߽�λ�ã�
mid=(i+j+1)/2;						//Ѱ���ұ߽磬Ӧ�þ������ұ�ȷ��������Χ
s[mid]>t��j=--mid;
s[mid]<t��i=++mid;
s[mid]=t��i=mid;
*/

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> result{ -1, -1 };
		if (nums.empty())
			return result;
		int begin = 0, end = nums.size() - 1;
		while (begin<end)
		{
			int mid = (begin + end) / 2;
			if (nums[mid]>target)    end = --mid;
			else if (nums[mid]<target)    begin = ++mid;
			else    end = mid;
		}
		if (nums[begin] == target)
			result[0] = begin;
		else
			return{ -1, -1 };
		begin = 0, end = nums.size() - 1;
		while (begin<end)
		{
			int mid = (begin + end + 1) / 2;
			if (nums[mid]>target)    end = --mid;
			else if (nums[mid]<target)    begin = ++mid;
			else    begin = mid;
		}
		result[1] = begin;
		return result;
	}
};