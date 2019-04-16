#include <iostream>
using namespace std;

const int TOTAL = 5;

void main()
{
	long n, index[50], values[50], incr[50], start;

	cin >> n;
	while (n > 0) {
		for(int i=0; i<n; i++) {	// get indices
			cin >> index[i];
			values[i] = 0;
			incr[i] = 1;
		}
		cin >> start;
									// for each index k, find smallest
									// k-gonal number >= start
		for(i=0; i<n; i++) {
			while (values[i] < start) {
				values[i] += incr[i];
				incr[i] += index[i]-2;
			}
		}
		int count = 0;
		while (count < TOTAL) {
									// find minimal values of each
									// current k-gonal numbers
			long min = values[0];
			int num = 1;
			for(int i=1; i<n; i++) {
				if (values[i] < min) {
					min = values[i];
					num = 1;
				}
				else if (values[i] == min)
					num++;
			}
									// if more than two mins the same
									// then output
			if (num > 1) {
				cout << min;
				bool first = true;
				for(int i=0; i<n; i++) {
					if (values[i] == min) {
						cout << (first ? ':' : ' ') << index[i];
						first = false;
					}
				}
				cout << endl;
				count++;
			}
									// update all mins to their
									// next k-gonal value
			for(i=0; i<n; i++) {
				if (values[i] == min) {
					values[i] += incr[i];
					incr[i] += index[i]-2;
				}
			}
		}
		cin >> n;
		if (n != 0)
			cout << endl;
	}
}