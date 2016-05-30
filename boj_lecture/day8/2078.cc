#include <iostream>
using namespace std;
int main()
{
    int X, Y, L = 0, R = 0;

    cin >> X >> Y;

    while (!(X == 1 && Y == 1))
    {
        if (X < Y) {
            R += Y / X;

            if (X == 1)
            {
                R--;
                Y = 1;
            }
            else Y = Y % X;
        }
        else {
            L += X / Y;
            if (Y == 1)
            {
                L--;
                X = 1;
            }
            else X = X % Y;
        }
    }

    cout << L << " " << R;
}