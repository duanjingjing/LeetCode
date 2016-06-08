#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
using namespace std;

int lengthOfLastWord(string s) {
    size_t size = s.size();
    if(size == 0) return 0;

    int cnt=0, wordLen;
    for(int i=0; i<s.size(); i++){
        if(isalpha(s[i])){
            cnt++;
        }
        else{
            if(cnt>0) {
                wordLen=cnt;
            }
            cnt=0;
        }
    }
    return cnt>0?cnt:wordLen;
}

int main(int argc, char* argv[])
{
    string s="Hello World";
    cout << lengthOfLastWord(s)<<endl;
}
