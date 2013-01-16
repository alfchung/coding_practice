#include <iostream>
#include <string>


using namespace std;

typedef void (*funchandler)();

void register_func(funchandler f)
{
	cout << "register_func" << endl;
	(*f)();
}

class A
{
	public:
		A() : _val( 0 ) { cout << "create A..." << endl; }
		void test() { cout << "test..." << endl; }
		void test1() { cout << "test1..." << endl; }
		void test2() { cout << "test2..." << endl; }
		int val() { return _val; }
		static void test3() { cout << "test3..." << endl; }
		int _val;

	private:

};

int main()
{
	A a;
	int ( A::*p_val ) = 0;
	p_val = &A::_val;
	cout << "a.*p_val: " << a.*p_val << endl;

	void (A::*p_func)();
	p_func = &A::test;
	a.test();
	(a.*p_func)();
	p_func = &A::test1;
	( a.*p_func )();
	p_func = &A::test2;
	( a.*p_func )();

	void (* pp_func)();
	pp_func = &A::test3;
	(*pp_func)();

	register_func( pp_func );
	return 0;
}

