#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ����һ��������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ����Ϊ�������ת������һ����������������һ����ת�������СԪ�ء�
�磺����{1��2��3��4��5}����ת{3��4��5��1��2}������1.
��������LeetCode�е�Find Minimum in Rotated Sorted Array I��II��ͬ
˼·������������������ظ�ֵ���ǲ������ظ�ֵ��������ת����ΪA�������������£�
1.�������ظ�ֵ����������Ƚϼ򵥣��������ֲ��ҵ�˼��
��1��A[low] < A[high], ֱ�ӷ���A[low];
��2��A[low] > A[high] && A[low] < A[mid], ǰ�벿��������Сֵһ���ں�벿�֣�low = mid+1;
��3��A[low] > A[high] && A[low] > A[mid], ��벿��������Сֵһ����ǰ�벿�֣�high = mid;

2.�����ظ�ֵ�������������һ�㣬�ų��߽��������
��1��A[low] < A[high], ֱ�ӷ���A[low]��������ͬ��
��2��A[low] == A[mid], low++;
��3��A[high] == A[mid], high--;
��4��A[low] > A[high] && A[low] < A[mid], ǰ�벿��������Сֵһ���ں�벿�֣�low = mid+1;
��5��A[low] > A[high] && A[low] > A[mid], ��벿��������Сֵһ����ǰ�벿�֣�high = mid;

�����������ظ�ֵ�Ľⷨ���ݲ������ظ�ֵ�Ľⷨ��
*/
class Solution {
public:
	int findMinI(vector<int > nums){ //�������ظ�ֵ
		int low = 0, high = nums.size()-1, mid;
		//if(nums.size() <= 0) return NULL;
		if(nums.size() == 1 || nums[low] < nums[high]) return nums[0];
		while(low < high){
			mid = (high+low)/2;
			if(nums[low] < nums[high]) return nums[low];
			if(nums[low] < nums[mid]) low = mid+1;
			else high = mid;
		}
		return nums[low];
	}
	int findMinII(vector<int > nums){ //�����ظ�ֵ
		int low = 0, high = nums.size()-1, mid;
		//if(nums.size() <= 0) return NULL;
		if(nums.size() == 1 || nums[low] < nums[high]) return nums[0];
		while(low < high){
			mid = (low+high)/2;
			if(nums[low] < nums[high]) return nums[low];
			if(nums[low] == nums[mid]){ low++; continue;}
			if(nums[high] == nums[mid]){ high--; continue;}
			if(nums[low] < nums[mid]) low = mid+1;
			if(nums[low] > nums[mid]) high = mid;
		}
		return nums[low];
	}
};
int main(){
  Solution c;
  vector<int > n;
  int sn = 7;
  for(int i = 0; i < sn; i++)
  {
          //cout << (i+3)% sn << " ";
          // n.push_back((i+3)% sn);
           if(i != 5) n.push_back(0);
           else n.push_back(1);
           
  }
  for(int i = 0; i < n.size(); i++) cout << n[i] << " "; 
  cout << endl;
  cout << c.findMinI(n) << endl;
  return 0;
 }
  