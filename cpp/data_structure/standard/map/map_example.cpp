
#include <iostream>
#include <string>
#include <map>

using namespace std;


int main() {

	/* 
	* think about SQL
	* CREATE TABLE telephone_book1(name VARCHAR(10), phone_number VARCHAR(10));
	* INSERT INTO telephone_book1 values('Alfred', '123-456-7890');
	* INSERT INTO telephone_book1 values('Jack', '123-456-7891');
	* ...
	*/


	map<string, string> telephone_book1;

	//insert
	telephone_book1["Alfred"] = "123-456-7890"; //use the [] operator
	telephone_book1["Jack"] = "123-456-7891";
	telephone_book1["Mike"] = "123-456-7892";
	telephone_book1["Tom"] = "123-456-7893";
	telephone_book1.insert(pair<string,string>("Bob","123-456-7894")); //use insert method

	map<string,string>::iterator it;
	for(it = telephone_book1.begin(); it!=telephone_book1.end(); it++) {
		cout<<(*it).first<<": "<<(*it).second<<endl;
	}
	cout<<"-----"<<endl<<endl;

	//modification
	telephone_book1["Jack"] = "919-456-7891";
	//at can only used in modification, not insertion
	telephone_book1.at("Tom") = "919-456-7893";
	cout<<"after modification:"<<endl;
	for(it = telephone_book1.begin(); it!=telephone_book1.end(); it++) {
		cout<<(*it).first<<": "<<(*it).second<<endl;
	}
	cout<<"-----"<<endl<<endl;


	//find and erase
	cout<<"erase Mike:"<<endl;
	it = telephone_book1.find("Mike");
	telephone_book1.erase(it);
	for(it = telephone_book1.begin(); it!=telephone_book1.end(); it++) {
		cout<<(*it).first<<": "<<(*it).second<<endl;
	}
	cout<<"-----"<<endl<<endl;



	return 0;
}

