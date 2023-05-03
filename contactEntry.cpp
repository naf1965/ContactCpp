#include "contactEntry.h"

contactEntry::contactEntry() {
}

contactEntry::contactEntry(sql::SQLString f, sql::SQLString l, sql::SQLString p, sql::SQLString t, sql::SQLString I, sql::SQLString e, sql::SQLString n) {
    first = f;
    last = l;
    phone = p;
    type = t;
    ID = I;
    email = e;
    nickname = n;
}

string contactEntry::text() {
    string result = ID + ". ";
    result += first + " ";
    result += last + " ";
    result += phone + " ";
    result += type;
    result+= email;
    result += nickname;
    return result;
}

string contactEntry::json() {
    string result = "{\"ID\":\"" + ID + "\",";
    result += "\"first\":\"" + first + "\",";
    result += "\"last\":\"" + last + "\",";
    result += "\"phone\":\"" + phone + "\",";
    result += "\"type\":\"" + type + "\"}";
    result += "\"email\":\"" + email + "\"}";
    result += "\"nickname\":\"" + nickname + "\"}";
    return result;
}
