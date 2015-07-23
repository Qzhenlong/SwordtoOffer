#include<iostream>
#include<vector>
using namespace std;
/*
题目：输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数。比如输入12，包含1的数字有1，10，11，12，总共出现5次
思路：观者从1到n数字中1出现的规律，可以发现，应该按从最低位到最高位上1出现的数量来统计。
个位上的1每10个数字出现一次，十位上的1每100个数字后连续出现十次，百位上的1每1000个数字连续出现100次..., 按此规律可以很快计算出1总共出现的次数。
如1-99，个位上1出现的次数为10，十位上出现的次数为1*10，总共为20
  1-999， 个位上1出现的次数为100，十位上出现的次数为10*10，百位上出现的次数为1*100，总共300
  ...
 步骤：1的总数为total=0;
 （1）令mul=1,用n除以10，c=0,得结果a及余数b，当若b>=1，则个位上1的数量为mul*a+1，否则为mul*a
 （2）c = b, mul=mul*10,再将n除以100得到a和b，若b>=2*mul，则十位上1的数量为mul*(a+1), 若mul<=b<2*mul，则为mul*a+c+1, 若b < mul,则为mul*a.
 （3）重复以上过程，直到a=0
*/
class Solution{
public:
    //O(logn);
	int NumberofOne(int n){
		int total = 0, mul = 1, c = 1, a = 1, b = 0;
		while(a != 0){ //这里暂不考虑整数的表示范围，leetcode解法中考虑
			a = n / (mul*10);
			b = n % (mul*10);
			if(b < mul) total += mul*a;
			else if(b >= mul && b < 2*mul) total += (mul*a+c+1);
			else total += mul*(a+1);
			c = b;
			mul *= 10;
		}
		return total;
	}
	//直接求解，O(nlogn)当验证上面的算法吧
	int NumberofOne1(int n){
		int total = 0;
		for(int i = 1; i <= n; i++) total += counter(i);
		return total;
	}
	int counter(int n){
		int total = 0;
		while(n){
			if(n % 10 == 1) total++;
			n = n/10;
		}
		return total;
	}
};

int main(){
	Solution c;
	int n = 1410065408;
	cout << c.NumberofOne(n) << endl;
	cout << c.NumberofOne1(n) << endl;
	return 0;
}
