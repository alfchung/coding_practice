
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

const int error_exit_wrong_key_type = -1;

const int put_status_insert_new = 0;
const int put_status_insert_overwritten = 1;
const int put_status_insert_fail = -1;

const int get_not_found = -1;
const int get_found = 0;

template <class Key, class Value>
class record {
	public:
		Key key;
		Value value;
		record* next;
		bool empty;
};


template <class Key, class Value>
class primary_record {
	public:
		primary_record() {
			empty       = true;
			record_root = NULL;
		}
		bool empty;
		record<Key, Value> *record_root;
};


template <class Key, class Value>
class hashtable {
	public: 
		hashtable()  {
			table_size = default_table_size;
			table.resize(default_table_size); //default table size
			for (int i=0; i<table_size; i++) {
				primary_record<Key, Value> pr;
				table.push_back(pr);
			}
		}

		hashtable(int size) {
			table_size = size;
			table.resize(size); //default table size
			for (int i=0; i<table_size; i++) {
				primary_record<Key, Value> pr;
				table.push_bash(pr);
			}
		}

		int put(Key key, Value value) {
			int hashkey;
			int position;
				
			hashkey = static_cast<int>(key);

			//hashkey = key;

			position = hash(hashkey);

			if (table[position].empty == true) {

				table[position].record_root = new record<Key, Value>;


				table[position].record_root->key = key;
				table[position].record_root->value = value;
				table[position].record_root->next = NULL;
				table[position].empty = false;
				return put_status_insert_new;
			} 

			record<Key,Value> *pRecord = table[position].record_root;
			record<Key,Value> *last;

			while (pRecord != NULL) {
				if (key == pRecord->key) {
					pRecord->value = value;
					return put_status_insert_overwritten;
				}
				last = pRecord;
				pRecord = pRecord->next;
			}

			//go through the chain, no dupliated keys found
			last->next  = new record<Key, Value>;
			last->next->key = key;
			last->next->value = value;
			return put_status_insert_new;


		}



		int get( Key key, Value *value ) {
			int hashkey;
			int position;
				
			hashkey = static_cast<int>(key);

			//hashkey = key;

			position = hash(hashkey);

			if (table[position].empty == true) {
				return get_not_found;
			} 

			record<Key,Value> *pRecord = table[position].record_root;

			while (pRecord != NULL) {
				if (key == pRecord->key) {
					*value = pRecord->value;
					return get_found;
				}
			}

			//go through the chain, no dupliated keys found
			return get_not_found;
		}


		int hash(int key) {
			return key%table_size;
		}





	private:
		int table_size;
		vector< primary_record <Key, Value> > table;

};


class hashable_string:public string {
	public: 
		hashable_string() {
		}

		hashable_string(string s) {
			str = s;
		}

		operator int() const {  
			int ret = 0;
			int size = str.size();
			for (int i=0; i<size; i++) {
				ret += static_cast<int>(str[i]) * (i%10);
			}

			return ret;
		}


		operator string() {  
			return str;
		}

		string to_string() {
			return str;
		}
		string str;
	private:
};



int main() {
	hashtable<int, int> ht;
	ht.put(2,20);
	ht.put(7,7);
	ht.put(3,3);
	ht.put(1,1);
	ht.put(8,8);
	ht.put(9,9);

	hashtable<hashable_string, string> ht2;
	hashable_string s1("Alfred");
	ht2.put(s1, "731 Lexington Ave");

	hashable_string s3("Wang");
	ht2.put(s3,"100 ABC drive");


	int ret1;
	if ( ht.get(3, &ret1) == get_found )
		cout<<"in ht,key 3 returns value "<<ret1<<endl;
	else
		cout<<"in ht,key 3 not found."<<endl;

	if ( ht.get(8, &ret1) == get_found )
		cout<<"in ht,key 8 returns value "<<ret1<<endl;
	else
		cout<<"in ht,key 8 not found."<<endl;


	if ( ht.get(99, &ret1) == get_found )
		cout<<"in ht,key 99 returns value "<<ret1<<endl;
	else
		cout<<"in ht,key 99 not found."<<endl;


	string ret2; 
	if ( ht2.get(s1, &ret2) == get_found )
		cout<<"in ht,key "<<(string)(s1)<<" returns value "<<ret2<<endl;
	else
		cout<<"in ht,key"<<s1.to_string()<<"  not found."<<endl;


	return 0;
}


