//user ashanlak
#include "bits/stdc++.h"
#define endl "\n"
#define dd(x) cout << #x << " = " << (x) << ", "
#define de(x) cout << #x << " = " << (x) << endl
using namespace std;

void solve(int cas) {
    int n; cin >> n;
    string pre, suf;
    string mid;
    bool noans = false;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int lp = 0;
        while (s[lp] != '*') lp++;
        int com_len = min(lp, (int)pre.size());
        if (s.substr(0, com_len) != pre.substr(0, com_len)) {
            noans = true;
            continue;
        }
        if ((int)pre.size() < lp) {
            pre = s.substr(0, lp);
        }
        int rp = (int)s.size() - 1;
        while (s[rp] != '*') rp--;
        rp++;
        com_len = min((int)s.size() - rp, (int)suf.size());
        if (s.substr(s.size() - com_len, com_len) != suf.substr(suf.size() - com_len, com_len)) {
            noans = true;
            continue;
        }
        if ((int)suf.size() < (int)s.size() - rp) {
            suf = s.substr(rp);
        }
        for (int j = lp; j < rp; j++) if (s[j] != '*') {
            mid += s[j];
        }
    }
    cout << "Case #" << cas << ": ";
    if (noans) cout << "*" << endl;
    else cout << pre << mid << suf << endl;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	for (int i = 0; i < t; i++) solve(i+ 1);
    return 0;
}
