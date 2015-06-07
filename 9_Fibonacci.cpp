#include<iostream>
using namespace std;
/*
��Ŀ��дһ������������n,��쳲��������еĵ�N��
��أ�LeetCode��Climbing Stairs
˼·�����ʹ�õݹ�Ἣ�󽵵�Ч�ʣ����ֱ����һ��ɨ����㼴��
*/
class Solution{
public:
	int fibonacci(int n){
		if(n <= 0) return 0;
		if(n == 1) return 1;
		int x = 0, y = 1, ans;
		for(int i = 2; i <= n; i++){
			ans = x + y;
			x = y;
			y = ans;
		}
		return ans;
	}
};
int main(){
  Solution c;
  int n = 2;
  cout << c.fibonacci(n) << endl;
  return 1;  
}

