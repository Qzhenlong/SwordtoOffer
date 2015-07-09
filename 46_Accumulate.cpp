#include<iostream>
#include<vector>
using namespace std;
/*
题目：求1+2...+n,要求不能使用乘除法，for,while..等关键字及条件 判断语句（A?B:C)

思路：
（1）采用类的思路求解，定义一个类，将和设计成静态成员变量，每次实例化时加一个数，实例化N次即可
（2）类继承的方法，子类当做递归函数，基类当做递归终止条件。
*/
int n = 0;
int sum = 0;
class Acc{
public:
	Acc(){ n++; sum += n; }
	static void reset(){ n = 0; sum = 0; }
	static int getSum(){
		return sum;
	}
//private:
	//static int sum;
	//static int n;
};
//int Acc::n = 0;
//int Acc::sum = 0;
int main(){
	Acc::reset();
	Acc *a = new Acc[5];
	delete[] a;
	a = NULL;
	cout << Acc::getSum() << endl;
	return 0;
}
