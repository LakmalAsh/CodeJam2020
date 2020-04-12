// user ashanlak
#include "bits/stdc++.h"
#define endl "\n"
#define dd(x) cout << #x << " = " << (x) << ", "
#define de(x) cout << #x << " = " << (x) << endl
using namespace std;


bool check(int target, int m, int &ans_mask) {
    if (target < m) { return false; }
    int remain = target - m;
    ans_mask = 0;
    for (int i = min(30, m - 1); i >= 0; i--) {
        if (remain) {
            if ((remain + 1) >> i & 1) {
                ans_mask |= 1 << i;
                remain = (remain + 1) - (1 << i);
            }
        }
    }
    return !remain;
}

void solve(int cas) {
    int n; cin >> n;
    int m = 0;
    int ans_mask = 0;
    while (!check(n, m, ans_mask)) m++;
    bool cur_is_left = true;
    cout << "Case #" << cas << ":" << endl;
    using pii = pair<int, int>;
    vector<pii> ans = {{1, 1}};
    int r = 1, c = 1;
    for (int i = 1; i < m; i++) {
        if (cur_is_left) r++;
        else r++, c++;
        ans.emplace_back(r, c);
        if (i <= 30 && ans_mask >> i & 1) {
            if (cur_is_left) {
                for (int i = 0; i < r - 1; i++) {
                    c++;
                    ans.emplace_back(r, c);
                }
                cur_is_left = false;
            } else {
                for (int i = 0; i < r - 1; i++) {
                    c--;
                    ans.emplace_back(r, c);
                }
                cur_is_left = true;
            }
        }
    }
    for (auto &p : ans) {
        cout << p.first << " " << p.second << endl;
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t; cin >> t;
    for (int i = 0; i < t; i++) solve(i + 1);
    return 0;
}
