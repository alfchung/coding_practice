

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
	cout<<"pa="<<pa<<endl;
	cout<<"pra="<<pra<<endl;
	cout<<"pra==pa? "<<(pra==pa)<<endl;
}


