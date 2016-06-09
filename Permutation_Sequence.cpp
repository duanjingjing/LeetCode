#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*
 * 以n=4, k=9为例
 * 最高位可以取{1,2,3,4},而每个数重复3!=6次。所以第k=9个permutation的s[0]
 * 为{1,2,3,4}中的第9/6+1=2个数字s[0]=2
 *而对于以2开头的6歌数字而言,k=9是其中的第k'=9%(3!)=3个，而剩下的数字{1,3,4}的
 *重复周期为2!=2次，所以s[1]为{1,3,4}中的第k'/2!+1=2个,即s[1]=3
 *对于以23揩油的2个数字而言,k=9是其中的第k''=k'%(2!)=1个，剩下的数字{1,4}的重复周期为1!=1次，所以s[2]=1
 *
 *
 */

string getPermutation(int n, int k)
{
    string ret;
    vector<int> factorial(n, 1);
    vector<char> num(n, 1);

    for(int i=1; i<n; i++){
        factorial[i] = factorial[i-1]*i;
    }
    
    for(int i=0; i<n; i++){
        num[i] = (i+1)+'0';
    }

    k--;
    for(int i=n; i>=1; i--){
        int j=k/factorial[i-1];
        k %= factorial[i-1];
        result.push_back(num[j]);
        num.erase(num.begin()+j);
    }

    return result;
}

int main(int argc, char* argv[])
{
    cout << getPermutation(4, 9) << endl;
}
