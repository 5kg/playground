#include <iostream>

using namespace std;

int sum[101];

int main()
{
    int m;

    cin >> m;
    cin >> sum[1];
    for (int i = 2; i <= m; ++i) {
        cin >> sum[i];
        sum[i] += sum[i-1];
    }

    int x, y;
    cin >> x >> y;

    for (int i = 1; i <= m; ++i)
        if ((sum[i] >= x) && (sum[i] <= y) &&
                (sum[m] - sum[i] >= x) && (sum[m] - sum[i] <= y)) {
            cout << i+1 << endl;
            return 0;
        }

    cout << 0 << endl;
    return 0;
}
