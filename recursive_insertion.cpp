#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

#define SIZE 20

void insert(vector<int>& v, int len, int element) {
    int i = len;
    while(i >= 0 && element < v[i]) {
        v[i+1] = v[i];
        i--;
    }
    v[i+1] = element;
}

void insertion_sort(vector<int>& v, int len) {
    if(len == v.size()) len--;

    if(len != 0) {
        insertion_sort(v, len-1);
        insert(v, len-1, v[len]);
    }
}

int main() {
     vector<int> vec;

    srand((unsigned)time(NULL));
    cout << "Vector before sorting:\n";
    for(int i =0 ; i < SIZE; i++) {
        int r= rand() % 1000;
        vec.push_back(r);
        cout << vec[i] << '\t';
    }
    cout << '\n';
    insertion_sort(vec, vec.size());
    cout << "Vector after sorting:\n";
    for(int i = 0; i < SIZE; i++) {
        cout << vec[i] << '\t';
    }
    cout << '\n';
}