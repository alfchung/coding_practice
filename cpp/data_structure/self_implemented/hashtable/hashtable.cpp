
/*
 * keys are unique
*/


#include<stdlib.h>
#include<stdint.h>
#include<math.h>

#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<typeinfo>


using namespace std;

const int default_table_size = 277;

template <class Key, class Value>
class record {
	public:
		record() {
			empty = true;
		}

		Key key;
		Value value;
		record* next;
		bool empty;
};


template <class Key, class Value>
class hashtable {
	public: 
		hashtable()  {
			table_size = default_table_size;
			table.resize(default_table_size); //default table size
			for (int i=0; i<table_size; i++) {
				record<Key, Value> r;
				table.push_bash(r);
			}
		}

		hashtable(int size) {
			table_size = size;
			table.resize(size); //default table size
			for (int i=0; i<table_size; i++) {
				record<Key, Value> r;
				table.push_bash(r);
			}
		}

		void put(Key key, Value value) {
			int hashkey;
			int position;
				
			string type(typeid(Key).name);
			if (type.compare("int")==0 ) {
				//integer type
				hashkey = static_cast<int>(key);
			}
			else if (type.compare("string")==0 ) {
				//integer type
				hashkey = string2int( static_cast<string>(key) );
			}

			position = hash(hashkey);

			if (table[position].empty == true) {
				table[position].key = key;
				table[position].value = value;
				table[position].next = NULL;
				table[position].empty = false;
			} 
			else {  //not empty, need to compare key along the chain

				record<Key,Value> *pNext = &(table[position]);



				if (key == table[position].key ) {
					table[position].value = value;
				}
			}


		}



		Value get( Key key );

		int string2int(string s) {
			int ret = 0;
			int size = s.size();
			for (int i=0; i<size; i++) {
				ret += static_cast<int>(s[i]) * (i%10);
			}

			return ret;
		}

		int hash(int key) {
			return key%table_size;
		}





	private:
		int table_size;
		vector< record <Key, Value> > table;

};





int main() {
	return 0;
}


