// return (n & mask) > 0 ? 1 : 0;
// if result is 0 return 1 other wise 0

#include <iostream>
using namespace std;

int masking(int n, int i){

int mask=(1>>i);
return (n & mask)>0 ? 1 :0;
// is result is greater than 0 return 1 otherwise 0 
}

void ClearIthBit(int &n , int i , int j){
	int masks=~(1<<i);
	n=n& masks;

}

void setIthBit(int &n ,int i){
	int mask=~(1<<i);
	n=n | mask;
}
// clearing bits in range 

void ClearBitsInRange(int &n ,int i, int j){
	int a= ~0<<(j+1);
	int b= (1<<i)-1;
	int mask=a|b;
	n=n & mask;
}

int main(){
 int n=31;
 int i=1;
 int j=3;

 //cout<<masking(n,i)<<endl;
 //ClearIthBit(n,i);
 //setIthBit(n,i);
 ClearBitsInRange(n,i,j);
 cout<<n<<endl;

 cout<<"Enjoy The Hustle !"<<endl;
}


/*
POWER OF 2 QUESTION
#include <iostream>
using namespace std;

int main(){
	int n;
	cin>>n;

	if(( n & (n-1))==0){
		cout<<"power of two"<<endl;
	}
	else{
		cout<<"not power of two"<<endl;
	}
	return 0;
}
*/
