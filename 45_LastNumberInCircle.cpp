#include<iostream>
#include<vector>
using namespace std;
/*
题目：0,1,...,n-1这n个数字排成一个圆圈，从数字0开始每次从圆圈中删除第m个数，求圆圈中最后剩下的一个数

思路：
（1）最笨的方法就是每次去掉数组中的一个数，直到剩下一个数字，复杂度为O(n^2)
（2）改变数据结构，利用环形链表存储，每删除一个结点要走m步，复杂度为O(mn)
（3）利用数学推导递推公式f(n,m) = [f(n-1,m)+m] % n, n > 1, f(1,m) = 0, (只有一个数字），复杂度为O(n)
	a.第一个删除的数字为k=(m-1)%n, 则剩余0,..,k-1, k+1,...n,
	b.第二次删除从k+1开始，那么k+1->0, k+2->1...映射关系为p(x)=(x-k-1)%n, 逆变换为_p(x) = (x+k+1)%n;
	c.则f(n,m) = _p(f(n-1, m))= (f(n-1,m)+k+1)%n = [f(n-1,m)+(m-1)%n + 1] %n = [f(n-1,m)+m]%n
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
