#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ����1+2...+n,Ҫ����ʹ�ó˳�����for,while..�ȹؼ��ּ����� �ж���䣨A?B:C)

˼·��
��1���������˼·��⣬����һ���࣬������Ƴɾ�̬��Ա������ÿ��ʵ����ʱ��һ������ʵ����N�μ���
��2����̳еķ��������൱���ݹ麯�������൱���ݹ���ֹ������
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
