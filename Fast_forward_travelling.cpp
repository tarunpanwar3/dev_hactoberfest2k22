#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include <debug.h>
#endif
#define st first
#define nd second
#define pb push_back
#define pf push_front
#define _pb pop_back
#define _pf pop_front
#define lb lower_bound
#define ub upper_bound
#define mtp make_tuple
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()
#define ll long long
#define ull unsigned long long
#define ldb long double
#define db double
#define str string
#define pi pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vll vector<ll>
#define vpi vector<pi>
#define vpll vector<pll>
#define gcd __gcd
#define lcm(a, b) ((a) / gcd((a), (b)) * (b))
#define FOR(i, l, r) for (int (i) = (l); (i) <= (r); ++(i))
#define FOS(i, r, l) for (int (i) = (r); (i) >= (l); --(i))
#define EACH(i, x) for (auto &(i) : (x))
#define WHILE while
#define file "TEST"
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
ll rand(ll l, ll r) { return uniform_int_distribution<ll>(l, r)(rd); }
/*
    Tran The Bao
    CTL - Da Lat
    Practising for VOI23 gold medal
*/
const int M = 998244353;
const int N = 1e6 + 1;
int t, n, f[N], inv[N], INV[N], a[N], cnt[N];
void reinit() { FOR(i, 1, n) cnt[i] = 0; }
void solve() {
	cin >> n;
	FOR(i, 1, n) cin >> a[i];
	FOR(i, 1, n) ++cnt[a[i]];
	int rs = 1;
	FOR(i, 1, n) {
		if (!cnt[i]) continue;
		if (cnt[i] % i != 0) {
			cout << 0 << '\n';
			return;
		}
		int total = cnt[i], num = cnt[i] / i;
		rs = 1LL * rs * f[total] % M * INV[num] % M;
		FOR(j, 1, num) rs = 1LL * rs * INV[i] % M;
		FOR(j, 1, num) rs = 1LL * rs * f[i - 1]  % M;
	}
	cout << rs << '\n';
}
signed main() {
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // freopen(file".inp", "r", stdin);
    // freopen(file".out", "w", stdout);
    inv[1] = 1;
    FOR(i, 2, N - 1) inv[i] = 1LL * (-M / i + M) % M * inv[M % i] % M;
    f[0] = INV[0] = 1;
    FOR(i, 1, N - 1) {
    	f[i] = 1LL * f[i - 1] * i % M;
    	INV[i] = 1LL * INV[i - 1] * inv[i] % M;
    }
    cin >> t;
    WHILE(t--) {
    	solve();
    	reinit();
    }
    return 0;
}
