#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compare(const Interval& lhs, const Interval& rhs)
{
    return lhs.start == rhs.start ? lhs.end < rhs.end : lhs.start < rhs.start;
}

vector<Interval> merge(vector<Interval>& intervals)
{
    vector<Interval> result;
    if(intervals.size() <= 0) return result;
    
    sort(intervals.begin(), intervals.end(), compare);
    for(int i=0; i<intervals.size(); i++){
       int size = result.size();
       if(size > 0 && intervals[i].start >= result[size-1].start && intervals[i].start <= result[size-1].end) {
           result[size-1].end = max(intervals[i].end, result[size-1].end);
       }
       else {
           result.push_back(intervals[i]);
       }
    }
    return result;
}

vector<Interval> insert(vector<Interval>& intervals, Interval newInterval)
{
    intervals.push_back(newInterval);
    return merge(intervals);
}

int main(int argc, char* argv[])
{
    Interval i1(1,3);
    Interval i2(6,9);
    Interval insert1(2,5);
    
    vector<Interval> intervals;
    intervals.push_back(i1);
    intervals.push_back(i2);

    vector<Interval> result=insert(intervals, insert1);
    for(int i=0; i<result.size(); i++){
        cout << "[" << result[i].start << "," << result[i].end << "]";
    }
    cout << endl;
}
