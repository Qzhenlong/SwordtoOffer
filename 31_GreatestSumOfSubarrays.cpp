#include<iostream>
#include<vector>
using namespace std;
/*
题目：输入一个数组，数组中一个或者连续几个整数组成一个子数组。求所有子数组的和的最大值，时间复杂度要求为O(n)
思路：动态规划思想，设数组为A，f(i)为i之前子数组和的最大值，则状态转移方程：f(i)=max(f(i-1)+A[i], A[i]);
*/

class Solution{
public:
	int MaxSum(vector<int > A){
		if(A.size() == 0) return 0;
		int maxSum = A[0], curMax = A[0];
		for(int i = 1; i < A.size(); i++){
			curMax = max(curMax+A[i], A[i]);
			maxSum = max(curMax, maxSum);
		}
		return maxSum;
	}
	
};

int main(){
	Solution c;
	vector<int > n;
	int A[] = {1,-2,3,10,-4,7,2,-5};
	for(int i = 0; i < sizeof(A)/4; i++) n.push_back(A[i]);
	cout << c.MaxSum(n);
	return 0;
}
