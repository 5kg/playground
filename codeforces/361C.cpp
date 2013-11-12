#include <iostream>

using namespace std;

struct op {
    int type, l, r, x;
};

op ops[5001];
int mm[5001], ans[5001];

int main()
{
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int type, l, r, x;

        cin >> ops[i].type >> ops[i].l >> ops[i].r >> ops[i].x;
    }

    for (int i = 1; i <= n; ++i)
        mm[i] = 1e9;

    for (int i = m - 1; i >= 0; --i) {
        if (ops[i].type == 1)
            for (int j = ops[i].l; j <= ops[i].r; ++j)
                mm[j] -= ops[i].x;
        else
            for (int j = ops[i].l; j <= ops[i].r; ++j)
                mm[j] = min(mm[j], ops[i].x);
    }

    for (int i = 1; i <= n; ++i) {
        ans[i] = mm[i];
        if (ans[i] > 1000000000)
            ans[i] = 1000000000;
    }

    for (int i = 0; i < m; ++i) {
        if (ops[i].type == 1)
            for (int j = ops[i].l; j <= ops[i].r; ++j)
                mm[j] += ops[i].x;
        else {
            int vmax = -2e9;
            for (int j = ops[i].l; j <= ops[i].r; ++j)
                vmax = max(vmax, mm[j]);
            if (vmax != ops[i].x) {
                cout << "NO" << endl;
                return 0;
            }
        }
    }

    cout << "YES" << endl;
    for (int i = 1; i <= n; ++i)
        cout << ans[i] << ((i == n) ? "\n" : " ");

    return 0;
}
