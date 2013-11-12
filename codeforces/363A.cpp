#include <iostream>

using namespace std;

void show(int d)
{
    if (d >= 5) {
        cout << "-O|";
        d -= 5;
    }
    else
        cout << "O-|";
    for (int i = 0; i < d; ++i)
        cout << "O";
    cout << "-";
    for (int i = 0; i < 4-d; ++i)
        cout << "O";
    cout << endl;
}

int main()
{
    int n;

    cin >> n;

    do {
        int d = n % 10;
        show(d);
        n /= 10;
    } while(n);
    return 0;
}
