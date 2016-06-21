#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

void split(const string& s, char delim, vector<string> &elems)
{
    stringstream ss(s);
    string item;
    while (getline(ss, item, delim)) {
        elems.push_back(item);
    }
    return ;
}

vector<string> split(const string& s, char delim)
{
    vector<string> elems;
    split(s, delim, elems);
    return elems;
}

string simplifyPath(string path)
{
    string result;
    vector<string> elems = split(path, '/');

    int ignore = 0;
    for(int i=elems.size()-1; i>=0; i--) {
        if(elems[i] == "" || elems[i] == ".") {
            continue;
        }

        if(elems[i] == "..") {
            ignore++;
            continue;
        }
        
        if(ignore>0) {
            ignore--;
            continue;
        }

        if(result.size() == 0) {
            result = "/" + elems[i];
        }
        else {
            result = "/" + elems[i] + result;
        }
    }

    return result.size() ? result : "/";
}

string Simplify_Path(string path) {
    string ret, curDir;
    vector<string> allDir;
    
    for(int i=0; i<path.size(); i++) {
        if(path[i] == '/') {
            if(curDir.empty()) {
                continue;
            }
            else if(curDir == ".") {
                curDir.clear();
                continue;
            }
            else if(curDir == "..") {
                if(!allDir.empty()) {
                    allDir.pop_back();
                }
                curDir.clear();
            }
            else {
                allDir.push_back(curDir);
                curDir.clear();
            }
        }
        else {
            curDir.push_back(path[i]);
        }
    }

    for(int i=0; i<allDir.size(); i++) 
        ret.append("/" + allDir[i]);

    if(ret.empty()) ret = "/";
    return ret;
}

int main(int argc, char* argv[])
{
    string path("/a/./b/../../c/");
    if(argc > 1) {
        path = argv[1];
    }

    cout << path << " : " << simplifyPath(path) << endl;
    cout << path << " : " << Simplify_Path(path) << endl;
}
