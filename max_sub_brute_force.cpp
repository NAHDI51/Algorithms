//implementation of max_sub_brute_force.py in c++.

#include <iostream>
#include <vector>
#include <array>
#include <climits>
using namespace std;

array<int, 3> max_sub(vector<int> a) {
    int hi_row, hi_total;
    hi_row = hi_total = INT_MIN;

    int st_indx_row, end_indx_row;
    int st_indx_tot, end_indx_tot;

    //rows will cover the stuffs during iteration.
    //totals will cover the stuffs after iteration.

    for(int i = 0; i < a.size(); i++) {
        int sum = 0;
        st_indx_row = i;
        hi_row = INT_MIN;
        for(int j = i; j < a.size(); j++) {
            sum += a[j];
            if(sum > hi_row) {
                hi_row = sum;
                end_indx_row = j;
            }
        }
        if(hi_row > hi_total) {
            //Read it like this: the universal highest is the highest of this row.
            hi_total = hi_row;
            st_indx_tot = st_indx_row;
            end_indx_tot = end_indx_row;
        }
    }
    return array<int, 3>({st_indx_tot, end_indx_tot, hi_total});
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
    array<int, 3> s = max_sub(ar);
    cout << "The maximum subarray: ";
    for(int i = s[0]; i <= s[1]; i++) {
        cout << ar[i] << '\t';
    }
    cout << '\n';
    return 0;
}