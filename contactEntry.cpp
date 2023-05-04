#include "contactEntry.h"

contactEntry::contactEntry() {
}

// added last two variables
contactEntry::contactEntry(sql::SQLString f, sql::SQLString l, sql::SQLString p, sql::SQLString t, sql::SQLString I, sql::SQLString e, sql::SQLString a) {
    first = f;
    last = l;
    phone = p;
    type = t;
    ID = I;
    email = e;
    age = a;
}

// added last two
string contactEntry::text() {
	string result = ID + ". ";
	result += first + " ";
	result += last + " ";
	result += phone + " ";
	result += type + " ";
	result += email + " ";
	result += age;
	return result;

}

// added last two
string contactEntry::json() {
	string result = "{\"ID\":\"" + ID + "\",";
	result += "\"first\":\"" + first + "\",";
	result += "\"last\":\"" + last + "\",";
	result += "\"phone\":\"" + phone + "\",";
	result += "\"type\":\"" + type + "\",";
	result += "\"email\":\"" + email + "\",";
	result += "\"age\":\"" + age + "\"}";
	return result;

}
