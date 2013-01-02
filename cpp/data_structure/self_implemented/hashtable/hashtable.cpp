
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

template <class Key, class Value>
class hashtable {
	public: 
		hashtable();
		hashtable(int size);
		void put( pair<Key, Value> record);
		Value get( Key key );

	private:
		vector<  pair<Key, Value>  > table;
};



int main() {
	return 0;
}


