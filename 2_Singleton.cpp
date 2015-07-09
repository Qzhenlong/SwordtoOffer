#include<iostream>
using namespace std;
/*
��Ŀ�����һ���࣬����ֻ�����ɸ����һ��ʵ��
��չ�������ģʽ��
ע�⣺�Լ���ֽ����д����@Qzl

*/
//C++�汾
//���߳�
class Singleton {
public:
	Singleton* getInstance(){
		if(instance == NULL)
			instance = new Singleton();
		return instance;
	}
private:
	Singleton(){ } //��̬���캯��
	static Singleton *instance;
};
//���߳�
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
	Singleton(){ } //��̬���캯��
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
	Singleton(){ } //��̬���캯��
	static Singleton2 *instance;
};
