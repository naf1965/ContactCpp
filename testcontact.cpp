/* Contacts console test program using mariaDB
 * By James Skon, Kenyon College, 2022
 */
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

#include "contactDB.h"
#include "contactEntry.h"


using namespace std;

int main(){
    contactDB ctdb;
    vector<contactEntry> results;
    string o;

    cout << "Contacts test program" << endl;

    cout << "Select an option (1-search first, 2-search last, 3-search type, 4-add, 5-edit, 6-delete, 7-end): ";
    cin >> o;

    while (o!="7") {
      if (o=="1") {
        cout << "Enter first name to find:";
        string firstMatch;
        getline(cin,firstMatch);

	results = ctdb.findByFirst(firstMatch);

        for (int i = 0; i<results.size(); i++) {
        	cout << results[i].text() << endl;
        }
      } else if (o=="2") {

        cout << "Enter last name to find:";
        string lastMatch;
        getline(cin,lastMatch);

        results = ctdb.findByLast(lastMatch);

        for (int i = 0; i<results.size(); i++) {
			cout << results[i].text() << endl;
        }
      } else if (o=="3") {
        cout << "Enter type to find:";
        string typeMatch;
        getline(cin,typeMatch);
        results = ctdb.findByType(typeMatch);

        for (int i = 0; i<results.size(); i++) {
			cout << results[i].text() << endl;
        }
      } else if (o=="4") {

        cout <<"Enter a first name to add: ";
        string first,last,phone,type;
        getline(cin,first);
        cout << "Enter a last name to add: ";
        getline(cin,last);
        cout << "Enter a phone number: ";
        getline(cin,phone);
        cout << "lastly, end a type: ";
        getline(cin,type);;

        ctdb.addEntry(first,last,phone,type);
        cout << "Entry added" << endl;

      } else if (o=="5") {
        string first,last,phone,type, IDnum;
        cout << "Leave blank to keep same."  << endl;
        cout << "Enter an ID number to edit: ";
        getline(cin,IDnum);
        contactEntry entry=ctdb.fetchEntry(IDnum);
        cout  << IDnum << endl;
        if (entry.ID.empty()) {
        	cout << "Entry with ID = " << IDnum << " not found!" << endl;
        } else {
        	cout << "Editing: " << entry.text() << endl;
        	cin.ignore();
        	cout << "Enter a new first name("+entry.first+"): ";
        	getline(cin,first);
        	if (first.size()>0) entry.first = first;

        	cout << "Enter a new last name("+entry.last+"): ";
        	getline(cin,last);
        	if (last.size()>0) entry.last = last;
        	
        	cout << "Enter a new phone number("+entry.phone+"): ";
        	getline(cin,phone);
        	if (phone.size()>0) entry.phone = phone;
        	
        	cout << "Enter a new type("+entry.type+"): ";
        	getline(cin,type);
        	if (type.size()>0) entry.type = type;
        	
        	ctdb.editEntry(entry.ID,entry.first,entry.last,entry.phone,entry.type);
        	cout << "Done!" << endl;
        }
      } else if (o=="6") {

        string IDnum;
        cout << "Enter an ID number to delete: ";
        getline(cin,IDnum);
        ctdb.deleteEntry(IDnum);
        cout << "Deleted!" << endl;
      }
      cout << "Select an option (1-search first, 2-search last, 3-search type, 4-add, 5-edit, 6-delete, 7-end): ";
      getline(cin,o);

    }
return 0;
}
