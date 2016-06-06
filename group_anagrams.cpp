#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;

vector<vector<string> > anagrams(vector<string>& strs)
{
    vector<vector<string> > res;
    unordered_map<string, vector<int> > ht;

    for(int i=0; i<strs.size(); i++){
        string key = strs[i];
        sort(key.begin(), key.end());
        ht[key].push_back(i);
    }
    
    for(unordered_map<string, vector<int> >::iterator it=ht.begin(); it!=ht.end(); it++){
        vector<string> solution;
        for(int i=0; i<it->second.size(); i++){
            solution.push_back(strs[it->second[i]]);
        }   
        res.push_back(solution);
    }

    return res;
}

void printMatrix(vector<vector<string> >& strs)
{
    for(int i=0; i<strs.size(); i++){
        cout << "[";
        for(int j=0; j<strs[i].size(); j++){
            cout << " "<< strs[i][j];
        }
        cout << "]"<< endl;
    }
}

int main(int argc, char* argv[])
{
    const char* strs[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> str(strs, strs+6);
    for (int i=0; i<str.size(); i++){
        cout << strs[i] << " ";
    }
    cout << endl;
    vector<vector<string> >res = anagrams(str);
    printMatrix(res);
}
