#include<iostream>
using namespace std;
/*
题目：实现函数double Power(double x, int n), 计算x的n次方，不需要考虑大数问题
相关：LeetCode中的Pow(x,n)
思路：采用x^n = (x^n/2) * (x^n/2) (n为偶数）的想法。
*/
class Solution{
public:
	double Power(double x, int n){ //非递归
		if(n == 0) return 1;
		if(x == 1 || x == 0) return x;
		double ans = 1;
		if(n < 0) x = 1/x;
		while(abs(n) > 0){
			if(n % 2 == 1) ans *= x;
			n /= 2;
			x *= x;
		}
		return ans;
	}
	//递归
	double Power1(double x, int n){
		if(n < 0) 
			return 1/mypower(x,n);
		else
			return mypower(x,n);
	}
	double mypower(double x, int n){
		if(n == 0) return 1;
		double v = mypower(x, n/2);
		if(n % 2 == 0) return v*v;
		else return v*v*x;
	}
};
int main(){
	Solution c;
	cout << c.Power(2,3) << endl;
	cout << c.Power1(2,-3) << endl;
	return 0;
}

