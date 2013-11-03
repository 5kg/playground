#include <iostream>

using namespace std;

inline bool is_at_edge(int r, int c, int n, int m)
{
    return (!r || !c || (r == n-1) || (c == m-1));
}

int main()
{
    int n, m, rst = 4;
    cin >> n >> m;

    for (int r = 0; r < n; ++r)
        for (int c = 0; c < m; ++c) {
            int v;
            cin >> v;
            if (v && is_at_edge(r, c, n, m)) {
                rst = 2;
                goto end;
            }
        }
end:
    cout << rst << endl;

    return 0;
}
