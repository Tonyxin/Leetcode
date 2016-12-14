/*
����������
�����򼯺�[1...n]���õ�n!��������Щ����Ҳ�ǰ���һ��˳��Ϊ
����n=3���õ�
1	"123"
2	"132"
3	"213"
4	"231"
5	"312"
6	"321"
�����n�ĵ�k������
���������
n=3,k=4
123
132
213     ����ȡ��Ϊvec_i={1��2��3}
231
312
321
�õ�str[0]=vec_i[(k-1)/((n-1)!)]=2,����k
13
31      vec_i={1��3}
�õ�str[1]=vec_i[(k-1)/((n-1)!)]=3,����k
1       vec_i={1}
�õ�str[2]=1
*/

class Solution {
public:
	string getPermutation(int n, int k) {
		if (!n || k>factorial(n))  return string();
		string result(n, 0);     //���
		vector<int> vec_i(n, 0); //���ڴ�Ŵ���ȡ����
		for (int i = 1; i <= n; i++)   vec_i[i - 1] = i + '0';  //��Щ������С����˳������            
		recur(result, 0, vec_i, k - 1); //���еݹ�
		return result;
	}
private:
	void recur(string &str, int pos, vector<int> &vec_i, int k)
	{
		int n = vec_i.size();
		if (n == 1)                    //�ݹ������־
		{
			str[pos] = vec_i[0];
			return;
		}
		int vec_pos = k / factorial(n - 1);   //��k�������еĵ�һ����x��vec_i�е�λ��
		str[pos] = vec_i[vec_pos];        //����x
		k = k%factorial(n - 1);             //����kֵ
		vec_i.erase(vec_i.begin() + vec_pos);     //ɾ��x
		recur(str, pos + 1, vec_i, k);       //����
	}
	int factorial(int n)        //��׳�
	{
		if (n == 1)    return 1;
		return n*factorial(n - 1);
	}
};