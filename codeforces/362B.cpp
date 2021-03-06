#include <iostream>
#include <algorithm>

using namespace std;

int d[3000];

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i)
        cin >> d[i];

    sort(d, d + m);

    if ((d[0] == 1) || (d[m-1] == n))
        cout << "NO" << endl;
    else if (m <= 2)
        cout << "YES" << endl;
    else {
        for (int i = 2; i < m; ++i)
            if ((d[i] == d[i-1]+1) && (d[i] == d[i-2]+2)) {
                cout << "NO" << endl;
                return 0;
            }
        cout << "YES" << endl;
    }

    return 0;
}
