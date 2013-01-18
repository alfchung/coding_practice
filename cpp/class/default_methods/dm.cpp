//default methods in a class
//default constructor, copy constructor, copy assignment operator, destructor


#include <iostream>

using namespace std;


class Apple {
	public:
		int price;
		int id;
		void display() {
			cout<<"Apple id "<<id<<"'s price is "<<price<<endl;

		}
};



int main() {
	Apple a0(); //default constructor
	Apple a1; //default constructor
	Apple a2(a1); //copy constructor
	Apple a3; //default constructor
	a3=a1; //copy assignment operator

	//a0.display();
	a1.display();
	a2.display();
	a3.display();

	a1.~Apple();
	a2.~Apple();
	a3.~Apple();

	return 0;
}

