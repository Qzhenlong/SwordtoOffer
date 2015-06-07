#include<iostream>
using namespace std;
/*
题目：写一个函数，输入n,求斐波那契数列的第N项
相关：LeetCode的Climbing Stairs
思路：如果使用递归会极大降低效率，因此直接用一次扫描计算即可
*/
class Solution{
public:
	int fibonacci(int n){
		if(n <= 0) return 0;
		if(n == 1) return 1;
		int x = 0, y = 1, ans;
		for(int i = 2; i <= n; i++){
			ans = x + y;
			x = y;
			y = ans;
		}
		return ans;
	}
};
int main(){
  Solution c;
  int n = 2;
  cout << c.fibonacci(n) << endl;
  return 1;  
}

