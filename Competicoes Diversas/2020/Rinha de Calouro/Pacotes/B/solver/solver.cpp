#include <bits/stdc++.h>
using namespace std;

int main(){
    int v[4];
    for (int i = 0; i < 4; i++) scanf("%d", &v[i]);

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        swap(v[a-1], v[b-1]);
    }

    for (int i = 0; i < 4; i++) {
        if (v[i] == 1) printf("%d\n", i+1);
    }
}
