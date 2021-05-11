#include <iostream>
#include <vector>
using namespace std;

int twoPointers(vector<int> a, int target) {
    int i = 0, j = a.size()-1;
    int count = 0;

    while(i < j) {
        int sum = a[i] + a[j];
        cout << sum << '\n';
        if(sum == target) {
            count++;
            i++;
            //j--
        } else if(sum > target) {
            j--;
        } else
        i++;
    }
    return count;
}

int main() {
    int m, k;
    cin >> m >> k;
    vector<int> a;
    for(int i =0 ; i < m; i++) {
        int n;
        cin >> n;
        a.push_back(n);
    }
    cout << twoPointers(a, k) << '\n';
}