#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int binary_search(vector<int>& a, int p, int q, int key) {
    if (q == a.size()) q--;

    if(p <= q) {
        int m = (p+q) / 2 - 1;  //-1 for the zero based index system

        if(a[m] == key) 
            return m;
        else if(a[m] > key) 
            return binary_search(a, p, m-1, key);
        else if(a[m] < key)
            return binary_search(a, m+1, q, key);
    } else 
        return -1;
}

int main() {
    vector<int> vec;
    srand((unsigned) time(NULL));
    cout << "Elements of the array:\n ";
    for(int i =0 ; i < 20; i++) {
        int r = rand() % 1000;
        vec.push_back(r);
        cout << vec[i] << '\t';
    }
    cout << '\n';
    cout << binary_search(vec, 0, vec.size(), 20);
}