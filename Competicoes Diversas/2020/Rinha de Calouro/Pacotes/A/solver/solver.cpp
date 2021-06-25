#include <bits/stdc++.h>

using namespace std;

int main(){
    
    int cont = 0;
    for (int i=0; i<12; i++){
        int x; cin >> x;
        if (x%2==0) cont += x;
        else cont += x-1;
    }

    cout << cont << endl;

}