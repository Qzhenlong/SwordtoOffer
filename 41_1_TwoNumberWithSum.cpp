#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
��Ŀ������һ�������������һ������s,�������в�����������ʹ�����ǵĺ�����Ϊs,����ж�Է���Ҫ������֣����һ�Լ��ɡ�
˼·��
��1�����û�пռ临�Ӷ�Ҫ�󣬿��Բ���һ�Ź�ϣ���洢(s-x, x), xΪ�����е����֣��������ɨ�裬����y = s-x�� ������ֶԼ��ɡ����÷�����������Ҳ�ɣ�
��2�����������ǵ����ģ���Ȼ�ռ���Ը��٣���������ָ��i,j���������������м�бƣ�������֮��С��sʱ��i++,����j--,ֱ���ҵ����

��أ�LeetCode�е�TwoSum
*/

class Solution{
public:
	vector<int > twoSum(vector<int > nums, int s){
		map<int, int> m;
		vector<int > ans;
		for(int i = 0; i < nums.size(); i++){
			if(m.find(nums[i]) == m.end()) m[s-nums[i]] = nums[i];
			else{
				ans.push_back(nums[i]);
				ans.push_back(m[nums[i]]);
				break;
			}
		}
		return ans;
	}
	vector<int > twoSum1(vector<int > nums, int s){
		vector<int > ans;
		int i = 0, j = nums.size()-1;
		while(i < j){
			int cur = nums[i]+nums[j];
			if(cur == s){
				ans.push_back(nums[i]);
				ans.push_back(nums[j]);
			}
			if(cur < s) i++;
			else j--;
		}
		return ans;
	}

};

int main()
{
	Solution c;
	int A[] = {1,2,3,4,5}, target=8;
	vector<int > num;
	for(int i = 0; i < sizeof(A)/4; i++)
		num.push_back(A[i]);
	vector<int > ans = c.twoSum(num, target);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}

