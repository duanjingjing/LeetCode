#include <iostream>
#include <string>
#include <vector>
using namespace std;

//双指针,动态维护一个区间。尾指针不断往后扫，当扫到有一个窗口包含了所有t的字符后,
//然后再收缩头指针， 直到不能再收缩为止。最后记录可能的情况中窗口最小的
string minWindow(string S, string T)
{
    //Start typing your C/C++ solution 
    if (S.size() == 0 || S.size() < T.size()) return "";
    int appearedCount[256];
    int expectedCount[256];
    memset(appearedCount, 0, sizeof(appearedCount));
    memset(expectedCount, 0, sizeof(expectedCount));

    for (int i=0; i<T.size(); i++)
    {
        expectedCount[T[i]]++;
    }

    int min_start = 0, minV = INT_MAX;
    int wid_start = 0;
    int appeared = 0;
    for (int wid_end = 0; wid_end < T.size(); wid_end++)
    {
        if (expectedCount[S[wid_end]] > 0)
        {
            appearedCount[s[wid_end]]++;
            if (appearedCount[s[wid_end]] <= expectedCount[s[wid_end]]){
                appeared++;
            }
        }

        if (appeared == T.size())
        {
            while (appearedCount[s[wid_start]] > expectedCount[s[wid_start]]
                    || expectedCount[s[wid_start]] == 0)
            {
                appearedCount[s[wid_start]]--;
                wid_start++;
            }

            if (minV > (wid_end - wid_start+1))
            {
                minV = wid_end - wid_start + 1;
                min_start = wid_start;
            }
        }
    }

    if (minV == INT_MAX) return "";
    return S.substr(min_start, minV);
 }
