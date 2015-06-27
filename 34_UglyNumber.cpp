#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ�����ǰ�ֻ��������2��3��5������Ϊ������ ���С�����˳��ĵ�1500������������6��8�ǳ�����14���ǣ�ϰ���Ͻ�1������һ������
˼·��
��1������������������2������������3������������5���������Ϊ1˵��Ϊ������Ч�ʲ�����
��2������ǰ������ϵ����֮ǰ�жϹ��ĳ����洢���������Խ���ʱ�临�Ӷȣ��������£�
	 �����еĳ����ֱ�����������U�У���ʼ��Ϊ1;
	 �����еĳ����ֱ����2��3��5����һ�������������������ķֱ��Ϊp2,p3,p5, ������������Сֵ��Ϊ���³�������U
	 ֱ��U�������ﵽҪ�󼴿�ֹͣ��

*/
class Solution{
public:
	//��Ч�㷨��������֤��
	int GetUgly0(int n){
		int c = 0, num = 1, ans = 1;
		while(c < n){
			if(isUgly(num)){
				c++;
				ans = num;
			}
			num++;
		}
		return ans;
	}
	bool isUgly(int num){
		while(num % 2 == 0 && num > 0) num /= 2;
		while(num % 3 == 0 && num > 0) num /= 3;
		while(num % 5 == 0 && num > 0) num /= 5;
		return (num == 1) ? true : false;
	}
	//��Ч�㷨 
	int GetUgly(int n){
		vector<int > uglyNum;
		int i2=0,i3=0,i5=0,p2=1,p3=1,p5=1;
		uglyNum.push_back(1);
		while(uglyNum.size() < n){
			int _min = min(p2*2, min(p3*3, p5*5));
			uglyNum.push_back(_min);
			while(uglyNum[i2]*2 <= uglyNum[uglyNum.size()-1]) p2 = uglyNum[++i2];
			while(uglyNum[i3]*3 <= uglyNum[uglyNum.size()-1]) p3 = uglyNum[++i3];
			while(uglyNum[i5]*5 <= uglyNum[uglyNum.size()-1]) p5 = uglyNum[++i5];
		}
		return uglyNum[uglyNum.size()-1];
	}
};

int main(){
	Solution c;
	for(int i = 1; i < 30; i++)
		cout << c.GetUgly(i) << " " << c.GetUgly0(i) << endl;
	
	cout << c.GetUgly(1500) <<" " << c.GetUgly0(1500) << endl;
	return 0;
}
