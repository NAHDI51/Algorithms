#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

#define range(n) for(int i = 0; i < n; i++)

void insertion_sort(vector<int>& n) {
    for(int j = 1; j < n.size(); j++) {
        int key = n[j];
        int i = j-1;

        while(i >= 0 && key < n[i]) {
            n[i+1] = n[i];
            i--;
        }
        n[i+1] = key;
    }
} 

int main() {
    vector<int> vect;
    cout << "Vector before sorting:\n";
    range(20) {
        int r = rand() % 1000;
        vect.push_back(r);
        cout << vect.back() << '\t';
    }
    cout << '\n';
    cout << "Vector after sorting: \n";
    insertion_sort(vect);
    for(auto i = vect.begin(); i != vect.end(); i++) {
        cout << *i << '\t';
    }
    cout << '\n';
}