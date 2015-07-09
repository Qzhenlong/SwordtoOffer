#include<iostream>
#include<vector>
using namespace std;
/*
题目：写一个函数，求两个整数之和，要求函数体内不得使用加减乘除
思路：
(1)换算成二进制运算按位进行运算,异或可以得到每位不进位的结果，记为x，两数相与结果左移一位，可得到各位上的进位,记为y, 将进位再加上x，重复这个过程，直到进位为0 
	负数是以补码形式运算，因此也满足要求。
	
	硬件设计中加法器事实上就是由与或非门构成, 难点就是构造一个进位器

*/
class Solution{
public:
	int getSum(int a, int b){
		int x = a ^ b;
		int y = (a&b) << 1;
		while(y != 0){
			int tmp = x;
			x ^= y;
			y = (tmp&y) << 1;
		}
		return x;
	}
};

int main(){
	Solution c;
	cout << c.getSum(-2,-3); 
	return 0;
}
