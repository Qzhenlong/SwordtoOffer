#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
/*
题目：把n个骰子扔在地上，所有骰子朝上一面的点数之和为s， 输入n，打印出s的所有可能值出现的概率

思路：
(1) 总的可能种类为6^n, 子问题就是给定一个值，求和为该值的所有可能，求排列再统计符合条件的数量
(2) 动态规划：dp[i][j]表示有i个骰子的情况下，点数之和为j的所有可能种类数，则动态转移方程
dp[i][j] = dp[i-1][j-1]+dp[i-1][j-2]...dp[i-1][j-5];

(dp[1][1] = dp[1][2]... = dp[1][6] = 1;
可以看出j在第一行为1-6，第二行变成2-12...第i行为2*i-6*j
每行长度不一样，由于当前行只和上一行的6个元素相关，利用滚动数组的思路，只需要定义两个大小为6*n的数组交替使用即可

最后一行即为所求结果

*/

class Solution {
public:
	void printProbability(int n){
		double all = pow(6, n);
		int total = 0, ver = 0;
		for(int i = n; i <= 6*n; i++){
			cout << "s = " << i << ": ";
			fun(i, 0, total, 0, n);
			cout << total << "/" << all << endl;
			ver += total;
			total = 0;
		}
		cout << "total: " << ver << endl;
	}
	void fun(int sum, int cursum, int &total, int i, int n){
		if(i > n) return;
		if(i == n && cursum == sum) total++;
		for(int j = 1; j <= 6; j++){
			if(cursum < sum){
				fun(sum, cursum+j, total, i+1, n);
			}
		}
	}
	void printProbability1(int n){
		vector<vector<int > > A(2, vector<int >(6*n+1, 0)); //第0个元素不使用
		for(int i = 1; i <= 6; i++) A[0][i] = 1; //只有一个骰子，每种取值只有一种情况
		int index = 0; //交替使用
		for(int i = 2; i <= n; i++){
		    for(int j = 0; j < i; j++) //点数小于骰子数量，种类为0
				A[1-index][j] = 0;
				
			for(int j = i; j <= 6*i; j++){
				A[1-index][j] = 0; //置0，求累加和
				for(int k = 1; k < j && k <= 6; k++)
					A[1-index][j] += A[index][j-k];
			}
			index = 1 - index;
		}
		double all = pow(6, n);
		int ver = 0;
		for(int i = n; i <= 6*n; i++){
			cout << "s = " << i << ": ";
			cout << A[index][i] << "/" << all << endl;
			ver += A[index][i];
		}
		cout << "total: " << ver << endl;
	}
    
};

int main()
{
	Solution c;
	c.printProbability(4);
	c.printProbability1(4);
	return 0;
}

