#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
题目：输入一个递增的数组和一个数字s,在数组中查找两个数，使得它们的和正好为s,如果有多对符合要求的数字，输出一对即可。
思路：
（1）如果没有空间复杂度要求，可以采用一张哈希表，存储(s-x, x), x为数组中的数字，如果往后扫描，存在y = s-x， 则出数字对即可。（该方法数组无序也可）
（2）由于数组是递增的，显然空间可以更少，定义两个指针i,j，从数组两端往中间夹逼，当两数之和小于s时，i++,否则j--,直到找到结果

相关：LeetCode中的TwoSum
*/

class Solution{
public:
	vector<int > twoSum(vector<int > nums, int s){
		map<int, int> m;
		vector<int > ans;
		for(int i = 0; i < nums.size(); i++){
			if(m.find(nums[i]) == m.end()) m[s-nums[i]] = nums[i];
			else{
				ans.push_back(nums[i]);
				ans.push_back(m[nums[i]]);
				break;
			}
		}
		return ans;
	}
	vector<int > twoSum1(vector<int > nums, int s){
		vector<int > ans;
		int i = 0, j = nums.size()-1;
		while(i < j){
			int cur = nums[i]+nums[j];
			if(cur == s){
				ans.push_back(nums[i]);
				ans.push_back(nums[j]);
			}
			if(cur < s) i++;
			else j--;
		}
		return ans;
	}

};

int main()
{
	Solution c;
	int A[] = {1,2,3,4,5}, target=8;
	vector<int > num;
	for(int i = 0; i < sizeof(A)/4; i++)
		num.push_back(A[i]);
	vector<int > ans = c.twoSum(num, target);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}

