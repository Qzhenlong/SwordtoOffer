#include<iostream>
#include<vector>
#include<map>
using namespace std;
/*
��Ŀ����������һ�����ֳ��ֵĴ������������һ�룬���ҳ�������֡�
˼·: 
��1���ù�ϣ���¼���ֳ��ֵĴ�����ʱ��Ϳռ临�Ӷȶ�ΪO(n)��
��2���Ľ�˼·(1)����ʵ�ϣ�����Ҫ�洢�������ֳ��ֵĴ�����ֻ��Ҫ����һ����������ֵ���ɣ���������������ϴε�������ͬ��
	�������1�������1��������Ϊ0����������֣���������ֵ��˼·��ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1)��
��3��ת�������n/2��������϶�Ϊ����һ������֣����ÿ��ŵ�Partition�ɿ��ٲ��ң�ʱ�临�Ӷ�ΪO(n),�ռ临�Ӷ�ΪO(1)��

*/
class Solution{
public:
	int find1(vector<int > nums){ //���涼��ʱ������ڳ��ִ�������һ�������,�����鲻Ϊ��
		map<int, int> c; //��ϣ���¼����
		for(int i = 0; i < nums.size(); i++) c[nums[i]]=0;
		for(int i = 0; i < nums.size(); i++) c[nums[i]]++;
		for(map<int, int>::iterator it = c.begin(); it != c.end(); it++)
			if(it->second > nums.size()/2) return it->first;
	}
	int find2(vector<int > nums){
		int c = 1, n = nums[0];
		for(int i = 1; i < nums.size(); i++){
			if(n == nums[i]) c++;
			else c--;
			if(c <= 0){
				n = nums[i];
				c = 1;
			}
		}
		return n;
	}
	int find3(vector<int > nums){
		int k = nums.size() >> 1;
		if(nums.size() <= 0) return nums[0];
		return findKth(nums, k); //�ٶ�����
	}
	int findKth(vector<int > A, int k){
		int low = 0, high = A.size()-1, n = A.size();
		int index = partition(A, low, high);
		while(index != (n-k)){ 
			if(index < (n-k)) low = index + 1;
			else high = index - 1;
			index = partition(A, low, high);
		}
		return A[index];
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
int main()
{	
	Solution c;
	vector<int > n;
	int A[] = {1};
	for(int i = 0; i < sizeof(A)/4; i++) n.push_back(A[i]);
	cout << c.find1(n) << endl;
	cout << c.find2(n) << endl;
	cout << c.find3(n) << endl;
	return 0;
}


	

 