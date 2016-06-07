#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval(): start(0), end(0) {}
    Interval(int s, int e) :start(s), end(e) {}
};

//two factors sorting [start:end]
bool compare(const Interval& lhs, const Interval& rhs) 
{
    return (lhs.start == rhs.start) ? lhs.end < rhs.end : lhs.start < rhs.start;
}

vector<Interval> merge(vector<Interval>& intervals)
{
    vector<Interval> result;
    if(intervals.size() <= 0) return result;

    sort(intervals.begin(), intervals.end(), compare);

    for(int i=0; i<intervals.size(); i++){
        int size=result.size();
        if(size > 0 && result[size-1].end>intervals[i].start) {
            result[size-1].end=max(intervals[i].end, result[size-1].end);
        } else {
            result.push_back(intervals[i]);
        }
    }
    return result;
}


int main(int argc, char* argv[])
{
    Interval i1(1,3);
    Interval i2(2,6);
    Interval i3(8,10);
    Interval i4(15,18);

    vector<Interval> intervals;
    intervals.push_back(i1);
    intervals.push_back(i2);
    intervals.push_back(i3);
    intervals.push_back(i4);

    vector<Interval> r = merge(intervals);
    for(int i=0; i<r.size(); i++){
        cout << "[" << r[i].start <<"," << r[i].end << "]";
    }
    cout << endl;
}
