#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
��Ŀ������һ�������������һ������s����ӡ���к�Ϊs�������������У����ٰ�������������
˼·����������ָ��i,j��ȷ�����еķ�Χ��iָ����ʼλ�ã�jָ��j����һ��λ�ã�������������ֺ�С��s����j++,�������s,��i++,�ҵ���ȷ����洢����

��Ҫ�̶ȣ���
*/

class Solution{
public:
	vector<vector<int > > ContinusSum(vector<int > nums, int s){
		vector<vector<int > > ans;
		vector<int > cur;
		if(nums.size() < 2) return ans;
		int i = 0, j = i+1, sum = nums[i] + nums[j];
		while(i < j && j < nums.size()){
			if(sum == s){
				for(int k = i; k <= j; k++) cur.push_back(nums[k]);
				ans.push_back(cur);
				cur.clear();
			}
			if(sum < s) sum += nums[++j];
			else sum -= nums[i++];
		}
		return ans;
	}

};

int main()
{
	Solution c;
	int A[] = {1,2,3,4,5,6,7,8}, target=15;
	vector<int > num;
	for(int i = 0; i < sizeof(A)/4; i++)
		num.push_back(A[i]);
	vector<vector<int > > ans = c.ContinusSum(num, target);
	for(int i = 0; i < ans.size(); i++){
		for(int j = 0;j < ans[i].size(); j++)
				cout << ans[i][j] << " ";
		cout << endl;
	}
	return 0;
}

