
/*ideal:
 *
 *采用贪心的策略
 *    我们来匹配s和p
 *      如果匹配就s++, p++
 *      如果不匹配的话就看p之前是否有*
 *   我们对于*需要记录的，遇到*就记录当前*位置和匹配到的s的位置
 *   然后从*的下一位置匹配，开始匹配0个字符
 */

#include <iostream>
#include <string>
using namespace std;

bool isMatch(const char* s, const char* p)
{
    const char* last_s = NULL;
    const char* last_p = NULL;
    while (*s != '\0'){
        if (*p == '*'){
            //skip the "*", and mark a flag
            p++;
            if (*p == '\0') return true;
            last_p = p;
            last_s = s;
        }
        else if (*p == '?' || *s == *p){
            s++; p++;
        }
        else if (last_s != NULL) {
            //check "last_s" to known whether meet '*'
            s = ++last_s;
            p = last_p;
        }
        else {
            return false;
        }
    }
    
    //edge case: "s" is done, but "p" is still have chars
    while (*p == '*') p++;
    return *p == '\0';
}

int main(int argc, char* argv[])
{
    const char* s= "aab";
    const char* p= "a*a*b";
    cout << s << ", " << p << ":" << isMatch(s, p) << endl;
}
