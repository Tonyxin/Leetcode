/*
问题描述：
给一个数组n，找到其中出现次数多于⌊n/3⌋的元素，元素不一定存在

解决方法：
//想法：
//1、一个序列中之多存在两个值a,b，出现的次数多于⌊ n/3
//2、假设已经找到一个ele_1满足⌊ n/3 ⌋，则寻找下一个ele_2则退化为寻找 ⌊ n/2 ⌋问题；
//3、假设已经找到等价于ele_1对于ele_2透明，即，对于nums[i]==ele_1,count_2不减
//4、ele_1与ele_2为对偶关系
//5、由于可能找到的仅是最后出现，但又不满足条件的值，因此需要从后到前再找一遍，验证结果
//6、|count_2-count_1|<=n/3-1(由于count_1>n/3，且count_2>n/3)
*/

class Solution {
public:
	//想法：
	//1、一个序列中之多存在两个值a,b，出现的次数多于⌊ n/3 
	//2、假设已经找到一个ele_1满足⌊ n/3 ⌋，则寻找下一个ele_2则退化为寻找 ⌊ n/2 ⌋问题；
	//3、假设已经找到等价于ele_1对于ele_2透明，即，对于nums[i]==ele_1,count_2不减
	//4、ele_1与ele_2为对偶关系
	//5、由于可能找到的仅是最后出现，但又不满足条件的值，因此需要从后到前再找一遍，验证结果
	//6、|count_2-count_1|<=n/3-1(由于count_1>n/3，且count_2>n/3)
	vector<int> majorityElement(vector<int>& nums) {
		vector<int> ans;
		int size = nums.size();
		if (!size)   return ans;
		int count_1 = 0, count_2 = 0;
		int ele_1 = nums[0], ele_2 = 0;
		for (int i = 0; i<size; i++)
		{
			if (nums[i] == ele_1)
				count_1++;
			else if (count_2 == 0)
			{
				ele_2 = nums[i];
				count_2++;
			}
			else if (nums[i] == ele_2)
				count_2++;
			else
			{
				count_1--;
				count_2--;
			}
			if (count_1 == 0 && i != size - 1 && nums[i + 1] != ele_2)
				ele_1 = nums[i + 1];
		}

		int count_3 = 0, count_4 = 0;
		int ele_3 = nums[size - 1], ele_4 = 0;
		for (int i = size - 1; i >= 0; i--)
		{
			if (nums[i] == ele_3)
				count_3++;
			else if (count_4 == 0)
			{
				ele_4 = nums[i];
				count_4++;
			}
			else if (nums[i] == ele_4)
				count_4++;
			else
			{
				count_3--;
				count_4--;
			}
			if (count_3 == 0 && i != 0 && nums[i - 1] != ele_4)
				ele_3 = nums[i - 1];
		}
		if (ele_1 != ele_3&&ele_1 != ele_4)
			count_1 = 0;
		if (ele_2 != ele_3&&ele_2 != ele_4)
			count_2 = 0;

		if (count_1>0 && count_2>0)
		{
			int max_dif = (size % 3 ? (size / 3 + 1) : (size / 3)) - 1;
			if (abs(count_1 - count_2)>max_dif)
			{
				if (count_1>count_2)
					ans.push_back(ele_1);
				else if (count_1<count_2)
					ans.push_back(ele_2);
				else
				{
					ans.push_back(ele_1);
					ans.push_back(ele_2);
				}
			}
			else
			{
				ans.push_back(ele_1);
				ans.push_back(ele_2);
			}
		}
		else
		{
			if (count_1>0)   ans.push_back(ele_1);
			if (count_2>0)   ans.push_back(ele_2);
		}
		return ans;
	}
};