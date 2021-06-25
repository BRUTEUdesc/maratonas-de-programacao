#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    int casos;
    cin >> casos;
    while(casos--){
        ll num;
        cin >> num;

        bool flag = true;
        for (int i = 2; i <= sqrt(num); i++){
            if (num % i == 0){
                flag = false;
                cout << "ei Kaqui, esse numero nao eh primo"<< endl;
                break;
            }
        }

        if(flag){
            cout << (int) log10(num)+1 << endl;
        }
    }
}
