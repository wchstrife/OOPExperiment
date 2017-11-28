#include <iostream>
using namespace std;

class Integer {
private:
    int _num;
public:
//构造函数
    Integer(int num) {
		_num = num;
    }
//计算当前Integer 和 b之间的最大公约数
    int gcd(Integer b) {
		int b_num = b._num;

		int n = _num < b_num ? _num : b_num;
		while(n>=1){
			if(_num % n == 0 && b_num % n == 0){
				break;
			}
			n--;
		}

		return n;
		}
};


int main(){
    int a, b;
    cin >> a >> b;
    Integer A(a);
    Integer B(b);
    cout << A.gcd(B) << endl;
	system("pause");
    return 0;
}
