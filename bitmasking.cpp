// return (n & mask) > 0 ? 1 : 0;
// if result is 0 return 1 other wise 0

#include <iostream>
using namespace std;

int masking(int n, int i){

int mask=(1>>i);
return (n & mask)>0 ? 1 :0;
// is result is greater than 0 return 1 otherwise 0 
}

int main(){
 int n=5;
 int i;
 cin>>i;

 cout<<masking(n,i)<<endl;
}
