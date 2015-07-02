#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
/*
��Ŀ��ͳ��һ�����������������г��ֵĴ�����
˼·��
��1����򵥵ķ�������ֱ�Ӷ���һ����ϣ����ͳ�ƴ������ռ��ʱ�临�Ӷ�ΪO(n)
��2��������Ŀ�е����������ģ�������ö��ֲ��ҵ�˼·���ռ临�Ӷȿɽ�ΪO(1),ʱ�临�ӶȽ�ΪO(logn)

ע����ʵ�Ͼ����ҵ�ĳ������k�����������г��ֵ�������ʼ�㣬��LeetCode�е�Search for A Range��ʵ��һ���ġ�
*/

class Solution{
public:
	//˼·(1)�Ƚϼ򵥣�ֱ��ʵ��˼·(2)
	int CalNumber(vector<int > nums, int target){
        vector<int > range(2, -1);
		int low = 0, high = nums.size()-1, mid;
		while(low <= high){
			mid = (low+high)/2;
			if(nums[mid] == target){
				range[0] = range[1] = mid;
				break;
			}
			if(nums[mid] < target) low = mid+1;
			else high = mid-1;
		}
		if(range[0] == -1) return 0; //���ҵ�һ��Ŀ��������λ�ã� �ٶԸ�λ�õ����߽��ж��ֲ��ң�ȷ�����½�
		int i = low, j = mid-1;
		while(i <= j){ //����[low,mid]��Ԫ��С�ڵ���Ŀ������
			int _mid = (i+j)/2;
			if(nums[_mid] == nums[mid]){
				range[0] = _mid;
				j = _mid-1;
			}
			else i = _mid+1;
		}
		i = mid+1; j = high;
		while(i <= j){ //����[mid,high]��Ԫ�ش��ڵ���Ŀ������
			int _mid = (i+j)/2;
			if(nums[_mid] == nums[mid]){
				range[1] = _mid;
				i = _mid+1;
			}
			else j = _mid-1;
		}
		return range[1]-range[0]+1;
	}

};

int main(){
    Solution c;
	vector<int > nums;
	int A[] = {1,2,3,3,3,3,3,3,4,5};
	for(int i = 0; i < sizeof(A)/4; i++) nums.push_back(A[i]);
	cout << c.CalNumber(nums, 3);
	return 0;
}
