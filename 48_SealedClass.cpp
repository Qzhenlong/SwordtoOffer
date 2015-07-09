#include<iostream>
#include<vector>
using namespace std;
/*
题目：用C++设计一个不能被继承的类

思路：私有构造函数和析构函数

*/
class SealedClass{
public:
	static SealedClass *getInstance(){
		return new SealedClass(); //有点类似于单例, 只是这里可以构造多个实例 
	}
	static SealedClass *deleteInstance(SealedClass *instance){
		delete instance;
	}
private:
	SealedClass();
	~SealedClass();
};

int main(){
	
	return 0;
}
