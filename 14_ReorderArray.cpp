#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ������һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ����������λ������ǰ�벿�֣�����ż��λ�ں�벿��
˼·����������ͷβָ��i,j�������м�бƣ��趨һ����ʱ�����ݴ��м�ֵ��
1����A[i]Ϊż����A[j]ҲΪż��ʱ��j--��
2����A[j]Ϊ������A[i]ҲΪ����ʱ��i++;
3����A[i]Ϊż����A[j]Ϊ����ʱ��������
4����i==jʱ������
*/
class Solution{
public:
	void reorderArray(vector<int > &A){
		int i = 0, j = A.size()-1;
		while(i < j){
			if(A[i]%2 == 0 && A[j]%2 == 1){
				int tmp = A[i];
				A[i] = A[j];
				A[j] = tmp;
			}
			if(A[i]%2 == 1) i++;
			if(A[j]%2 == 0) j--;
		}
	}

};
int main()
{	
	Solution c;
	int A[] = {1,2};
	vector<int > num;
	for(int i = 0; i < sizeof(A)/4; i++){
		num.push_back(A[i]);
		cout << A[i] << " ";
	}
	cout << endl;
	c.reorderArray(num);
	for(int i = 0; i < num.size(); i++)
		cout << num[i] << " ";
	
	return 0;
}

	

 