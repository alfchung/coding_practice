
/*
 * keys are unique
*/


#include<stdlib.h>
#include<stdint.h>

#include<iostream>
#include<string>
#include<map>
#include<vector>


using namespace std;

const int default_table_size = 100;

template <class Key, class Value>
class record {
	public:
		Key key;
		Value value;
		record* next;
};


template <class Key, class Value>
class hashtable {
	public: 
		hashtable()  {
			table.resize(default_table_size); //default table size
		}

		hashtable(int size) {
			table.resize(size); //default table size
		}

		void put(Key key, Value value) {

		}



		Value get( Key key );





	private:
		vector< record <Key, Value> > table;

};





int main() {
	return 0;
}


