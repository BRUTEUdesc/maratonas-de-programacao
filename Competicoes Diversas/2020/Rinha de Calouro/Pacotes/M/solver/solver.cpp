#include <bits/stdc++.h>

using namespace std;

int main(){
    int S,D; cin >> S >> D;
    vector<long long> cont;
    cont.assign(S+1,0);
    long long sum = 0;
    for(int i=0; i<D; i++){
        for(int j=0; j<S; j++){
            long long x; cin >> x;
            cont[j] += x;
            sum += x;
        }
    }
    cout << ceil((double)sum/D) << endl;
    cout << 1 + distance(cont.begin(), max_element(cont.begin(), cont.end())) << endl;
}