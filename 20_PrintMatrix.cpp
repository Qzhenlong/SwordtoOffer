#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ������һ�����󣬰�����������˳ʱ���˳�����δ�ӡ��ÿ�����֣���
1 2 3
4 5 6
7 8 9
���Ϊ1 2 3 6 9 8 7 4 5
˼·����������ָ�룬һ����ָ��i��һ����ָ��j���������б߽磬��Ϊ��������б߽���ȣ�ֻ��Ҫ����low,up����ʼ��Ϊlow=0, up=matrix.size();
1��������ָ��j,��j�ߵ�ͷʱ��i��ʼ�ߣ���i����ͷʱ��j��ʼ�����ߣ�j�ߵ�ͷʱ��i��ʼ����
2��ÿ��j�ص��������ʱ�������б߽����м�ѹ����low++�� up--;
3) ֱ��low == up�� ��ӡ����
*/

class Solution{
public:
	void printMatrix(vector<vector<int > > nums){
		int i = 0, j = 0, low = 0, up = nums.size();
		while(low < up){
			while(j < up)
				cout << nums[i][j++] << " ";
			j--; i++; //����Խ�缰�ظ���ӡ
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
			//��ӡ��һȦ���������
			i = low;
			j = low;
		}
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

