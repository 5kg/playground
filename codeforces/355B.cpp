#include <iostream>

using namespace std;

int main()
{
    int c1, c2, c3, c4;

    cin >> c1 >> c2 >> c3 >> c4;

    int n, m;

    cin >> n >> m;

    int mb = 0, mt = 0;
    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        mb += min(c1*a, c2);
    }

    for (int i = 0; i < m; ++i) {
        int b;
        cin >> b;
        mt += min(c1*b, c2);
    }

    mb = min(mb, c3);
    mt = min(mt, c3);

    cout << min(mb+mt, c4) << endl;

    return 0;
}
