#include <iostream>
#include <string>
using namespace std;

string addBinary(string a, string b)
{
    int sizeA = a.size(), sizeB = b.size();
    int carry=0, i, j;
    string res;
    for(i=sizeA-1, j=sizeB-1; i>=0 && j>=0; i--, j--) {
        int sum = (a[i]-'0') + (b[j]-'0') + carry;
        carry = sum/2;
        res.insert(res.begin(), sum%2+'0');
    }

    for(int k=i; k>=0; k--) {
        if(carry>0) {
            int sum= a[k]-'0'+carry;
            carry=sum/2;
            res.insert(res.begin(), sum%2+'0');
        }
        else res.insert(res.begin(), a[k]);
    }
    
    for(int k=j; k>=0; k--) {
        if(carry>0) {
            int sum=b[k]-'0'+carry;
            carry=sum/2;
            res.insert(res.begin(), sum%2+'0');
        }
        else res.insert(res.begin(), b[k]);
    }

    if(carry>0) {
        res.insert(res.begin(), carry+'0');
    }
    return res;
}

int main()
{
    cout << addBinary("11", "1") << endl;
    cout << addBinary("0", "0") << endl;
}
