#include <iostream>
#include <vector>
using namespace std;

long long int polynomial(int n, vector<int> coeff) {    //coeff[i] represents coefficient of n's ith degree.
    long long int x = 0;
    for(int i = 0; i <= coeff.size() - 1; i++) {
        x = coeff[i] + (x * n);
    }
    return x;
}

int main() {
    int deg;
    cout << "Enter the degree of the polynomial: ";
    cin >> deg;
    vector<int> c;

    for(int i = 0; i < deg+1; i++) {
        int n;
        cout << "Enter the value of " << static_cast<char>(i+97)  << ": ";
        cin >> n;
        c.push_back(n); 
    }
    cout << '\n' << "POLYNOMIAL: ";
    for(int i = 0 ; i < c.size(); i++) {
        if(i != 0) cout << " + ";
        if(c[i] != 0) {
            if(i != c.size() - 1)
                cout << c[i] << "n^" << c.size() - 1 - i;
            else
                cout << c[i];
        }
    }
    cout << '\n';

    for(int i = 1; i <= 10; i++) cout << "f(" << i << ") = " << polynomial(i, c) << '\n';
    return 0;
}