#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
/*
��Ŀ����n���������ڵ��ϣ��������ӳ���һ��ĵ���֮��Ϊs�� ����n����ӡ��s�����п���ֵ���ֵĸ���

˼·��
(1) �ܵĿ�������Ϊ6^n, ��������Ǹ���һ��ֵ�����Ϊ��ֵ�����п��ܣ���������ͳ�Ʒ�������������
(2) ��̬�滮��dp[i][j]��ʾ��i�����ӵ�����£�����֮��Ϊj�����п�������������̬ת�Ʒ���
dp[i][j] = dp[i-1][j-1]+dp[i-1][j-2]...dp[i-1][j-5];

(dp[1][1] = dp[1][2]... = dp[1][6] = 1;
���Կ���j�ڵ�һ��Ϊ1-6���ڶ��б��2-12...��i��Ϊ2*i-6*j
ÿ�г��Ȳ�һ�������ڵ�ǰ��ֻ����һ�е�6��Ԫ����أ����ù��������˼·��ֻ��Ҫ����������СΪ6*n�����齻��ʹ�ü���

���һ�м�Ϊ������

*/

class Solution {
public:
	void printProbability(int n){
		double all = pow(6, n);
		int total = 0, ver = 0;
		for(int i = n; i <= 6*n; i++){
			cout << "s = " << i << ": ";
			fun(i, 0, total, 0, n);
			cout << total << "/" << all << endl;
			ver += total;
			total = 0;
		}
		cout << "total: " << ver << endl;
	}
	void fun(int sum, int cursum, int &total, int i, int n){
		if(i > n) return;
		if(i == n && cursum == sum) total++;
		for(int j = 1; j <= 6; j++){
			if(cursum < sum){
				fun(sum, cursum+j, total, i+1, n);
			}
		}
	}
	void printProbability1(int n){
		vector<vector<int > > A(2, vector<int >(6*n+1, 0)); //��0��Ԫ�ز�ʹ��
		for(int i = 1; i <= 6; i++) A[0][i] = 1; //ֻ��һ�����ӣ�ÿ��ȡֵֻ��һ�����
		int index = 0; //����ʹ��
		for(int i = 2; i <= n; i++){
		    for(int j = 0; j < i; j++) //����С����������������Ϊ0
				A[1-index][j] = 0;
				
			for(int j = i; j <= 6*i; j++){
				A[1-index][j] = 0; //��0�����ۼӺ�
				for(int k = 1; k < j && k <= 6; k++)
					A[1-index][j] += A[index][j-k];
			}
			index = 1 - index;
		}
		double all = pow(6, n);
		int ver = 0;
		for(int i = n; i <= 6*n; i++){
			cout << "s = " << i << ": ";
			cout << A[index][i] << "/" << all << endl;
			ver += A[index][i];
		}
		cout << "total: " << ver << endl;
	}
    
};

int main()
{
	Solution c;
	c.printProbability(4);
	c.printProbability1(4);
	return 0;
}

