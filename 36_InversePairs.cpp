#include<iostream>
#include<vector>
#include<map>
#include<string>
using namespace std;
/*
题目：在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对，输入一个数组，求出这个数组逆序对的总数
	  如：{7，5，6，4}有5个逆序对，{7,5},{7,6},{7,4},{5,4},{6,4}
思路：
（1）最笨的方法就是每次扫描当前元素后面所有元素，找出所有逆序对，复杂度为O(n^2)，空间O(1)
（2）以时间换空间，用一张哈希表存放已处理过的元素区间[i,j]，[i,j]表示以i为起点，到j为止的逆序对都找完了，复杂度为O(nlogn)
（3）书中思路：使用归并排序的思路，分成子表进行对比，自底向上进行归并，每次统计完逆序对的数量后进行归并排序，事实上就是归并排序的过程

*/
class Solution{
public:
	//思路1比较简单，就不在这里实现了，直接从思路（2）开始
	int PairsNum1(vector<int > A){
		int n = A.size(), ans = 0;
		if(n < 2) return 0;
		vector<int > index;
		for(int i = 0; i < n-1; i++) index.push_back(i); //初始化
		for(int i = 0; i < n-1; i++){
			int k = index[i]+1; //去掉已扫描区间
			//cout << i << " " << k << " " << ans << endl;
			int max = A[k];
			for(int j = k; j < n; j++){
				if(A[i] > A[j]) ans++;
				if(j > index[k]){ //扫描过的区间不用对比了
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
    //思路3:归并
	void merge(vector<int > &A, int low, int mid, int high, int &counter){
		vector<int > B;
		int i = low, j = mid+1;
		while(i <= mid && j <= high){
			if(A[i] > A[j]){
				B.push_back(A[j++]); // A[i,..,mid]都比A[j]大
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
