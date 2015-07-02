#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
题目：输入一个递增的数组和一个整数s，打印所有和为s的连续正数序列（至少包含两个数）。
思路：定义两个指针i,j来确定序列的范围，i指向起始位置，j指向j的下一个位置，如果区间内数字和小于s，则j++,如果大于s,则i++,找到正确解则存储下来

重要程度：高
*/

class Solution{
public:
	vector<vector<int > > ContinusSum(vector<int > nums, int s){
		vector<vector<int > > ans;
		vector<int > cur;
		if(nums.size() < 2) return ans;
		int i = 0, j = i+1, sum = nums[i] + nums[j];
		while(i < j && j < nums.size()){
			if(sum == s){
				for(int k = i; k <= j; k++) cur.push_back(nums[k]);
				ans.push_back(cur);
				cur.clear();
			}
			if(sum < s) sum += nums[++j];
			else sum -= nums[i++];
		}
		return ans;
	}

};

int main()
{
	Solution c;
	int A[] = {1,2,3,4,5,6,7,8}, target=15;
	vector<int > num;
	for(int i = 0; i < sizeof(A)/4; i++)
		num.push_back(A[i]);
	vector<vector<int > > ans = c.ContinusSum(num, target);
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0;j < ans[i].size(); j++)
				cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}

