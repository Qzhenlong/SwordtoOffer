#include<iostream>
#include<vector>
using namespace std;
/*
题目：我们把只包含因子2，3，5的数称为丑数。 求从小到大的顺序的第1500个丑数。例如6和8是丑数，14不是，习惯上将1看作第一个丑数
思路：
（1）连续除，连续除以2，再连续除以3，再连续除以5，如果最终为1说明为丑数，效率不够高
（2）丑数前后有联系，将之前判断过的丑数存储下来，可以降低时间复杂度，方法如下：
	 将已有的丑数分别按序存放至数组U中，初始化为1;
	 将已有的丑数分别乘以2，3，5，第一个大于数组中最大丑数的分别记为p2,p3,p5, 这三个数的最小值作为当新丑数加入U
	 直到U的数量达到要求即可停止。

*/
class Solution{
public:
	//低效算法，用作验证吧
	int GetUgly0(int n){
		int c = 0, num = 1, ans = 1;
		while(c < n){
			if(isUgly(num)){
				c++;
				ans = num;
			}
			num++;
		}
		return ans;
	}
	bool isUgly(int num){
		while(num % 2 == 0 && num > 0) num /= 2;
		while(num % 3 == 0 && num > 0) num /= 3;
		while(num % 5 == 0 && num > 0) num /= 5;
		return (num == 1) ? true : false;
	}
	//高效算法 
	int GetUgly(int n){
		vector<int > uglyNum;
		int i2=0,i3=0,i5=0,p2=1,p3=1,p5=1;
		uglyNum.push_back(1);
		while(uglyNum.size() < n){
			int _min = min(p2*2, min(p3*3, p5*5));
			uglyNum.push_back(_min);
			while(uglyNum[i2]*2 <= uglyNum[uglyNum.size()-1]) p2 = uglyNum[++i2];
			while(uglyNum[i3]*3 <= uglyNum[uglyNum.size()-1]) p3 = uglyNum[++i3];
			while(uglyNum[i5]*5 <= uglyNum[uglyNum.size()-1]) p5 = uglyNum[++i5];
		}
		return uglyNum[uglyNum.size()-1];
	}
};

int main(){
	Solution c;
	for(int i = 1; i < 30; i++)
		cout << c.GetUgly(i) << " " << c.GetUgly0(i) << endl;
	
	cout << c.GetUgly(1500) <<" " << c.GetUgly0(1500) << endl;
	return 0;
}
