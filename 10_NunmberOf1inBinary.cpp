#include<iostream>
using namespace std;
/*
��Ŀ����ʵ��һ������������һ��������������������Ʊ�ʾ��1�ĸ�����
��أ�LeedCode�е�Hamming Weight
˼·�������λ�������������㺺���ء�
*/

class Solution{
public:
	int hammingWeight(int x){ //�޷�������
		int hw = 0, y = 1;
		while(x > 0){
			hw += (x & y);
			x = x >> 1;
		}
		return hw;
	}
	int hammingWeight1(int x){
		int hw = 0, y = 1;
		for(int i = 0; i < sizeof(x)*8; i++) hw += ((x >> i) & y);
		return hw;
	}
	int hammingWeight2(int x){
		int hw = 0, y = 1;
		while(y){
			if(y & x) hw++;
			y = y << 1;
		}
		return hw;		
	}
};
int main()
{
  Solution c;
  cout << c.hammingWeight(0x80000000)<< endl;
  cout << c.hammingWeight1(0x80000000)<< endl;
  cout << c.hammingWeight2(0x80000000)<< endl;
  return 1;   
}

