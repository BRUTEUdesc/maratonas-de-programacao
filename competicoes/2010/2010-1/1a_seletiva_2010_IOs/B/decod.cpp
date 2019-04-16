#include<cassert>
#include<vector>
#include<iostream>
#include<string>

using namespace std;

typedef vector<int> VI;
typedef long long LL;

int n;

inline VI concat(const VI& a, const VI& b) {
	VI v(n);
	for (int i=0; i<n; i++) {
		v[i]=b[a[i]-1];
	}
	return v;
}

VI pow(const VI& v, int m) {
	if (m==1) return v;
	if (m==0) {
		VI temp(n);
		for (int i=0; i<n; i++) temp[i]=i+1;
		return temp;
	}
	const VI temp=pow(v,m/2);
	if (m%2==0) return concat(temp,temp);
	else return concat(concat(temp,temp),v); 
}


int main() {
	//freopen("decode.in","r",stdin);
	int m; cin >> n >> m;
	while (n||m) {
		VI v(n);	
		for (int i=0; i<n; i++) {
			cin >> v[i];
		}
		char c=0;
		while (c!='\n')	cin.get(c);
		char input[n];
		for (int i=0; i<n; i++) {
			cin.get(input[i]);
		}
	
		VI inv=pow(v,m);

		char res[n];
		for (int i=0; i<n; i++) {
			res[inv[i]-1]=input[i];
		}
		for (int i=0; i<n; i++) cout << res[i];
		cout << endl;

		cin >> n >> m;
	}
}
