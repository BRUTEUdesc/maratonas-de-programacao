// another fine solution by misof
#include <string.h>
#include <iostream>
#include <vector>
#include <map>
using namespace std;

#define CLEAR(t) memset((t),0,sizeof(t))
#define REP(i,n) for(int i=0;i<(int)(n);++i)

#define MAXR 8
#define ENCODE(c1,c2) (1LLU << (((c1)<<3) | (c2)))
#define DOTOUCH(T,c1,c2) ((T) & ENCODE((c1),(c2)))

typedef vector<int> column;
typedef unsigned long long touching;
typedef pair<column,touching> info;
typedef pair<int,info> state;
map<state,long long> memo;
int T,R,C;

long long solve(int kde, touching T, const column &stary) {
  state S(kde,info(stary,T));
  if (memo.count(S)) return memo[S];
  long long &res = memo[S];
  res = 0;
  if (kde == C) return res=1;
  // generate all possible states for the next column
  int G[2*MAXR][2*MAXR];
  int color[2*MAXR];
  REP(vert,1<<R)
    REP(hor,1<<(R-1)) {
      // fill the connectivity graph
      CLEAR(G);
      REP(r,2*R) G[r][r]=1;
      REP(r1,R) REP(r2,r1) if (stary[r1]==stary[r2]) G[r1][r2]=G[r2][r1]=1;
      REP(r,R) if (!(vert & (1<<r))) G[r][r+R]=G[r+R][r]=1;
      REP(r,R-1) if (!(hor & (1<<r))) G[R+r][R+r+1]=G[R+r+1][R+r]=1;
      // run floyd-warshall
      REP(k,2*R) REP(i,2*R) REP(j,2*R) G[i][j] |= G[i][k] && G[k][j];
      // color the components starting with the new vector
      memset(color,-1,sizeof(color));
      int colorsUsed = 0;
      REP(m,2) REP(r,R) if (color[(1-m)*R+r]==-1) { 
        REP(r2,2*R) if (G[(1-m)*R+r][r2]) color[r2]=colorsUsed; 
        colorsUsed++; 
      }
      // check coloring validity
      int ok = 1;
      
      REP(r,R-1) if (stary[r]!=stary[r+1]) if (G[r][r+1]) ok = 0; // useless edge before
      REP(r,R) if (vert & (1<<r)) if (G[r][r+R]) ok = 0; // useless vertical edge
      REP(r,R-1) if (hor & (1<<r)) if (G[R+r][R+r+1]) ok = 0; // useless edge after

      // we can not merge two colors if the regions are touching already
      REP(r,R) REP(r2,r) if (DOTOUCH(T,stary[r],stary[r2])) if (color[r]==color[r2]) ok = 0;

      if (ok) {
        // create the new color vector
        vector<int> next(color+R,color+2*R);
        // create the new touching info
        touching NT = 0;
        // now:
        REP(r,R-1) if (color[R+r]!=color[R+r+1]) NT |= ENCODE(color[R+r],color[R+r+1]) | ENCODE(color[R+r+1],color[R+r]);
        // touching the previous column:
        int newColors = 0; REP(r,R) newColors = max(newColors,color[R+r]+1);
        REP(r,R) if (color[r]<newColors) if (color[r]!=color[R+r]) NT |= ENCODE(color[R+r],color[r]) | ENCODE(color[r],color[R+r]);
        // touching even earlier
        REP(r,R) REP(r2,r) if (DOTOUCH(T,stary[r],stary[r2])) if (color[r]<newColors) if (color[r2]<newColors) NT |= ENCODE(color[r],color[r2]) | ENCODE(color[r2],color[r]);
        // update the result
        res += solve(kde+1,NT,next);
      }
    }
  return res;
}

int main() {
  cin >> T;
  while (T--) {
    memo.clear();
    cin >> R >> C; if (R > C) swap(R,C);
    cerr << R << " " << C << " ..."; //added by Tom
    long long res = 0;
    REP(how,1<<(R-1)) {
      column col(R);
      REP(r,R-1) col[r+1] = col[r] + !!(how & (1<<r));
      touching T = 0;
      int last = col[R-1];
      REP(i,last) T |= ENCODE(i,i+1) | ENCODE(i+1,i);
      res += solve(1,T,col);
    }
    cerr << " done.\n"; //added by Tom
    cout << res << endl;
  }
  return 0;
}
// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
