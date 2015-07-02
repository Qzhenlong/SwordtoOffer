#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
/*
��Ŀ��һ�����������г�����������֮�⣬�������ֶ����������Σ���д�����ҳ�����������һ�ε����֣�Ҫ��ʱ�临�Ӷ�O(n)���ռ临�Ӷ�O(1)
˼·��
��1�������Ҫ��ռ临�Ӷȣ�ʹ��һ�Ź�ϣ���¼�������ɣ��ռ��ʱ�䶼ΪO(n)
��2������O(1)�Ŀռ临�Ӷȣ�ע�⵽�������ֶ��������Σ����ȫ����������õ�������ͬ�������Ľ������ͬ�������Ϊ0������Ϊx
	 x�϶���Ϊ1�ı��أ����ݸñ��ؽ�ԭ������л��֣����ֺ��ʹ������ͬ�������벻ͬ���ϣ�����ͬ������Ȼ�����ͬ���ϣ���Ϊ��λΪ1����ͬ���ֱ�Ȼ�ڸ�λ��ͬʱΪ0��1��
	 ֻ��������ͬ�������ڸ�λ�ϲ�ͬ���õ�����������󣬷ֱ�����������Ԫ����򼴿ɵõ�������ͬ���֡�
*/
class Solution{
public:
	vector<int > getTwoDifNumbers(vector<int > nums){
		vector<int > ans(2, 0);
		int x = 0, bit = 0;
		for(int i = 0; i < nums.size(); i++) x ^= nums[i];
		for(bit = 0; bit < sizeof(x)*4; bit++)
			if(((x >> bit) & 0x01) > 0) break;
		for(int i = 0; i < nums.size(); i++){
			if(((nums[i] >> bit) & 0x01) > 0) ans[0] ^= nums[i];
			else ans[1] ^= nums[i];
		}
		return ans;
	}
};

int main(){
	Solution c;
	int A[] = {2,4,3,6,3,2,5,5};
	vector<int > nums;
	for(int i = 0; i < sizeof(A)/4; i++) nums.push_back(A[i]);
	vector<int > ans = c.getTwoDifNumbers(nums);
	cout << ans[0] << endl;
	cout << ans[1] << endl;
	return 0;
}
