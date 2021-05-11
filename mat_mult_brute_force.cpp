#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrix_mult(vector<vector<int>>& a, vector<vector<int>>& b) {
    if(a[0].size() != b.size()) return vector<vector<int>>();

    vector<vector<int>> mult(a.size());

    for(int i = 0; i < a.size(); i++) {
        for(int j = 0; j < b[0].size(); j++) {
            int sum = 0;
            for(int k = 0; k < b.size(); k++) {
                sum += (a[i][k] * b[k][j]);
            }
            mult[i].push_back(sum);
        }
    }
    return mult;
}

void print_mat(vector<vector<int>> vec) {
    for(int i = 0; i < vec.size(); i++) {
        for(int j = 0; j < vec[0].size(); j++) {
            if(j == 0)
                cout << "|  ";
            
            printf("%8d  ", vec[i][j]);

            if(j == vec[i].size() - 1)
                cout << "  |";
        }
        cout << '\n';
    }
    cout << '\n';
}

int main() {
    int c1, c2, r1;
    cout << "Enter the number of rows for vec1: ";
    cin >> r1;
    cout << "Enter the number of columns for vec2: ";
    cin >> c2;
    cout << "Enter the number of columns for vec1: ";
    cin >> c1;

    vector<vector<int>> vect1(r1);
    vector<vector<int>> vect2(c1);

    cout << "Enter matrix #1 (" << r1 << '*' << c1 << ')' << "\n";
    for(int i =0; i < r1; i++) {
        for(int j = 0; j < c1; j++) {
            int n;
            cin >> n;
            vect1[i].push_back(n);
        }
    }

    
    cout << "Enter matrix #2 (" << c1 << '*' << c2 << ')' << '\n';
    for(int i =0; i < c1; i++) {
        for(int j = 0; j < c2; j++) {
            int n;
            cin >> n;
            vect2[i].push_back(n);
        }
    }

    vector<vector<int>> mult_vect = matrix_mult(vect1, vect2);
    print_mat(vect1);
    cout << "\n * \n\n";
    print_mat(vect2);
    cout << "\n = \n\n";
    print_mat(mult_vect);
}