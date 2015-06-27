#include<iostream>
#include<vector>
using namespace std;
/*
题目：输入一个正整数数组，把数组里所有数字拼接排开成一个数，打印能拼接出的所有数字中的最小值，假如输入数组{3，32，321}，最小值为321323
思路：由于要对数组中的元素进行组合，要得到最小值，那么必须放在第一的，必然是该数组元素中最高位最小的元素（当前元素的最高位，与其它元素的位数无关）。
	 （1） 可以考虑按从高到低位对数组进行排序，这样虽然比找全排列的复杂度为低，但是也不够优化。
	 （2）如果只进行一次排序就能得到最后结果那就可将复杂度降至O(nlogn),方法如下：
		a. 先将数组所有元素补成位数相同；
		b. 填补的规则为：假设数组中元素最大为t位，那么位数小于t位的数字，将其最低位后面补充与最低位相同的数字，至t位
		c. 再排序即可。
思路错误，LeetCode中 219 / 221 test cases passed. 测试用例[824,938,1399,5607,6973,5703,9609,4398,8247]

书中思路：
先将整数数组转为字符串数组，然后字符串数组进行排序，最后依次输出字符串数组即可。
这里注意的是字符串的比较函数需要重新定义，不是比较a和b，而是比较ab与 ba。
如果ab < ba，则a < b；如果ab > ba，则a > b；如果ab = ba，则a = b。
事实上就是定义一个新的对比函数，将字符串进行排序即可
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
	    if(zero) return "0"; //全都为0;
		while(max > 0){
			max /= 10;
			div *= 10; //找出最大值的位数
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
	//正解
	static bool cmp(const string &s1, const string &s2) { //重载对比函数
        return (s1 + s2) < (s2 + s1);
    }
    string largestNumber1(vector<int> &nums) {
        vector<string> s_num(nums.size());
		string ans = "";
		bool zero = true;
        for (int i = 0; i < nums.size(); ++i) {
            //s_num[i] = to_string(nums[i]); //转换为字符串
			s_num[i] = int2string(nums[i]);
			if(nums[i] != 0 && zero) zero = false;
        }
		if(zero) return "0"; //全0
        sort(s_num.begin(), s_num.end(), cmp);

		for(int i = 0; i < nums.size(); i++){
			if(s_num[i] != "0" && !zero) zero = true;
			if(zero) ans += s_num[i]; //去除高位0
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
