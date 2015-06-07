#include<iostream>
#include<vector>
using namespace std;
/*
题目：输入数字n，按顺序打印出从1到最大的n位十进制数，如输入3，打印数1到999.
思路：注意数字n是位数，如果n很大时，便不可能采用普通的数字运算的方法做，书上的做法还是有点复杂，
	  事实上可以借鉴LeetCode上Plus One或者Add Two Number，定义数组或者链表来表示十进制数，复杂度O(n^2)
*/
class Solution{
public:
	void PrintNumber(int n){ //利用数组存储
		vector<int > num(n, 0); //定义长度为n的数, 并初始化为0, 数组从0-n表示从高位到低位
		bool done = false, isPrint = false;
		int c = 0; //进位
		while(!done){
			c = 1;
			for(int i = n-1; i >= 0; i--){
				if(c == 0) break; //无进位，不用继续执行了
				int x = num[i] + c;
				num[i] = x % 10;
				c = x / 10;
			}
			done = true; 
			isPrint = false;
			for(int j = 0; j < n; j++){
				if(num[j] != 9) done = false;
				if(num[j] != 0 && !isPrint) isPrint = true; //省略高位0
				if(isPrint) cout << num[j];
			}
			cout << endl;
		}
	}
};
int main()
{	
	Solution c;
	c.PrintNumber(4);
	return 0;
}
	

 