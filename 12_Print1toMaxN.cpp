#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ����������n����˳���ӡ����1������nλʮ��������������3����ӡ��1��999.
˼·��ע������n��λ�������n�ܴ�ʱ���㲻���ܲ�����ͨ����������ķ����������ϵ����������е㸴�ӣ�
	  ��ʵ�Ͽ��Խ��LeetCode��Plus One����Add Two Number���������������������ʾʮ�����������Ӷ�O(n^2)
*/
class Solution{
public:
	void PrintNumber(int n){ //��������洢
		vector<int > num(n, 0); //���峤��Ϊn����, ����ʼ��Ϊ0, �����0-n��ʾ�Ӹ�λ����λ
		bool done = false, isPrint = false;
		int c = 0; //��λ
		while(!done){
			c = 1;
			for(int i = n-1; i >= 0; i--){
				if(c == 0) break; //�޽�λ�����ü���ִ����
				int x = num[i] + c;
				num[i] = x % 10;
				c = x / 10;
			}
			done = true; 
			isPrint = false;
			for(int j = 0; j < n; j++){
				if(num[j] != 9) done = false;
				if(num[j] != 0 && !isPrint) isPrint = true; //ʡ�Ը�λ0
				if(isPrint) cout << num[j];
			}
			cout << endl;
		}
	}
};
int main()
{	
	Solution c;
	c.PrintNumber(4);
	return 0;
}
	

 