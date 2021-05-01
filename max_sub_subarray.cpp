//An implementation of the max_sub_array.py in c++.
#include <iostream>
#include <vector>
#include <array>
#include <climits>
using namespace std;

#define l 0
#define h 1
#define sum 2

array<int, 3> max_cross_sub(vector<int>& a, int lo, int mid, int hi) {
    array<int, 2> lft, ryt;
    int sm = 0;
    lft[1] = ryt[1] = INT_MIN;

    for(int i = mid; i >= lo; i--) {
        sm += a[i];
        if(sm > lft[sum-1]) {
            lft[1] = sm;
            lft[l] = i;
        }
    }
    sm = 0;

    for(int i = mid+1; i <= hi; i++) {
        sm += a[i];
        if(sm > ryt[1]) {
            ryt[1] = sm;
            ryt[l] = i;
        }
    }
    return array<int, 3>({lft[l], ryt[l], lft[1] + ryt[1]});
}

array<int, 3> max_sub(vector<int>& a, int lo, int hi) {
    if(hi == a.size()) hi--;

    if(lo == hi) return array<int, 3>({lo, hi, a[lo]});
    else {
        array<int, 3> lft, ryt, cross;

        int mid = (lo + hi) / 2;
        lft = max_sub(a, lo, mid);
        ryt = max_sub(a, mid+1, hi);
        cross = max_cross_sub(a, lo, mid, hi);

        if(lft[sum] >= ryt[sum] && lft[sum] >= cross[sum]) 
            return lft;
        else if(ryt[sum] >= lft[sum] && ryt[sum] >= cross[sum]) 
            return ryt;
        else 
            return cross;
    }
}

int main() {
    vector<int> ar;
    int n;
    cout << "Please enter the number of elements: ";
    cin >>n;
    for(int i = 0; i < n; i++) {
        int el;
        cout << "enter element #" << i+1 << ": ";
        cin >> el;
        ar.push_back(el);
    }
    array<int, 3> s = max_sub(ar, 0, ar.size());
    cout << "The maximum subarray: ";
    for(int i = s[0]; i <= s[1]; i++) {
        cout << ar[i] << '\t';
    }
    cout << '\n';
    return 0;
}
