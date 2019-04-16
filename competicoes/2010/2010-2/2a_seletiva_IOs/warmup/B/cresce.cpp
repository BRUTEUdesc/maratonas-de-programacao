#include <iostream.h>

#define SIZE 1000

bool commas[SIZE];

int lastComma, lastSize;

bool greater(int prev, int start, int end, int a[])
{
	int prevend = start;
	while (start < end && a[start] == 0)
		start++;
	if (start == end && a[start] == 0)
		return false;
	while (prev < prevend-1 && a[prev] == 0)
		prev++;
	if (prev == prevend-1 && a[prev] == 0)
		return true;
	if (prevend-prev > end-start+1)
		return false;
	if (prevend-prev < end-start+1)
		return true;
	for(int i=start; i<=end; i++) {
		if (a[i] > a[i-start+prev])
			return true;
		else if (a[i] < a[i-start+prev])
			return false;
	}
	return false;
}
bool greaterequal(int start1, int end1, int start2, int end2, int a[])
{
	bool iszero1 = false, iszero2 = false;
	while (start1 < end1-1 && a[start1] == 0)
		start1++;
	if (start1 == end1-1 && a[start1] == 0)
		iszero1 = true;
	while (start2 < end2-1 && a[start2] == 0)
		start2++;
	if (start2 == end2-1 && a[start2] == 0)
		iszero2 = true;
	if (end1-start1 > end2-start2)
		return true;
	if (end1-start1 < end2-start2)
		return true;
	for(int i=start1; i<end1; i++) {
		if (a[i] > a[i-start1+start2])
			return true;
		else if (a[i] < a[i-start1+start2])
			return false;
	}
	return true;
}

void findseries(int start, int a[], int size, int prev, bool comma[])
{
	if (start == size) {
		if (greaterequal(prev, size, lastComma, size, a)) {
			for(int i=0; i<size; i++)
				commas[i] = comma[i];
			lastComma = prev;
			int temp = prev;
			lastSize = size-prev;
		}
		return;
	}
	comma[start-1] = true;
	int i=start;
	while (i<size && !greater(prev, start, i, a)) {
		i++;
	}
	int j = start;
	while (j<i && a[j] == 0)
		j++;
	while (i<size && (i-j+1 <= lastSize)) {
		findseries(i+1, a, size, start, comma);
		i++;
	}
	comma[start-1] = false;
}


int main()
{
	int size;
	int a[SIZE];
	bool comma[SIZE];
	char ch;


	while (true) {

		for(size=0; true; size++) {
			cin.get(ch);
			if (ch < '0' || ch > '9')
				break;
			a[size] = ch-'0';
			comma[size] = false;
			commas[size] = false;
		}
		if (size == 1 && a[0] == 0)
			break;
		lastComma = 0, lastSize = size;
		int i=1;
		while (i<size) {
			findseries(i, a, size, 0, comma);
			i++;
		}
		bool nonzero = false;
		for(i=0; i<size; i++) {
			cout << a[i];
			if (a[i] != 0)
				nonzero = true;
			if (nonzero && commas[i]) {
				cout << ',';
				nonzero = false;
			}
		}
		cout << endl;

	}
}
