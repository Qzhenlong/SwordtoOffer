#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
/*
��Ŀ���������е��������֣����ǰ��һ�����ִ��ں�������֣����������������һ������ԣ�����һ�����飬��������������Ե�����
	  �磺{7��5��6��4}��5������ԣ�{7,5},{7,6},{7,4},{5,4},{6,4}
˼·��
��1����ķ�������ÿ��ɨ�赱ǰԪ�غ�������Ԫ�أ��ҳ���������ԣ����Ӷ�ΪO(n^2)���ռ�O(1)
��2����ʱ�任�ռ䣬��һ�Ź�ϣ�����Ѵ������Ԫ������[i,j]��[i,j]��ʾ��iΪ��㣬��jΪֹ������Զ������ˣ����Ӷ�ΪO(nlogn)
��3������˼·��ʹ�ù鲢�����˼·���ֳ��ӱ���жԱȣ��Ե����Ͻ��й鲢��ÿ��ͳ��������Ե���������й鲢������ʵ�Ͼ��ǹ鲢����Ĺ���

*/
class Solution{
public:
	//˼·1�Ƚϼ򵥣��Ͳ�������ʵ���ˣ�ֱ�Ӵ�˼·��2����ʼ
	int PairsNum1(vector<int > A){
		int n = A.size(), ans = 0;
		if(n < 2) return 0;
		vector<int > index;
		for(int i = 0; i < n-1; i++) index.push_back(i); //��ʼ��
		for(int i = 0; i < n-1; i++){
			int k = index[i]+1; //ȥ����ɨ������
			//cout << i << " " << k << " " << ans << endl;
			int max = A[k];
			for(int j = k; j < n; j++){
				if(A[i] > A[j]) ans++;
				if(j > index[k]){ //ɨ��������䲻�öԱ���
					if(max > A[j]){
						ans++;
						index[k] = j;
					}
					else{
						max = A[j];
						k = j;
					}
				}
			}
		}
		return ans;
	}
    //˼·3:�鲢
	void merge(vector<int > &A, int low, int mid, int high, int &counter){
		vector<int > B;
		int i = low, j = mid+1;
		while(i <= mid && j <= high){
			if(A[i] > A[j]){
				B.push_back(A[j++]); // A[i,..,mid]����A[j]��
				counter += (mid-i+1);
			}
			else B.push_back(A[i++]);
		}
		while(i <= mid) B.push_back(A[i++]);
		while(j <= high) B.push_back(A[j++]);
		for(i = low, j = 0; j < B.size(); i++, j++) A[i] = B[j];
	}
	void mergeDC(vector<int > &A, int low, int high, int &counter){
		if(low < high){
			int mid = (low+high)/2;
			mergeDC(A, low, mid, counter);
			mergeDC(A, mid+1, high, counter);
			merge(A, low, mid, high, counter);
		}
	}
	int PairsNum2(vector<int > &A){
		int c = 0;
		mergeDC(A, 0, A.size()-1, c);
		return c;
	}
};

int main(){
	Solution c;
	int A[] = {7,5,6,4,0};
	vector<int > nums;
	for(int i = 0; i < sizeof(A)/4; i++) nums.push_back(A[i]);
	cout << c.PairsNum1(nums) << endl;
	cout << c.PairsNum2(nums) << endl;
	return 0;
}
