#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ����C++���һ�����ܱ��̳е���

˼·��˽�й��캯������������

*/
class SealedClass{
public:
	static SealedClass *getInstance(){
		return new SealedClass(); //�е������ڵ���, ֻ��������Թ�����ʵ�� 
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
