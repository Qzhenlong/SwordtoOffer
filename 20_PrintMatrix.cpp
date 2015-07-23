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

ע���������п������в���ȣ���LeetCode�е�Spiral Matrixһ�⣬˼·ֻ�Ƕ������±߽缴��
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
	//����
    vector<int> spiralOrder(vector<vector<int > >& matrix) {
		vector<int > ans;
		if(matrix.size() == 0) return ans;
		int i = 0, j = 0, rlow = 0, clow = 0, m = matrix.size(), n = matrix[0].size();
		while(rlow < m && clow < n){
		    rlow++;                                        //�б߽�����
			while(j < n) ans.push_back(matrix[i][j++]);    //�����ϱ���
			--j; ++i; 									   //�����ظ�
			if(j < clow || i < rlow) break;                //���в���ȵľ��󣬿�����ǰ�����յ�
			while(i < m) ans.push_back(matrix[i++][j]);    //�����ұ���
			--i; --j;                                      //�����ظ�
			if(j < clow || i < rlow) break;                //���в���ȵľ��󣬿�����ǰ�����յ�
			while(j >= clow) ans.push_back(matrix[i][j--]);//�����±���
			++j; --i; 									   //�����ظ�
			while(i >= rlow) ans.push_back(matrix[i--][j]);//���������
			clow++; 									   //�б߽�����
			m--; n--;                     			       //ѹ���߽�
			i = rlow; j = clow; 						   //�������
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

