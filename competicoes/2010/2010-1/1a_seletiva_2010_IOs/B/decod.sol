hello
second test case
encoded?
pludfykgruowzgiooobppleqlwphapjnadqhdcjvwdtxjbmypmphauxnspusgdhiixqmbfjxncvudjsu
kskfojnewxgxnnofwltwjsnnvkwjcbdmeouuzhyvhgvwujbqxxpitcvograiddvhrrdwycqhkleewhxt
zjchndnlunmppnlgjsnkewwuyzgefonexpmmsbaopmdgzqmkqzxuvtqvpxbslqzkglzamzpdnsjolvyb
hrynqzdqmlfotpqhvokiiammqmvxjvbsoaifxyxnjcberrnmixxsyjhovengbpyqrixqgwqrygxrxkfh
ltqtmpyyeqtujuiokcowswqyxntnsxqqdgkhvihbaawjugagloddktdjizynyoesuozryityjrifximk
zlizniccozwknwyhzgpqlwfkjqipuujvwtxlbzngyjdohbvrhmyuiggtyqjtmuqinntqmihntkddnaaw
pdvslkoelfynzeavaaceazuipydypvmgyxblhmpuunkttkqtmvanuuvjvahmjvuvsvhzkywhmgchqvdc
qsdmzohydtuotmyysttlknjqdyudpbxftatuqastvphoahpsdifnxrfbqaghdfoyhhsxhntdcctcmivp
rqgjhmjqtypztjsnopyagetjfqiexqroiayrojhghjiarcpgrniysdhztzfqhwhpyfioopxxvgxniova
vzwalxoeufhotiotgryvoeicbnljkoahnxibwwhqdrhwzxsfpqadujixytdjjjqziaaewjwccfydiqju
// Author: Adrian Kuegel
// Date: 27. 6. 2008
// Complexity: O(n)
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <vector>
#include <assert.h>
using namespace std;
#define MAXN 80
int p[MAXN];
char s[MAXN+1], out[MAXN+1];
typedef vector<int> VI;
int main() {
int n, m, q;
freopen("decode.in", "r", stdin);
while(scanf("%d %d", &n, &m) == 2 && n && m) {
assert(1 <= n && n <= MAXN);
assert(1 <= m && m <= 1000000000);
for (int i=0; i<n; ++i)
p[i] = -1;
for (int i=0; i<n; i++) {
scanf("%d", &q);
assert(1 <= q && q <= n);
assert(p[q-1] == -1);
p[q-1] = i;
}
gets(s); // skip remainder of previous line
gets(s);
assert(strlen(s) == n);
strcpy(out, s);
for (int i=0; i<n; ++i) {
if (p[i] == i)
continue;
VI temp;
while(p[i] != i) {
temp.push_back(p[i]);
swap(p[i], p[p[i]]);
}
temp.push_back(i);
int k = m % temp.size();
for (int j=0; j<(int)temp.size(); ++j) {
out[temp[j]] = s[temp[(j+k)%temp.size()]];
}
}
puts(out);
}
assert(n == 0 && m == 0);
return 0;
}
