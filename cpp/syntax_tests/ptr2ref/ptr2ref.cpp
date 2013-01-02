

/* 
* pointer to a variable, and a pointer to one of the same varialbe's reference
* Are they pointing to the same address? 
* Answer: Yes
*/



#include <iostream>

using namespace std;

int main() {
	int a = 10;
	int *pa = &a;
	int &ra = a;
	int *pra = &ra;
	int *pra2 = &ra;
	cout<<"pa="<<pa<<endl;
	cout<<"pra="<<pra<<endl;
	cout<<"pra2="<<pra2<<endl;
	cout<<"pra==pa? "<<(pra==pa)<<endl;
	cout<<"pra2==pa? "<<(pra==pa)<<endl;
}


