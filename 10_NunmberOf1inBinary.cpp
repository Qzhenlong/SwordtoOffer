#include<iostream>
using namespace std;
/*
题目：请实现一个函数，输入一个整数，输出该数二进制表示中1的个数。
相关：LeedCode中的Hamming Weight
思路：结合移位运算和与运算计算汉明重。
*/

class Solution{
public:
	int hammingWeight(int x){ //无法处理负数
		int hw = 0, y = 1;
		while(x > 0){
			hw += (x & y);
			x = x >> 1;
		}
		return hw;
	}
	int hammingWeight1(int x){
		int hw = 0, y = 1;
		for(int i = 0; i < sizeof(x)*8; i++) hw += ((x >> i) & y);
		return hw;
	}
	int hammingWeight2(int x){
		int hw = 0, y = 1;
		while(y){
			if(y & x) hw++;
			y = y << 1;
		}
		return hw;		
	}
};
int main()
{
  Solution c;
  cout << c.hammingWeight(0x80000000)<< endl;
  cout << c.hammingWeight1(0x80000000)<< endl;
  cout << c.hammingWeight2(0x80000000)<< endl;
  return 1;   
}

