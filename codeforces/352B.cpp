#include <iostream>

using namespace std;

int prev[100001];
int d[100001];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= 100000; ++i)
        d[i] = prev[i] = 0;

    for (int i = 1; i <= n; ++i) {
        int t;
        cin >> t;

        if (d[t] < 0)
            continue;

        if ((prev[t] > 0) && (d[t] > 0) && (d[t] != (i-prev[t]))) {
            d[t] = -1;
            continue;
        }

        if (prev[t] > 0)
            d[t] = i-prev[t];
        prev[t] = i;
    }

    int tot = 0;
    for (int i = 1; i <= 100000; ++i)
        if ((prev[i] > 0) && (d[i] >= 0))
            ++tot;
    cout << tot << endl;
    for (int i = 1; i <= 100000; ++i)
        if (d[i] < 0)
            continue;
        else if (prev[i] > 0)
            cout << i << " " << d[i] << endl;

    return 0;
}
