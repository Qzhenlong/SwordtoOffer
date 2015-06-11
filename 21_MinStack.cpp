#include<iostream>
#include<stack>
using namespace std;
/*
题目：定义栈数据结构，请在该类型中实现一个能够得到栈中最小元素的Min函数，使用调用min,push,pop的时间复杂度都为O(1)
思路：最小栈问题，定义两个栈，一个执行正常栈操作，另一个用于得到当前最小元素
相关：LeetCode中的Mini Stack一题
*/

class MiniStack{
public:
	void push(int e){
		if(ms.empty() || e <= ms.top())  ms.push(e); //注意栈空的情况
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
	stack<int > ms; //最小栈

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

