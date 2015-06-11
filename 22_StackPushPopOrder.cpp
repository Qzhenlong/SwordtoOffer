#include<iostream>
#include<stack>
#include<vector>
using namespace std;
/*
��Ŀ�����������������У���һ�����б�ʾջѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳�򣬼���ѹ��ջ���������־�����ȡ�
�磺ѹջ���У�1��2��3��4��5�� ����4��5��3��2��1��һ���������У���4��3��5��1��2�����䵯������

˼·��ͨ��һ������ջ��ʵ���жϣ�ѹջ����һ�߽�ջһ�߼�ⵯ�����У�����ǰջ��Ԫ�ص��ڵ������еĵ�ǰֵʱ��Ԫ�س�ջ��
	  ����������ɨ�����ʱ������ջΪ����˵�����䵯�����У������ǡ�
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

