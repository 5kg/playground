#include <iostream>

using namespace std;

int a[200000];

int main()
{
    int n, k, m = 0, idx = 0, mm;

    cin >> n >> k;

    for (int i = 0; i < n; ++i)
        cin >> a[i];

    for (int i = 0; i < k; ++i)
        m += a[i];

    mm = m;

    for (int i = 1; i < n-k+1; ++i) {
        m = m - a[i-1] + a[i+k-1];
        if (m < mm) {
            idx = i;
            mm = m;
        }
    }

    cout << idx + 1 << endl;

    return 0;
}
