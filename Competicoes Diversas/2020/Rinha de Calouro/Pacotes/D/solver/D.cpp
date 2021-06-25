#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,d;
    cin >> n >> d;
    int mmc=4;
    for(int i=0;i<n;i++){
        int a;
        scanf("%d", &a);
        mmc=(mmc*a)/__gcd(mmc,a);
    }
    int resposta = 2020+mmc;
    int minimo = 2020+d;
    while(resposta<minimo){
        resposta+=mmc;
    }
    printf("%d\n", resposta);
}