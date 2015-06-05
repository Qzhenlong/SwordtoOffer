#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ����һ����ά�����У�ÿһ�а��մ����ҵ�����˳������ÿһ�а��մ��ϵ��µ�����˳������
�����һ��������������һ����ά�����һ���������жϸ��������Ƿ������������
˼·��
1��ÿ�ζ������Ͻǵ����Աȣ�
2���������Ͻǵ������ʱ����true;
3���������Ͻǵ���Сʱ��ȥ������У�
4���������Ͻǵ�����ʱ��ȥ����һ�У�
5���ظ����Ϲ��̣�δ�ҵ�ʱ����false��
*/
class Solution {
public:
	bool FindinMatrix(vector<vector<int > > matrix, int tar) {
		if(matrix.size() == 0) return false;
		int row = 0, col = matrix[0].size()-1;
		while(row < matrix.size() && col >= 0) { //ÿ�ζ��Ա����Ͻǵ���
			if(matrix[row][col] == tar) return true;
			if(matrix[row][col] > tar) col--;
			else row++;
		}
		return false;
	}
};

int main() {
	Solution c;
	vector<vector<int > > matrix;
	int A[4][4] = {{1,2,8,9},{2,4,9,12},{4,7,10,13},{6,8,11,15}};
	vector<int > cur;
	for(int i = 0; i < 4; i++){
		for(int j = 0; j < 4; j++)
			cur.push_back(A[i][j]);
		matrix.push_back(cur);
		cur.clear();
	}
	cout << c.FindinMatrix(matrix, 0);
	return 0;
}
