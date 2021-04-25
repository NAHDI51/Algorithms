#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

#define SIZE 20

int avg(int a, int b) {return (a+b) / 2;}

//Sub arrays: |p, p+1, ..., q-1, q| and |q+1, ... , r|
void merge_2(vector<int>& A, int p, int q, int r) {
    int n1 = q-p+2;
    int n2 = r-q+1;

    int L[n1], R[n2];
    for(int i = 0 ; i < n1-1; i++) 
        L[i] = A[p+i];
    for(int i = 0; i < n2-1; i++) 
        R[i] = A[q+i+1];

    int r_indx, l_indx;
    r_indx = l_indx = 0;
    L[n1-1] = R[n2-1] = INT_MAX;

    for(int k = p; k <= r; k++) {
        if(L[l_indx] <= R[r_indx]) {
            A[k] = L[l_indx];
            l_indx++;
        } else if(R[r_indx] < L[l_indx]) {
            A[k] = R[r_indx];
            r_indx++;
        }
    }
}

void merge(vector<int>& A, int p, int q, int r) {
    int n1 = q-p+1;
    int n2 = r-q;
    int lft[n1];
    int ryt[n2];

    for(int i = 0; i < n1; i++) 
        lft[n1] = A[p+i];
    for(int i = 0; i < n2; i++) 
        ryt[n2] = A[q+i+1];
    
    int in1 = 0, in2 = 0;

    for(int k = p; k <= r; k++) {
        if(in1 == n1) {
            A[k] = ryt[in2]; 
            in2++;
        } else if(in2 == n2) {
            A[k] = lft[in1];
            in1++;
        } else if(lft[in1] < ryt[in2]){
            A[k] = lft[in1];
            in1++;
        } else {
            A[k] = ryt[in2];
            in2++;
        }
    }
}

void merge_sort(vector<int>& A, int p, int r) {
    if(r == A.size()) r--;
    if(p < r) {
        //Reminder: now the ceiling is q-1 and r-1 respectively. Thus, we will need to merge them like that.
        int q = avg(p, r);
        merge_sort(A, p, q);
        merge_sort(A, q+1 ,r);
        merge_2(A, p, q, r);
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
    merge_sort(vec, 0, vec.size());
    cout << "Vector after sorting:\n";
    for(int i = 0; i < SIZE; i++) {
        cout << vec[i] << '\t';
    }
    cout << '\n';
}