#include <iostream>
#include <vector>
#include <array>
#include <climits>
#include <cstring>
#include <map>
using namespace std;

struct st {
    int n;
    string s;
};

void countSort(vector<vector<string>> arr) {
    int hi = 0;
    map<int, vector<string>> mp;
    for(int  i= 0; i < arr.size(); i++) {
        if((static_cast<int>(arr[i][0][0]) - 48) > hi) {
            hi = static_cast<int>(arr[i][0][0]) - 48;
        }
        mp[(arr[i][0][0] - 48)].push_back(arr[i][1]);
    } 
    
    vector<int> srt(hi+1);
    for(int i = 0; i < arr.size(); i++) {
       srt[arr[i][0][0] - 48]++;
    }
    vector<st> fn;
    int fn_indx = 0;
    for(int i = 0; i < hi+1; i++) {
        if(srt[i] != 0) {
            int ind = 0;
            while(srt[i]) {
                if(srt[i] < arr.size()/2) {
                    fn.push_back({srt[i], "-"});
                } else {
                    fn.push_back({srt[i], mp[srt[i]][ind]});
                    ind++;
                }
                fn_indx++;
                srt[i]--;
            }
        }
    }
    for(int i = 0; i < fn.size(); i++) {
        cout << fn[i].n << " " << fn[i].s << endl;
    }
}


int main() {
    vector<vector<string>> s;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        s.push_back({s1, s2});
    }
    countSort(s);
}
