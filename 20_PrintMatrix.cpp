#include<iostream>
#include<vector>
using namespace std;
/*
题目：输入一个矩阵，按从外向里以顺时针的顺序依次打印出每个数字，如
1 2 3
4 5 6
7 8 9
输出为1 2 3 6 9 8 7 4 5
思路：定义两个指针，一个行指针i，一个列指针j，定义行列边界，因为矩阵的行列边界相等，只需要定义low,up。初始化为low=0, up=matrix.size();
1）先走列指针j,当j走到头时，i开始走，当i增到头时，j开始往回走，j走到头时，i开始往回
2）每次j回到出发起点时，将行列边界往中间压缩，low++， up--;
3) 直到low == up， 打印结束

注：矩阵还是有可能行列不相等，如LeetCode中的Spiral Matrix一题，思路只是定义上下边界即可
*/

class Solution{
public:
	void printMatrix(vector<vector<int > > nums){
		int i = 0, j = 0, low = 0, up = nums.size();
		while(low < up){
			while(j < up)
				cout << nums[i][j++] << " ";
			j--; i++; //避免越界及重复打印
			while(i < up)
				cout << nums[i++][j] << " ";
			i--; j--;
			while(j >= low)
				cout << nums[i][j--] << " ";
			j++; i--;
			if(j == low){
				low++;
				up--;
			}
			while(i >= low)
				cout<< nums[i--][j] << " ";
			//打印完一圈，重置起点
			i = low;
			j = low;
		}
	}
	//补充
    vector<int> spiralOrder(vector<vector<int > >& matrix) {
		vector<int > ans;
		if(matrix.size() == 0) return ans;
		int i = 0, j = 0, rlow = 0, clow = 0, m = matrix.size(), n = matrix[0].size();
		while(rlow < m && clow < n){
		    rlow++;                                        //行边界增大
			while(j < n) ans.push_back(matrix[i][j++]);    //先走上边沿
			--j; ++i; 									   //避免重复
			if(j < clow || i < rlow) break;                //行列不相等的矩阵，可能提前到达终点
			while(i < m) ans.push_back(matrix[i++][j]);    //再走右边沿
			--i; --j;                                      //避免重复
			if(j < clow || i < rlow) break;                //行列不相等的矩阵，可能提前到达终点
			while(j >= clow) ans.push_back(matrix[i][j--]);//再走下边沿
			++j; --i; 									   //避免重复
			while(i >= rlow) ans.push_back(matrix[i--][j]);//再走左边沿
			clow++; 									   //列边界增加
			m--; n--;                     			       //压缩边界
			i = rlow; j = clow; 						   //重置起点
		}
		return ans;
    }
};
int main()
{
  Solution c;
  vector<vector<int > > n;
  vector<int > cur;
  for(int i = 0; i < 9; i++){
	cur.push_back(i+1);
	if((i+1) % 3 == 0){
		n.push_back(cur);
		cur.clear();
	}
  }
  c.printMatrix(n);
  n.clear(); cout << endl;
   for(int i = 0; i < 16; i++){
	cur.push_back(i+1);
	if((i+1) % 4 == 0){
		n.push_back(cur);
		cur.clear();
	}
  }
  c.printMatrix(n);
  return 1;   
}

