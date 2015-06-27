#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ������һ�����������飬����������������ƴ���ſ���һ��������ӡ��ƴ�ӳ������������е���Сֵ��������������{3��32��321}����СֵΪ321323
˼·������Ҫ�������е�Ԫ�ؽ�����ϣ�Ҫ�õ���Сֵ����ô������ڵ�һ�ģ���Ȼ�Ǹ�����Ԫ�������λ��С��Ԫ�أ���ǰԪ�ص����λ��������Ԫ�ص�λ���޹أ���
	 ��1�� ���Կ��ǰ��Ӹߵ���λ�������������������Ȼ����ȫ���еĸ��Ӷ�Ϊ�ͣ�����Ҳ�����Ż���
	 ��2�����ֻ����һ��������ܵõ�������ǾͿɽ����ӶȽ���O(nlogn),�������£�
		a. �Ƚ���������Ԫ�ز���λ����ͬ��
		b. ��Ĺ���Ϊ������������Ԫ�����Ϊtλ����ôλ��С��tλ�����֣��������λ���油�������λ��ͬ�����֣���tλ
		c. �����򼴿ɡ�
˼·����LeetCode�� 219 / 221 test cases passed. ��������[824,938,1399,5607,6973,5703,9609,4398,8247]

����˼·��
�Ƚ���������תΪ�ַ������飬Ȼ���ַ�������������������������ַ������鼴�ɡ�
����ע������ַ����ıȽϺ�����Ҫ���¶��壬���ǱȽ�a��b�����ǱȽ�ab�� ba��
���ab < ba����a < b�����ab > ba����a > b�����ab = ba����a = b��
��ʵ�Ͼ��Ƕ���һ���µĶԱȺ��������ַ����������򼴿�
*/
class Solution{
public:
    string largestNumber(vector<int>& nums) {
		int n = nums.size();
		if(n == 0) return "0";
		string ans = "";
		bool zero = true;
		vector<pair<int, int > > p;
		int max = nums[0], div = 1;
		for(int i = 0; i < n; i++){
			if(max < nums[i]) max = nums[i];
			if(nums[i] != 0 && zero) zero = false;
		}
	    if(zero) return "0"; //ȫ��Ϊ0;
		while(max > 0){
			max /= 10;
			div *= 10; //�ҳ����ֵ��λ��
		}
		div /= 10;
		cout << div << endl;
		for(int i = 0; i < n; i++){
			int len = -1, d = div, c, x = 0;
			if(nums[i] == 0) x = -1;
			while(x == 0 && d > 0){
				x = nums[i] / d;
				d /= 10;
				len++;
			}
			c = nums[i] % 10;
			int tmp = nums[i];
			for(int j = 0; j < len; j++) tmp = tmp*10 + c;
			p.push_back(make_pair(tmp, i));
			cout << tmp << endl;
		}
		sort(p.begin(), p.end());
		char str[32];
		for(int i = 0; i < n; i++){\
		    itoa(nums[p[i].second], str, 10);
			ans += str;
		}
	
		
		return ans;
    }
	//����
	static bool cmp(const string &s1, const string &s2) { //���ضԱȺ���
        return (s1 + s2) < (s2 + s1);
    }
    string largestNumber1(vector<int> &nums) {
        vector<string> s_num(nums.size());
		string ans = "";
		bool zero = true;
        for (int i = 0; i < nums.size(); ++i) {
            //s_num[i] = to_string(nums[i]); //ת��Ϊ�ַ���
			s_num[i] = int2string(nums[i]);
			if(nums[i] != 0 && zero) zero = false;
        }
		if(zero) return "0"; //ȫ0
        sort(s_num.begin(), s_num.end(), cmp);

		for(int i = 0; i < nums.size(); i++){
			if(s_num[i] != "0" && !zero) zero = true;
			if(zero) ans += s_num[i]; //ȥ����λ0
		}
        return ans;
    }
	string int2string(int number)
	{
		   string s1,s2;
		   s1 = "";
		   int tmp = abs(number);
		   
		   while(tmp){
						 s1 += (tmp%10+'0');
						 tmp /= 10;
		   }
		   
		   s2 = "";
		   if(number == 0) s2 = "0";
		   if(number < 0) s2 += '-';
		   for(int i = s1.size()-1; i >= 0; i--) 
				   s2 += s1[i];
		   return s2;
	}
};

int main(){
	Solution c;
	int A[] = {3,32,321};
	vector<int > nums;
	for(int i = 0; i < sizeof(A)/4; i++) nums.push_back(A[i]);
	cout << c.largestNumber1(nums);
	return 0;
}
