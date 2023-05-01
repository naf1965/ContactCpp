/* contacts web microservice using mariaDB
 * By James Skon, Kenyon College, 2022
 */


#include <iostream>
#include <fstream>
#include <string>
#include <map>

#include "httplib.h"
#include "contactDB.h"
#include "contactEntry.h"
const int port = 5004;

using namespace std;

ofstream logfile; 

string jsonResults(vector<contactEntry> pbList) {
	string res = "{\"results\":[";
	for (int i = 0; i<pbList.size(); i++) {
		res += pbList[i].json();
		if (i < pbList.size()-1) {
			res +=",";
		}
	}
	res += "]}";
	return res;
}

int main() {
	httplib::Server svr;

  	contactDB ctdb; // Contact Book SQL Interface Object
  
  	vector<contactEntry> results;

  	svr.Get("/", [](const httplib::Request & /*req*/, httplib::Response &res) {
    	res.set_header("Access-Control-Allow-Origin","*");
    	res.set_content("Contact API", "text/plain");
  	});

  	svr.Get(R"(/contact/find)", [&](const httplib::Request& req, httplib::Response& res) {
    	res.set_header("Access-Control-Allow-Origin","*");

    	results = ctdb.find("");
    	string json = jsonResults(results);
    	res.set_content(json, "text/json");
    	res.status = 200;
  	});
  	  	
  	svr.Get(R"(/contact/find/(.*))", [&](const httplib::Request& req, httplib::Response& res) {
    	res.set_header("Access-Control-Allow-Origin","*");

    	string last = req.matches[1];
    	results = ctdb.find(last);
    	string json = jsonResults(results);
    	res.set_content(json, "text/json");
    	res.status = 200;
  	});
  	
  	svr.Get(R"(/contact/last/(.*))", [&](const httplib::Request& req, httplib::Response& res) {
    	res.set_header("Access-Control-Allow-Origin","*");

    	string last = req.matches[1];
    	results = ctdb.findByLast(last);
    	string json = jsonResults(results);
    	cout << "Last: " << json << endl;
    	res.set_content(json, "text/json");
    	res.status = 200;
  	});
  	
  	svr.Get(R"(/contact/first/(.*))", [&](const httplib::Request& req, httplib::Response& res) {
    	res.set_header("Access-Control-Allow-Origin","*");

    	string first = req.matches[1];
    	results = ctdb.findByFirst(first);
    	string json = jsonResults(results);
    	cout << "first: " << json << endl;
    	res.set_content(json, "text/json");
    	res.status = 200;
  	});  	

  	svr.Get(R"(/contact/type/(.*))", [&](const httplib::Request& req, httplib::Response& res) {
    	res.set_header("Access-Control-Allow-Origin","*");

    	string type = req.matches[1];
    	results = ctdb.findByType(type);
    	string json = jsonResults(results);
    	cout << "type: " << json << endl;
    	res.set_content(json, "text/json");
    	res.status = 200;
  	});  
  	
  	svr.Get(R"(/contact/add/(.*)/(.*)/(.*)/(.*))", [&](const httplib::Request& req, httplib::Response& res) {
    	res.set_header("Access-Control-Allow-Origin","*");

    	string first = req.matches[1];
    	string last = req.matches[2];
    	string phone = req.matches[3];
    	string type = req.matches[4];
    	ctdb.addEntry(first,last,phone,type);

    	res.set_content("{\"status\":\"success\"}", "text/json");
    	res.status = 200;
  	}); 	
 
   	svr.Get(R"(/contact/update/(.*)/(.*)/(.*)/(.*)/(.*))", [&](const httplib::Request& req, httplib::Response& res) {
    	res.set_header("Access-Control-Allow-Origin","*");

    	string ID = req.matches[1];
    	string first = req.matches[2];
    	string last = req.matches[3];
    	string phone = req.matches[4];
    	string type = req.matches[5];
    	ctdb.editEntry(ID,first,last,phone,type);

    	res.set_content("{\"status\":\"success\"}", "text/json");
    	res.status = 200;
  	}); 

  	svr.Get(R"(/contact/delete/(.*))", [&](const httplib::Request& req, httplib::Response& res) {
    	res.set_header("Access-Control-Allow-Origin","*");

    	string ID = req.matches[1];
		ctdb.deleteEntry(ID);
    	res.set_content("{\"status\":\"success\"}", "text/json");
    	res.status = 200;
  	});  
  	 
  	cout << "Server listening on port " << port << endl;
  	svr.listen("0.0.0.0", port);

}
