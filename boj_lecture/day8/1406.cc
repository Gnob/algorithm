#include <iostream>
#include <vector>

using namespace std;

int main()
{
    string str;
    cin >> str;

    int N;
    cin >> N;

    char cmd;
    int curPos = str.length();
    while (N--)
    {
        char buf[8];
        scanf("%s", buf);
        cmd = buf[0];

        if (cmd == 'L')
        {
            if (curPos > 0)
                curPos--;
        }
        else if (cmd == 'D')
        {
            if (curPos < str.length())
                curPos++;
        }
        else if (cmd == 'B')
        {
            if (curPos > 0)
            {
                str.erase(str.begin() + curPos - 1);
                curPos--;
            }
        }
        else
        {
            scanf("%s", buf);
            char ch = buf[0];

            if (curPos == str.length())
            {
                str.push_back(ch);
                curPos++;
            }
            else
            {
                str.insert(str.begin() + curPos, ch);
                curPos++;
            }
        }
    }

    cout << str;
}