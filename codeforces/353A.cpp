#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    int sa, sb, oe, eo;
    sa = sb = oe = eo = 0;
    for (int i = 0; i < n; ++i) {
        int a, b;

        cin >> a >> b;
        sa += a & 1;
        sb += b & 1;
        if ((a & 1) && !(b & 1))
            ++oe;
        if (!(a & 1) && (b & 1))
            ++eo;
    }

    if (!(sa & 1) && !(sb & 1))
        cout << 0 << endl;
    else if ((sa + sb) & 1)
        cout << -1 << endl;
    else if (oe + eo <= 1)
        cout << -1 << endl;
    else
        cout << 1 << endl;

    return 0;
}
