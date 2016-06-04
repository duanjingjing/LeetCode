#include <iostream>
#include <string>
using namespace std;


string Multiply(const string& num, char ch)
{
    int n = ch -'0';
    string s;
    int carry = 0;
    for (int i=num.size()-1; i>=0; i--) {
        int res = (num[i]-'0') * n + carry;
        carry = res/10;
        s.insert(s.begin(), res%10+'0');
    }

    if (carry > 0){
        s.insert(s.begin(), carry+'0');
    }

    return s;
}

string strPlus(const string& num1, const string& num2)
{
    string s;
    int n1=num1.size()-1;
    int n2=num2.size()-1;
    int i, j;
    int carry=0;
    for(i=n1,j=n2; i>=0||j>=0; i--,j--) {
        int x1= (i>=0 ? num1[i]-'0':0);
        int x2= (j>=0 ? num2[j]-'0':0);
        int x=x1+x2+carry;
        carry=x/10;
        s.insert(s.begin(), x%10+'0');
    }
    if (carry> 0) {
        s.insert(s.begin(), carry+'0');
    }

    return s;
}

string multiply(string& num1, string& num2)
{
    if(num1.size() <= 0 || num2.size() <= 0) return "";

    int shift=0;
    string result="0";
    for(int i =num1.size()-1; i>=0; i--) {
        string s = Multiply(num2, num1[i]);
        for (int j=0; j<shift; j++){
            s.insert(s.end(), '0');
        }
        result = strPlus(result, s);
        shift++;
    }
    
    //check result if is zero
    if (result[0]=='0') return "0";
    return result;
}

int main(int argc, char* argv[])
{
    string s1="25";
    string s2="20";

    if (argc > 2) {
        s1=argv[1];
        s2=argv[2];
    }
    cout << s1 << "*" << s2 << "=" << multiply(s1, s2) << endl;
    return 0;
}
