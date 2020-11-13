#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

#define MAXN 5005
string s;
int sa[MAXN], ra[2*MAXN], rb[2*MAXN], n, G, pre[MAXN], plcp[MAXN], lcp[MAXN];

bool cmp(int x, int y){
    if (ra[x] < ra[y]) return true;
    return (ra[x] == ra[y] && ra[x+G] < ra[y+G]);
}

int main() {

    ios::sync_with_stdio(0);
    int t; cin >> t; cin.ignore(1);
    while(t--) {
        memset(sa, 0, sizeof sa);
        memset(ra, 0, sizeof ra);
        memset(rb, 0, sizeof rb);
        memset(pre, 0, sizeof pre);
        memset(plcp, 0, sizeof plcp);
        memset(lcp, 0, sizeof lcp);

        cin >> s; s = " " + s;
        n = (int)s.length() - 1;

        for(int i = 1; i <= n; i++)
        { sa[i] = i; ra[i] = s[i]; }
        for(G = 1; G <= n; G <<= 1) {
            sort(sa+1, sa+n+1, cmp);
            rb[sa[1]] = 1;
            for(int i = 2; i <= n; i++)
                rb[sa[i]] = rb[sa[i-1]] + cmp(sa[i-1], sa[i]);
            for(int i = 1; i <= n; i++)
                ra[i] = rb[i];
            if (ra[sa[n]] == n) break;
        }

        pre[sa[1]] = -1;
        for(int i = 2; i <= n; i++) pre[sa[i]] = sa[i-1];
        int L = 0;
        for(int i = 1; i <= n; i++) {
            if (pre[i] == -1) { plcp[i] = 0; continue; }
            while(s[i+L] == s[pre[i]+L]) L++;
            plcp[i] = L;
            L = max(L-1, 0);
        }
        for(int i = 1; i <= n; i++)
            lcp[i] = plcp[sa[i]];

        int ans = 0;
        for(int i = 2; i <= n; i++)
            ans = max(ans, lcp[i]);
        cout << ans << '\n';
    }

    return 0;
}
