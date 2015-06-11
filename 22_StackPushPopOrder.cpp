#include<iostream>
#include<stack>
#include<vector>
using namespace std;
/*
题目：输入两个整数序列，第一个序列表示栈压入顺序，请判断第二个序列是否为该栈的弹出顺序，假设压入栈的所有数字均不相等。
如：压栈序列：1，2，3，4，5， 序列4，5，3，2，1是一个弹出序列，而4，3，5，1，2不是其弹出序列

思路：通过一个辅助栈来实现判断，压栈序列一边进栈一边检测弹出序列，当当前栈顶元素等于弹出序列的当前值时，元素出栈，
	  当弹出序列扫描完毕时，辅助栈为空则说明是其弹出序列，否则不是。
*/

class Solution{
public:
	bool isPopSeq(vector<int > pushSeq, vector<int > popSeq){
		if(pushSeq.size() != popSeq.size()) return false;
		stack<int > s;
		int i = 0, j = 0;
		while(i < pushSeq.size() && j < popSeq.size()){
			if(i < pushSeq.size()) s.push(pushSeq[i++]);
			while(!s.empty() && j < popSeq.size() && popSeq[j] == s.top()){
				s.pop(); j++;
			}
		}
		if(s.empty()) return true;
		return false;
	}
};
int main()
{
  Solution c;
  int A[] = {1,2,3,4,5};
  int B[] = {4,3,5,1,2};//{4,5,3,2,1};
  vector<int > p1,p2;
  for(int i = 0; i < sizeof(A)/4; i++){
	p1.push_back(A[i]);
	p2.push_back(B[i]);
  }
  cout << c.isPopSeq(p1,p2);
  return 0;   
}

