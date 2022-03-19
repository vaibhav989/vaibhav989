// return (n & mask) > 0 ? 1 : 0;
// if result is 0 return 1 other wise 0

#include <iostream>
using namespace std;

int masking(int n, int i){

int mask=(1>>i);
return (n & mask)>0 ? 1 :0;
// is result is greater than 0 return 1 otherwise 0 
}

void ClearIthBit(int &n , int i){
	int masks=~(1<<i);
	n=n& masks;

}
int main(){
 int n=13;
 int i;
 cin>>i;

 //cout<<masking(n,i)<<endl;
 ClearIthBit(n,i);

 cout<<n<<endl;

 cout<<"Enjoy The Hustle !"<<endl;
}
