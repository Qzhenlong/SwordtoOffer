#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��дһ������������������֮�ͣ�Ҫ�������ڲ���ʹ�üӼ��˳�
˼·��
(1)����ɶ��������㰴λ��������,�����Եõ�ÿλ����λ�Ľ������Ϊx����������������һλ���ɵõ���λ�ϵĽ�λ,��Ϊy, ����λ�ټ���x���ظ�������̣�ֱ����λΪ0 
	�������Բ�����ʽ���㣬���Ҳ����Ҫ��
	
	Ӳ������мӷ�����ʵ�Ͼ����������Ź���, �ѵ���ǹ���һ����λ��

*/
class Solution{
public:
	int getSum(int a, int b){
		int x = a ^ b;
		int y = (a&b) << 1;
		while(y != 0){
			int tmp = x;
			x ^= y;
			y = (tmp&y) << 1;
		}
		return x;
	}
};

int main(){
	Solution c;
	cout << c.getSum(-2,-3); 
	return 0;
}
