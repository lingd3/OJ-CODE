class Solution {
public:
    //现将每对//里的内容切割出来，在用栈实现
    string simplifyPath(string p) {
        stack<string> s;
        string a = "";
        string b = "";
        int t = 0;
        for (int i = 0; i < p.size(); i++) {
            if (p[i] == '/' && t == 1) {
                s.push(a);
                a = "";
                t = 0;
            }
            else if (p[i] == '/') continue;
            else {
                a.push_back(p[i]);
                t = 1;
            }
        }
        if (a != "") s.push(a);
        
    //    while (!s.empty()) {
    //        cout << s.top() <<  " ";
    //        s.pop();
    //    }
    //    cout << endl;
        
        int count = 0;
        while (!s.empty()) {
            if (s.top() == ".") {
                s.pop();
            }
            else if (s.top() == "..") {
                count++;
                s.pop();
            }
            else if (count != 0) {
                while (count > 0 && !s.empty()) {
                    if (s.top() == ".") {
                        s.pop();
                        continue;
                    }
                    else if (s.top() == "..") {
                        count++;
                        s.pop();
                        continue;
                    }
                    if (s.empty()) break;
                    s.pop();
                    count--;
                }
            }
            else {
                b.insert(0, s.top());
                b.insert(0, 1, '/');
                s.pop();
            }
        }
        if (b == "") return "/";
        return b;
    }
};