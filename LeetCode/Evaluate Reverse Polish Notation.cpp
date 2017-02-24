#include<stack>
#include<iostream>
#include<sstream>
using namespace std;
class Solution {
public:
    int change(string aa) {
    	int val;
    	std::stringstream ss;
    	ss << aa;
    	ss >> val;
    	return val;
    }
    string change1(int a) {
    	string aa;
    	std::stringstream ss;
    	ss << a;
    	ss >> aa;
    	return aa;
    }
    int evalRPN(vector<string>& tokens) {
        stack<string> a;
	    vector<string>::iterator iter;
    	for (iter = tokens.begin(); iter != tokens.end(); iter++) {
    		if (*iter != "+" && *iter != "-" && *iter != "*" && *iter != "/") a.push(*iter);
	    	else if (*iter == "+") {
		    	string a1 = a.top();
			    a.pop();
    			string a2 = a.top();
	    		a.pop();
	    		int aa1 = change(a1);
	    		int aa2 = change(a2);
	    		int cc = aa1+aa2;
		    	string c = change1(cc);
			    a.push(c);
    		}
	    	else if (*iter == "-") {
		    	string a1 = a.top();
			    a.pop();
    			string a2 = a.top();
	    		a.pop();
	    		int aa1 = change(a1);
	    		int aa2 = change(a2);
	    		int cc = aa2-aa1;
		    	string c = change1(cc);
			    a.push(c);
		    }
    		else if (*iter == "*") {
	    		string a1 = a.top();
		    	a.pop();
			    string a2 = a.top();
    			a.pop();
	    		int aa1 = change(a1);
	    		int aa2 = change(a2);
	    		int cc = aa1*aa2;
		    	string c = change1(cc);
		    	a.push(c);
		    }
    		else if (*iter == "/") {
	    		string a1 = a.top();
		    	a.pop();
			    string a2 = a.top();
    			a.pop();
	       		int aa1 = change(a1);
	    		int aa2 = change(a2);
	    		int cc = aa2/aa1;
		    	string c = change1(cc);
		    	a.push(c);
		    }
	    }
    	string q = a.top();
	    int w = change(q);
	    return w;
    }
};
