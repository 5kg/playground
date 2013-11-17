#include <iostream>

using namespace std;

int main()
{
    int n, five, zero;
    five = zero = 0;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int t;
        cin >> t;
        if (t == 5)
            ++five;
        else
            ++zero;
    }

    if (!zero)
        cout << -1 << endl;
    else if (five / 9 < 1)
        cout << 0 << endl;
    else {
        for (int i = 0; i < (five/9*9); ++i)
            cout << 5;
        for (int i = 0; i < zero; ++i)
            cout << 0;
        cout << endl;
    }
    return 0;
}
