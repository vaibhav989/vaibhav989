// count the number of ones in the solution

#include <iostream>
using namespace std;

int count_bits(int n){
	int cnt=0;

	while(n>0){
		int last_bits=(n& 1);
		cnt+=last_bits;

		n=n>>1;
	}
	return cnt;
}

int main(){
	int n;
	cin>>n;

	cout<<count_bits(n)<<endl;
}

// POWER OF TWO

/*#include <iostream>
using namespace std;

int main(){
    int n;
    cin>>n;

    if((n & (n-1))==0){
        cout<<"power of two"<<endl;
    }
    else{
        cout<<"Not Power of Two"<<endl;
    }
}
*/
