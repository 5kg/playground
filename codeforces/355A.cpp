#include <iostream>

using namespace std;

int main()
{
    int k, d;
    cin >> k >> d;

    if (d) {
        cout << d;
        for (int i = 0; i < k-1; ++i)
            cout << 0;
        cout << endl;
    } else if (k == 1)
        cout << 0 << endl;
    else
        cout << "No solution" << endl;

    return 0;
}
