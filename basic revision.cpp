// update the value of array by refrance 

#include <iostream>
using namespace std;

void updatearr(int arr[],int i,int val){
	arr[i]=val;

}


int main(){
	int arr[]={10,20,23,43,50};
	int n=sizeof(arr)/sizeof(int);

  // pass by value in arr

	updatearr(arr,1,13);

	for(int i=0;i<n;i++){
		cout<<arr[i]<<endl;
	}
}
