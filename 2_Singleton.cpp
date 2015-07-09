#include<iostream>
using namespace std;
/*
题目：设计一个类，我们只能生成该类的一个实例
扩展：大话设计模式，
注意：自己在纸上书写程序@Qzl

*/
//C++版本
//单线程
class Singleton {
public:
	Singleton* getInstance(){
		if(instance == NULL)
			instance = new Singleton();
		return instance;
	}
private:
	Singleton(){ } //静态构造函数
	static Singleton *instance;
};
//多线程
class Singleton1 {
public:
	Singleton1* getInstance(){
		lock();
		if(instance == NULL)
			instance = new Singleton1();
		unlock();
		return instance;
	}
private:
	Singleton(){ } //静态构造函数
	static Singleton1 *instance;
};

class Singleton2{
public:
	Singleton2* getInstance(){
		if(instance == NULL){
			lock();
			if(instance == NULL)
				instance = new Singleton2();
			unlock();
		}
		return instance;
	}
private:
	Singleton(){ } //静态构造函数
	static Singleton2 *instance;
};
