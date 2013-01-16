

#include <iostream>

using namespace std;

class A {
	void hello() {
		cout<<"hello 1"<<endl;
	}

	/*
	   not allowed
	{
		void hello() {
			cout<<"hello 2"<<endl;
		}
	}
	*/
	class B {
	};
};


class parent {
	public:
		void hello(){cout<<"hello from parent."<<endl;}
		void hello(int i){cout<<"hello "<<i<<endl;}
	int p;
};


class child: public parent {
	public:
		void hello(){cout<<"hello from child."<<endl;}
	int c;
};





int main() {
	A a;
	//B b;

	cout<<"sizeof(A)="<<sizeof(A)<<endl;


	{
		//override
		int a=0;
		int b=1;
		cout<<"a="<<a<<endl;
		cout<<"b="<<b<<endl;
	}



	child c;
	c.hello();

	c.c = 0;
	c.p = 1;

	cout<<c.p<<endl;
	cout<<c.c<<endl;
	c.parent::hello(100);

	return 0;
}

