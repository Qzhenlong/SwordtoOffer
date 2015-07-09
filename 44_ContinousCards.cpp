#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ�����˿����������5���ƣ��ж��ǲ���һ��˳�ӣ�����һ�����ǲ����������˿���2-10Ϊ���ֱ���AΪ1��J-KΪ11��12��13�� ��С���ɿ�����������
˼·������С����Ϊ0�� ��ô�鵽��5���ƶ�Ӧһ�����飬����������ǰ����������֮��Ϊ1������˳��
	  �������һ��0����ô�������ֿ��԰�����Ϊ2������һ�ԣ����������0�����԰�����Ϊ2���������ԣ����߲�Ϊ3������һ�ԡ�
*/
class Solution{
public:
	bool isContinous(vector<int > nums){
		sort(nums.begin(), nums.end());
		int zero = 0;
		for(int i = 0; i < 2; i++)
			if(nums[i] == 0) zero++;
		for(int i = zero; i < nums.size()-1; i++){
			int div = nums[i+1]-nums[i];
			if(div > 3) return false; //��Ϊ3���ϣ���������˳��
			if(div == 0) return false; //��ͬ���֣���������˳��
			if(div == 3){
				if(zero < 2) return false;
				else zero = 0; //������������
			}
			if(div == 2){
				if(zero < 1) return false;
				else zero--; //����������1
			}
		}
		return true;
	}
	
};

int main(){
	Solution c;
	int A[] = {0, 0, 4, 6, 7};
	vector<int > nums;
	for(int i = 0; i < sizeof(A)/4; i++) nums.push_back(A[i]);
	cout << c.isContinous(nums);
	return 0;
}
