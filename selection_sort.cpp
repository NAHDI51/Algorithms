#include <iostream>
#include <vector>
using namespace std;

#define SIZE 20

void selection_sort(vector<int>& vect) {
    for(int i = 0; i < vect.size() - 1; i++) {
        int min = vect[i];
        int min_indx = i;

        for(int j = i+1; j < vect.size(); j++) {
            if(min > vect[j]) {
                min = vect[j];
                min_indx = j;
            }
        }
        swap(vect[i], vect[min_indx]);
    }
}

int main() {
    vector<int> vec;
    cout << "before sorting: \n";
    for(int i = 0; i < SIZE; i++) {
        int r = rand();
        vec.push_back(r % 1000);
        cout << vec[i] << '\t';
    }
    cout << '\n';
    cout << "After sorting: \n";
    selection_sort(vec);
    for(int i = 0; i < SIZE; i++) {
        cout << vec[i] << '\t';
    }
    cout << '\n';
}