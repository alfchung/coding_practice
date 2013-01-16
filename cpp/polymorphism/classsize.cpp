#include <iostream>

using namespace std;

class empty {
	
};

struct es {
};


class v1 {
	public:
		virtual void hello() {cout<<"hello"<<endl;};

};


class v2 {
	public:
		virtual void hello() {cout<<"hello"<<endl;};
		virtual void bye() {cout<<"bye"<<endl;};

};

class v3 :public v1 {
	private:
		int a;
};



int main() {
	cout<<"sizeof(empty struct) = "<<sizeof(es)<<endl;
	cout<<"sizeof(empty) = "<<sizeof(empty)<<endl;
	cout<<"sizeof(v1) = "<<sizeof(v1)<<endl;
	cout<<"sizeof(v2) = "<<sizeof(v2)<<endl;
	cout<<"sizeof(v3) = "<<sizeof(v3)<<endl;
	return 0;
}
