#include<iostream>
#include<stack>
using namespace std;
/*
��Ŀ������ջ���ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ����СԪ�ص�Min������ʹ�õ���min,push,pop��ʱ�临�Ӷȶ�ΪO(1)
˼·����Сջ���⣬��������ջ��һ��ִ������ջ��������һ�����ڵõ���ǰ��СԪ��
��أ�LeetCode�е�Mini Stackһ��
*/

class MiniStack{
public:
	void push(int e){
		if(ms.empty() || e <= ms.top())  ms.push(e); //ע��ջ�յ����
		s.push(e);
	}
	void pop(){
		if(s.empty()) return;
		if(!ms.empty() && s.top() <= ms.top()) ms.pop();
		s.pop();
	}
	int top(){
		return s.top();
	}
	int min(){
		if(!ms.empty()) 
			return ms.top(); 
	}
private:
	stack<int > s;
	stack<int > ms; //��Сջ

};
int main()
{
  MiniStack ms;
  ms.push(1);
  ms.push(4);
  ms.push(6);
  ms.push(3);
  cout << ms.top() << endl;
  cout << ms.min() << endl;
  return 1;   
}

