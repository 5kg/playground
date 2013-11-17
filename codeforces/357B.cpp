#include <iostream>

using namespace std;

int d[100001][3];
int o[][3] = { {1, 2, 3}, {1, 3, 2}, {2, 1, 3}, {2, 3, 1}, {3, 1, 2}, {3, 2, 1} };
int c[100001];
int n, m;

void dfs(int l, int x)
{
    if (l > m)
        return;
    for (int i = 0; i < 3; ++i)
        if (c[d[l][i]] && (c[d[l][i]] != o[x][i]))
            return;
    for (int i = 0; i < 3; ++i)
        c[d[l][i]] = o[x][i];
    for (int i = 0; i < 6; ++i)
        dfs(l+1, i);
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; ++i)
        cin >> d[i][0] >> d[i][1] >> d[i][2];

    for (int i = 0; i < 6; ++i)
        dfs(1, i);

    for (int i = 1; i <= n; ++i)
        cout << c[i] << ((i == n) ? "\n" : " ");
    return 0;
}
