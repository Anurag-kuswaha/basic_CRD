#include <iostream>
#include<fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct JSON {  //JSON object contains the name and the age of a person.
	string name;
	int age;
};

static int a = 7;                                       // used for polynomial hashing
#define MOD 1000000                                    //max value of polynomial function
#define CAPACITY 1000                                 //defining the capacity of the data storage of our array;
vector<pair<string, JSON>> STORAGE[CAPACITY];        //using hashing with chaining for storing the data

class CRD {
   private:
	    string key;                      // key is of string type
	    JSON value;                     // value is of JSON type which i have created as struct type
		void create();
		void read();
		void delete_();
		int count;
   public: 
		void operations(); 
};

///------------------------main function------------------------------///
int main() {
	CRD object;                            //creating the object of CRD class
	object.operations();                  // calling the operations function in the main function
}


// -----------function to check whether age is integer or not------------//
pair<bool,int> check_digit(string age) {  
	int age_ = 0;
	for (int i = 0;i < age.size();i++) {
		if ('0' <= age[i] && age[i] <= '9') {
			age_ = age_ * 10 + (age[i] - '0');
		}
		else return { 0,-1 };
	}
	return { 1,age_ };
}

///---------------------------user opeartion -----------------------///

void CRD::operations() {

	while (true) {
		cout << " select the option\n press 1 : create\n press 2 : read\n press 3 : delete\n press 4 : clear the screen\n";
		cout << " press 5 : input the file to initialise(must be 'input.txt' name)\n press 6 : exit \n";
		string option_; cin >> option_;
		if (check_digit(option_).first == 0) cout << " wrong input, input must be integer type, try again \n";
		else {
			       int option = check_digit(option_).second;
			       if (option == 1) {

				           cout << " Enter the key \n";
				           cin >> key;
				           cout << " Enter the name \n";
				           cin >> value.name;
				           cout << " Enter the age\n";
				           string age_;
				           while (1) {
				        	        cin >> age_;
					                if (check_digit(age_).first) { value.age = check_digit(age_).second; break; }
					                else cout << " wrong input, input must be integer, please try again \n";
				           }
				           create();
			       }
			       else if (option == 2) {
				           cout << " Enter the key that you want to read\n";
			               cin >> key;
				           read();  //calling the private read function to read the data
 
			       }
			      else if (option == 3) {
				           cout << " Enter the key that you want to delete\n";
				           cin >> key;
				           delete_();   //calling the private delete_ function to delete the data if exist
			      }
			      else if (option == 4)   system("cls");      // purpose is to clean the screen 
			      else if (option == 5) {
				          ifstream in("input.txt");
				          count = 0;
				          string age_;
				          while (in >> key && in >> value.name && in >> age_) {
					                if (check_digit(age_).first) value.age = check_digit(age_).second;
					                else {
						            cout << " oops ! u have chossen the wrong file try to add the working file \n";
						            break;
					                }
					               create();
				          }
				          cout << "\n total " << count << " data added successfully \n";
			      }
			      else if (option == 6) {
				          cout << " abort successfully \n";  //if user input anything other than what mentioned above then close;
				          exit(1);
			      }
			      else cout << " oops! belive us, you made the wrong choice try input the valid option \n";
			   
				  cout << "\n\n";
		}
	}
}


///-----------calculating the hash value of the string(key) using polynomial hashing------///

int hash_value(string s) {
	int size = s.size();                  //size of the string
	int hash = 0;                        //stores the hash vale of the string s
	for (int i = size-1;i >= 0;i--) {
		hash = ((hash*a + (s[i] )) % MOD) % CAPACITY; ///taking the ASCII value of char of string to calculate hash value.
	}
	return hash;
}

///---------------------------CREATE opeartion -----------------------///

void CRD::create() {
	
	int hash = hash_value(key);
	vector<pair<string, JSON>>& cell = STORAGE[hash];    //going over that particular index of an array;
	auto i = begin(cell);
	bool key_present = false;
	for (;i != cell.end();i++) {
		if (key == (*i).first)
			key_present = true;   //key already present;
	}
	if (!key_present) {

		STORAGE[hash].push_back({ key,{value.name,value.age} });   //if key not presnt already then add at the end ;
		cout <<"\n "<<key<<" added successfully  \n";
		count++;
	}
	else       cout << "\n oops! Data already exist \n";

}

///---------------------------READ opeartion -----------------------///

void CRD::read() {
	int hash = hash_value(key);
	vector<pair<string, JSON>>& cell = STORAGE[hash];    //going over that particular index of an array;
	auto i = begin(cell);
	bool found = false;
	for (;i != cell.end();i++) {
		if ((*i).first == key) {  //key found;
			cout << " name of the person is : " << ((*i).second).name << '\n';
			cout << " age is                : " << ((*i).second).age << '\n';
			found = true;
		}
	}
	if (!found) {
		//if not found;
		cout << " oops! there is no such directory exist in the library \n";
	}

}

///---------------------------DELETE opeartion -----------------------///

void CRD::delete_() {
	int hash = hash_value(key);
	vector<pair<string, JSON>>& cell = STORAGE[hash];    //going over that particular index of an array;
	auto i = begin(cell);
	bool found = false;
	for (;i != cell.end();i++) {
		if ((*i).first == key) {  //key found;
			cell.erase(i);
			found = true;
			break;
		}
	}
	if (!found) {
		//if not found;
		cout << " oops! there is no such directory exist in the library \n";
	}
	else     cout << "\n " << key << " deleted successfully\n";
}
