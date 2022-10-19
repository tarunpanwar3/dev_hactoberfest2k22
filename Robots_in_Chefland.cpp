#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define MAXN 1000010
#define MAXLG 22
#define MOD 1000000007
#define pb push_back
#define mp make_pair

#define ll long long
#define lld long long double
#define INF LLMAX

#define FOR(i, a, b) for(int i = a ; i <= b ; ++i)
#define REV(i, a, b) for(int i = a ; i >= b ; --i)
#define SFOR(i, a, b, d) for(int i = a ; i <= b ; i+=d)
#define SREV(i, a, b, d) for(int i = a ; i >= b ; i-=d)
#define fill(a, val) memset(a, val, sizeof(a))

#define sz(a) (int)a.size()
#define len(a) (int)a.length()
#define pi M_PI
#define cd complex<double>

int gcd(int a, int b) {
  if(a == 0)
  return b;
  return gcd(b%a, a);
}

ll modularExponentiation(ll base, ll power, ll mod) {
  ll ans = 1;
  while(power > 0) {
    if(power&1)
    ans = (ans*base)%mod;
    power = power>>1;
    base = (base*base)%mod;
  }
  return ans;
}
const ll C = 6;
const double x[6] = {1.0, cos(pi/3), cos((2*pi)/3), cos(pi), cos((4*pi)/3), cos((5*pi)/3)};
const double y[6] = {0.0, sin(pi/3), sin((2*pi)/3), sin(pi), sin((4*pi)/3), sin((5*pi)/3)};
ll l, r, n, q;
string str;
struct SegmentTree {
  double X[C];
  double Y[C];
  ll E[C];
};

SegmentTree segmentTree[MAXN];

SegmentTree merge(SegmentTree segmentTree1, SegmentTree segmentTree2) {
  SegmentTree ret;
  FOR(i, 0, C-1) {
    ll mv = segmentTree1.E[i];
    ret.E[i] = segmentTree2.E[mv];
    ret.X[i] = segmentTree1.X[i]+segmentTree2.X[mv];
    ret.Y[i] = segmentTree1.Y[i]+segmentTree2.Y[mv];
  }

  return ret;
}

void buildSegmentTree(ll node, ll st, ll en) {
  if(st > en)
  return;

  if(st == en) {
    ll mv = str[st]-'0';
    FOR(i, 0, C-1) {
      segmentTree[node].E[i] = (mv+i)%C;
      segmentTree[node].X[i] = x[segmentTree[node].E[i]];
      segmentTree[node].Y[i] = y[segmentTree[node].E[i]];
    }

    return;
  }

  buildSegmentTree(2*node, st, (st+en)/2);
  buildSegmentTree(2*node+1, (st+en)/2+1, en);

  segmentTree[node] = merge(segmentTree[2*node], segmentTree[2*node+1]);
}

SegmentTree getFinalPos(ll node, ll st, ll en, ll i, ll j) {
  if(st >= i && en <= j)
  return segmentTree[node];

  if(j <= (st+en)/2)
  return getFinalPos(2*node, st, (st+en)/2, i, j);
  else if(i >= (st+en)/2+1)
  return getFinalPos(2*node+1, (st+en)/2+1, en, i, j);
  else  
  return merge(getFinalPos(2*node, st, (st+en)/2, i, j), getFinalPos(2*node+1, (st+en)/2+1, en, i, j));
}

void solve() {
  cin >> n >> q;
  cin >> str;
  buildSegmentTree(1, 0, n-1);
  FOR(i, 1, q) {
    cin >> l >> r;
    SegmentTree result = getFinalPos(1, 0, n-1, l-1, r-1);
    cout << setprecision(9) << fixed << result.X[0] << " " << result.Y[0] << endl;
  }

  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int t = 1;
  cin >> t;
  while(t--) {
    solve();
  }
  return 0;
}
