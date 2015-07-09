#include<iostream>
#include<vector>
using namespace std;
/*
��Ŀ��0,1,...,n-1��n�������ų�һ��ԲȦ��������0��ʼÿ�δ�ԲȦ��ɾ����m��������ԲȦ�����ʣ�µ�һ����

˼·��
��1����ķ�������ÿ��ȥ�������е�һ������ֱ��ʣ��һ�����֣����Ӷ�ΪO(n^2)
��2���ı����ݽṹ�����û�������洢��ÿɾ��һ�����Ҫ��m�������Ӷ�ΪO(mn)
��3��������ѧ�Ƶ����ƹ�ʽf(n,m) = [f(n-1,m)+m] % n, n > 1, f(1,m) = 0, (ֻ��һ�����֣������Ӷ�ΪO(n)
	a.��һ��ɾ��������Ϊk=(m-1)%n, ��ʣ��0,..,k-1, k+1,...n,
	b.�ڶ���ɾ����k+1��ʼ����ôk+1->0, k+2->1...ӳ���ϵΪp(x)=(x-k-1)%n, ��任Ϊ_p(x) = (x+k+1)%n;
	c.��f(n,m) = _p(f(n-1, m))= (f(n-1,m)+k+1)%n = [f(n-1,m)+(m-1)%n + 1] %n = [f(n-1,m)+m]%n
*/
class Solution{
public:
	int LastNumber(int n, int m){
		if(n < 1 || m < 1) return -1;
		int last = 0;
		for(int i = 2; i <= n; i++)
			last = (last+m) % i;
		return last;
	}
};

int main(){
	Solution c;
	for(int i = 3; i < 20; i++)
		cout << c.LastNumber(i, 3) << endl;
	return 0;
}
