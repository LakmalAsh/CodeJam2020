#include "bits/stdc++.h"
#define endl "\n"
#define dd(x) cout << #x << " = " << (x) << ", "
#define de(x) cout << #x << " = " << (x) << endl
using namespace std;
using pii = pair<int, int>;
using ll = long long;

struct Dancer {
    bool deleted {false};
    int skill {0};
    Dancer * up {NULL};
    Dancer * down {NULL};
    Dancer * left {NULL};
    Dancer * right {NULL};
    bool die_in_nxt() {
        if (deleted) return false;
        int sum = 0;
        if (up != NULL) sum += up->skill - skill;
        if (down != NULL) sum += down->skill - skill;
        if (left != NULL) sum += left->skill - skill;
        if (right != NULL) sum += right->skill - skill;
        return sum > 0;
    }
    void del() {
        deleted = true;
        if (up != NULL) up->down = down;
        if (down != NULL) down->up = up;
        if (left != NULL) left->right = right;
        if (right != NULL) right->left = left;
    }
};

const int N = 1e5 + 7;
int n, m;
Dancer dancers[N];
Dancer * GetDancer(int r, int c) { 
    if (r < 0 || r >= n) return NULL;
    if (c < 0 || c >= m) return NULL;
    return &dancers[r * m + c]; 
}

void solve(int cas) {
    cin >> n >> m;
    ll cur_sum = 0;
    queue<Dancer *> may_die;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            int sk; cin >> sk;
            auto dancer = GetDancer(r, c);
            dancer->skill = sk;
            dancer->deleted = false;
            dancer->up = GetDancer(r - 1, c);
            dancer->down = GetDancer(r + 1, c);
            dancer->left = GetDancer(r, c - 1);
            dancer->right = GetDancer(r, c + 1);
            cur_sum += dancer->skill;
            may_die.push(dancer);
         }
    }
    ll ans = 0;
    while (true) {
        ans += cur_sum;
        queue<Dancer *> die_in_nxt;
        while (!may_die.empty()) {
            auto dancer = may_die.front(); may_die.pop();
            if (dancer->die_in_nxt()) {
                die_in_nxt.push(dancer);
            }
        }
        bool someone_die_in_nxt = !die_in_nxt.empty();
        while (!die_in_nxt.empty()) {
            auto dancer = die_in_nxt.front(); die_in_nxt.pop();
            if (dancer->deleted) continue;
            cur_sum -= dancer->skill;
            if (dancer->up != NULL) may_die.push(dancer->up);
            if (dancer->down != NULL) may_die.push(dancer->down);
            if (dancer->left != NULL) may_die.push(dancer->left);
            if (dancer->right != NULL) may_die.push(dancer->right);
            dancer->del();
        }
        if (!someone_die_in_nxt) break;
    }
    cout << "Case #" << cas << ": " << ans << endl;
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	for (int i = 0; i < t; i++) solve(i + 1);
    return 0;
}
