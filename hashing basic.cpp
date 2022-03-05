#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

int main(){
// inserting in maps
	unordered_map<string, int> mapping;
	pair<string, int> p={"abc",1};
	mapping.insert(p);

	// another way
	mapping["def"]=2;

	// accesing in maps
	cout<<mapping.at("abc")<<endl;
	cout<<mapping["pqr"]<<endl;


	// check presence 
	if(mapping.count("abc")>0){
		cout<<"is present"<<endl;
	}

	if(mapping.count("mrw")>0){
		cout<<"is present"<<endl;
	}

	cout<<"size:-"<<mapping.size()<<endl;
	
}









