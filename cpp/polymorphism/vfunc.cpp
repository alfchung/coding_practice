

#define VIR 

#include <iostream>
#include <string>

using namespace std;



class parent {
	public:
		parent(string name) {
			this->name = name;
		}
#ifdef VIR
		virtual void hello() {
#else	
		void hello() {
#endif
			cout<<"hello from "<<name<<endl;
		}

		virtual void display() {
			cout<<"this at "<<this<<endl;
			cout<<"parent.name at "<<&name<<endl;
			cout<<"parent.name offset "<<(int*)&name-(int*)this<<endl;
			cout<<endl;
		}

	private:
		string name;
};

class child1:public parent {
	public: 
		//in child constructor, if not specified a parent constructor, the default parent constructor with no arguments will be called !!!
		//if the default constructor is not declared while a constructor with arguments are declared, it will report error !!!
		child1(string name) : parent(name+"'s parent") {
			this->name = name;
		}

		void hello() {
			cout<<"hello from "<<name<<endl;
		}


		void display() {

			cout<<endl;
			int *cp;
			int i = 0;
			for (cp = (int*)this; *cp!=0; cp++) {
				cout<<i++<<" "<<(*cp)<<endl;
			}
			cout<<endl;


			cout<<"this at "<<this<<endl;
			cout<<"child.name at "<<&name<<endl;
			cout<<"child.name offset "<<(int*)&name-(int*)this<<endl;
			cout<<"child's "<<endl;
			parent::display();
		}

	private:
		string name; // this is override of the parent's name !!!
};

//this is pass by value (copy)
//when passed a child in, it drops all addition to its parent part
//therefore, only parent version say hello get called
void say_hello(parent foo) {
	foo.hello();
}


void say_hello_ref(parent &foo) {
	foo.hello();
}


ostream& operator<<(ostream &o, parent &c) {
	cout<<"class address: "<<&c<<endl;
	cout<<endl;

	cout<<"virtual table:"<<endl;
	unsigned *vptr = NULL;
	int i=0;
	for (vptr= (unsigned*)*((unsigned*)&c); *vptr!=0; vptr++) {
		cout<<i++<<" "<<*vptr<<endl;
	}

	c.display();

	cout<<endl;
}



int main() {
	cout<<endl;
	parent p("parent");
	child1 c("child");

	//this is static binding, the compiler can easily know where hello to call
	cout<<"Static binding, parent and child just call their own functions"<<endl;
	p.hello();
	c.hello();
	cout<<endl;

	cout<<"calling parent's method from a child"<<endl;
	c.parent::hello();
	cout<<endl;

	cout<<"Parents or children object are passed by value, only parent portion is copied and passed to the function, so only parent version method get called."<<endl;
	say_hello(p);
	say_hello(c);
	cout<<endl;

	cout<<"Passed by reference, even a reference to parent type will not lose information in a child object, so it calls its actual type."<<endl;
	say_hello_ref(p);
	say_hello_ref(c);
	cout<<endl;


	cout<<"parent pointer call parent or child methods"<<endl;
	parent *pp = &p;
	pp->hello();
	pp = &c;
	pp->hello();
	cout<<endl;
	cout<<endl;
	cout<<endl;


	cout<<"Class memory explore"<<endl;
	cout<<"object c"<<endl;
	cout<<c<<endl;
	cout<<endl;

	cout<<"sizeof(parent)="<<sizeof(parent)<<endl;
	cout<<"sizeof(child1)="<<sizeof(child1)<<endl;


	return 0;



}



