#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int c = 0;

void permute(int n, string a) {
    if(n == a.size()) n--;

    if(n == 0) {
        c++;
        cout << a << '\n';
    } else {
        for(int i = n; i >= 0; i--) {
            permute(n-1, a);
            swap(a[i-1], a[n]);
        }
    }
}

int main() {
    string s;
    cout << "Enter your string: ";
    cin >> s;
    cout << "Permutations: \n";
    permute(s.length(),s);
    cout << "Total count: " << c << '\n';
    return 0;
}