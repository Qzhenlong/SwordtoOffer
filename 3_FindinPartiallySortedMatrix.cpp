#include<iostream>
#include<vector>
using namespace std;
/*
题目：在一个二维数组中，每一行按照从左到右递增的顺序排序，每一列按照从上到下递增的顺序排序。
请完成一个函数，输入这一个二维数组和一个整数，判断该数组中是否包含该整数。
思路：
1）每次都与右上角的数对比；
2）当与右上角的数相等时返回true;
3）当比右上角的数小时，去除最后列；
4）当比右上角的数大时，去除第一行；
5）重复以上过程，未找到时返回false。
*/
class Solution {
public:
	bool FindinMatrix(vector<vector<int > > matrix, int tar) {
		if(matrix.size() == 0) return false;
		int row = 0, col = matrix[0].size()-1;
		while(row < matrix.size() && col >= 0) { //每次都对比右上角的数
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
