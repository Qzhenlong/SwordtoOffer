#include<iostream>
#include<queue>
using namespace std;
/*
��չ����������ʵ��һ��ջ��ʵ�ֽ�ջ���ջ
����һ�����и������ջ��Ԫ�أ�����һ������һֱΪ�գ��������ջ��
*/
class Stack {
public:
    // Push element x onto stack.
    void push(int x) {
		if(q1.empty()) q2.push(x); //�ҷǿն��н�
		else q1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        if(q1.empty() && q2.empty()) return; //ջ��
		if(q1.empty()){ //��q2Ԫ��ȫ������q1
			while(!q2.empty()){
				if(q2.size() == 1){ q2.pop(); break; }
				q1.push(q2.front());
				q2.pop();
			}
		}
		else{
			while(!q1.empty()){
				if(q1.size() == 1){ q1.pop(); break; }
				q2.push(q1.front());
				q1.pop();
			}
		}
    }

    // Get the top element.
    int top() {
		int ans = -1;
        if(q1.empty() && q2.empty()) return ans; //ջ��
		if(q1.empty()){ //��q2Ԫ��ȫ������q1
			while(!q2.empty()){
				ans = q2.front();
				q1.push(q2.front());
				q2.pop();
			}
		}
		else{
			while(!q1.empty()){
				ans = q1.front();
				q2.push(q1.front());
				q1.pop();
			}
		}
		return ans;
    }

    // Return whether the stack is empty.
    bool empty() {
        return (q1.empty() && q2.empty());
    }
private:
	queue<int > q1;
	queue<int > q2;
};

int main(){
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	cout << s.top() << endl;
	s.pop();
	cout << s.top() << endl;
	s.push(4);
	cout << s.top() << endl;
	cout << s.empty() <<endl;
}
