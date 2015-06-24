#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ������n���������ҳ�������С��k��������������4��5��1��6��2��7��3��8��8����������С��4����Ϊ1��2��3��4
˼·��
��1��ֱ��ѡ������˼�룬ÿ�β�����СԪ�أ�ʱ�临�Ӷ�O(kn)
��2�����ǿ���˼�룬��ϲ��ҵ�k��Ԫ�ص�˼·���ɵ���Сk��Ԫ��,���Ӷ�O(n)
��3�����Ϸ���������һ����СΪk��������������Сk��Ԫ�أ�˼·�루1�����ƣ������ǽ���ǰԪ���������е����ֵ���жԱȣ�������ö������洢������Ҹ��Ӷ�ΪO(logk),
	�ܸ��ӶȿɴﵽO(nlogk)��
*/

class Solution{
public:
	//˼·1�Ƚϼ򵥣�ֱ��ʵ��˼·2�����Ӷ�O(n)
	vector<int > getKelements(vector<int > nums, int k){
		vector<int > ans;
		int low = 0, high = nums.size()-1;
		int index = partition(nums, low, high);
		while(index != k-1){
			if(index > k-1) high = index - 1;
			else low = index + 1;
			index = partition(nums, low, high);
		}
		for(int i = 0; i <= index; i++) ans.push_back(nums[i]);
		return ans;
	}
	int partition(vector<int > &A, int low, int high){
		int i = low, j = high;
		if(low < high){
			int tmp = A[i];
			while(i != j){
				while(i < j && tmp <= A[j]) j--;
				A[i] = A[j];
				while(i < j && tmp > A[i]) i++;
				A[j] = A[i];
			}
			A[i] = tmp;
		}
		return i;
	}
	
};

int main(){
	Solution c;
	vector<int > n;
	int A[] = {4,5,1,6,2,7,3,8};
	for(int i = 0; i < sizeof(A)/4; i++) n.push_back(A[i]);
	vector<int > ans = c.getKelements(n, 4);
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";
	return 0;
}
