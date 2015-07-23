#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ������һ������n�����1��n��n��������ʮ���Ʊ�ʾ��1���ֵĴ�������������12������1��������1��10��11��12���ܹ�����5��
˼·�����ߴ�1��n������1���ֵĹ��ɣ����Է��֣�Ӧ�ð������λ�����λ��1���ֵ�������ͳ�ơ�
��λ�ϵ�1ÿ10�����ֳ���һ�Σ�ʮλ�ϵ�1ÿ100�����ֺ���������ʮ�Σ���λ�ϵ�1ÿ1000��������������100��..., ���˹��ɿ��Ժܿ�����1�ܹ����ֵĴ�����
��1-99����λ��1���ֵĴ���Ϊ10��ʮλ�ϳ��ֵĴ���Ϊ1*10���ܹ�Ϊ20
  1-999�� ��λ��1���ֵĴ���Ϊ100��ʮλ�ϳ��ֵĴ���Ϊ10*10����λ�ϳ��ֵĴ���Ϊ1*100���ܹ�300
  ...
 ���裺1������Ϊtotal=0;
 ��1����mul=1,��n����10��c=0,�ý��a������b������b>=1�����λ��1������Ϊmul*a+1������Ϊmul*a
 ��2��c = b, mul=mul*10,�ٽ�n����100�õ�a��b����b>=2*mul����ʮλ��1������Ϊmul*(a+1), ��mul<=b<2*mul����Ϊmul*a+c+1, ��b < mul,��Ϊmul*a.
 ��3���ظ����Ϲ��̣�ֱ��a=0
*/
class Solution{
public:
    //O(logn);
	int NumberofOne(int n){
		int total = 0, mul = 1, c = 1, a = 1, b = 0;
		while(a != 0){ //�����ݲ����������ı�ʾ��Χ��leetcode�ⷨ�п���
			a = n / (mul*10);
			b = n % (mul*10);
			if(b < mul) total += mul*a;
			else if(b >= mul && b < 2*mul) total += (mul*a+c+1);
			else total += mul*(a+1);
			c = b;
			mul *= 10;
		}
		return total;
	}
	//ֱ����⣬O(nlogn)����֤������㷨��
	int NumberofOne1(int n){
		int total = 0;
		for(int i = 1; i <= n; i++) total += counter(i);
		return total;
	}
	int counter(int n){
		int total = 0;
		while(n){
			if(n % 10 == 1) total++;
			n = n/10;
		}
		return total;
	}
};

int main(){
	Solution c;
	int n = 1410065408;
	cout << c.NumberofOne(n) << endl;
	cout << c.NumberofOne1(n) << endl;
	return 0;
}
