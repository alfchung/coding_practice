


#include <iostream>

using namespace std;


class mem_test_p {
public:
	virtual void hello() {
		cout<<"hello from parent"<<endl;
	}


	int parent_id;
};


class mem_test_c:public mem_test_p {
public:
	void hello() {
		cout<<"hello from child"<<endl;
	}

	int child_id;
};

void display_mem(mem_test_p *p) {
	//display stack
	cout<<"stack: "<<endl;
	unsigned *stack;
	int i=0;
	for(stack=(unsigned*)p; *stack!=0; stack++) {
		cout<<i++<<"   "<<stack<<"   "<<*stack<<"("<<(unsigned*)stack<<")"<<endl;
	}
	cout<<i<<"   "<<stack<<"   "<<*stack<<"("<<(unsigned*)stack<<")"<<endl;
	cout<<endl;



	//display virtual table
	cout<<"virtual table: "<<endl;
	unsigned *vtable = (unsigned*)(p);
	unsigned *v_content;
	i=0;
	for (v_content = (unsigned*)(*vtable); *v_content != 0; v_content++) {
		if (i==0) {

			typedef void (mem_test_p::*hellptype)() ;

			void (mem_test_p::*hellop)();
			//hellop = &mem_test_p::hello;
			hellop = ((hellptype)((void*)*v_content))();
			//hellop = ( (void (mem_test_p::*)())  (*v_content) )();
			(p->*hellop)();


		}
		cout<<i++<<"   "<<v_content<<"   "<<*v_content<<endl;
	}
	cout<<i<<"   "<<v_content<<"   "<<*v_content<<endl;
	cout<<endl;
	

}



int main() {
	cout<<"sizeof(mem_test_p) = "<<sizeof(mem_test_p)<<endl;
	cout<<"sizeof(mem_test_c) = "<<sizeof(mem_test_c)<<endl;
	cout<<endl;

	mem_test_p p;
	mem_test_c c;


	p.parent_id = 100;
	c.child_id  = 200;


	cout<<"parent class"<<endl;
	display_mem(&p);
	cout<<"parent hello() address: "<< (&mem_test_p::hello)<<endl;
	cout<<endl;


	cout<<"child class"<<endl;
	display_mem(&c);
	cout<<"child hello() address: "<< (&mem_test_c::hello)<<endl;
	cout<<endl;


	void (mem_test_p::*hellop)();
	hellop = &mem_test_p::hello;
	(p.*hellop)();


	return 0;
}

