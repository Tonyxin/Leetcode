/*
问题描述：
给有序集合[1...n]，得到n!个排序，这些排序也是按照一定顺序，为
例如n=3，得到
1	"123"
2	"132"
3	"213"
4	"231"
5	"312"
6	"321"
求给定n的第k个序列
解决方法：
n=3,k=4
123
132
213     待抽取数为vec_i={1，2，3}
231
312
321
得到str[0]=vec_i[(k-1)/((n-1)!)]=2,更新k
13
31      vec_i={1，3}
得到str[1]=vec_i[(k-1)/((n-1)!)]=3,更新k
1       vec_i={1}
得到str[2]=1
*/

class Solution {
public:
	string getPermutation(int n, int k) {
		if (!n || k>factorial(n))  return string();
		string result(n, 0);     //结果
		vector<int> vec_i(n, 0); //用于存放待抽取的数
		for (int i = 1; i <= n; i++)   vec_i[i - 1] = i + '0';  //这些数按从小到大按顺序排列            
		recur(result, 0, vec_i, k - 1); //进行递归
		return result;
	}
private:
	void recur(string &str, int pos, vector<int> &vec_i, int k)
	{
		int n = vec_i.size();
		if (n == 1)                    //递归结束标志
		{
			str[pos] = vec_i[0];
			return;
		}
		int vec_pos = k / factorial(n - 1);   //第k个序列中的第一个数x在vec_i中的位置
		str[pos] = vec_i[vec_pos];        //保存x
		k = k%factorial(n - 1);             //更新k值
		vec_i.erase(vec_i.begin() + vec_pos);     //删除x
		recur(str, pos + 1, vec_i, k);       //迭代
	}
	int factorial(int n)        //求阶乘
	{
		if (n == 1)    return 1;
		return n*factorial(n - 1);
	}
};