#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <stdlib.h>
using namespace std;

string vecToStr(const vector<int>& data)
{
    stringstream ss;
    for (vector<int>::size_type idx = 0; idx != data.size(); idx++)
    {
        ss << data[idx];
    }
    return ss.str();
}

vector<int> getNext(const vector<int>& data)
{
    vector<int> ret;
    int val=0, cnt=0;

    for(int idx = 0; idx != data.size(); idx++)
    {
        if(idx == 0)
        {
            val=data[idx];
            cnt=1;
            continue;
        }

        if (data[idx] == val)
        {
            cnt++;
        }
        else
        {
            ret.push_back(cnt);
            ret.push_back(val);
            cnt = 1;
            val = data[idx];
        }
    }

    if (cnt > 0 && val >0)
    {
        ret.push_back(cnt);
        ret.push_back(val);
    }

    return ret;
}

string countAndSay(int n)
{
    if (n == 0) return "";
    if (n == 1) return "1";

    vector<int> num;
    num.push_back(1);
    for (int i = 1; i <=n-1; i++)
    {
        num = getNext(num);
    }

    return vecToStr(num);
}

int main(int argc, char* argv[])
{
    if (argc < 2)
    {
        cout << "argument num less than 2!!" << endl;
        exit(-1);
    }

    cout << countAndSay(atoi(argv[1])) << endl;
}
