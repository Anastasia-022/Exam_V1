#include <iostream>
using namespace std;

int main()
{
    char str[255];
    cin >> str;
    int pos = -1, act = 0, cnt = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
        {
            pos = i;
            act = 1;
        }
        else if (isdigit(str[i]) && (((act == 1 || act == 3) && cnt < 3) || ((act == 4 || act == 5) && cnt < 2)))
        {
            cnt++;
                if (cnt == 2 && act == 5)
                {
                    act = 6;
                        break;
                }
        }
        else if (act == 1 && cnt == 3 && str[i] == ')') act = 2;
        else if (act == 2 && str[i] == '-')
        {
            act = 3;
            cnt = 0;
        }
        else if (act == 3 && cnt == 3 && str[i] == '-')
        {
            act = 4;
            cnt = 0;
        }
        else if (act == 4 && cnt == 2 && str[i] == '-')
        {
            act = 5;
            cnt = 0;
        }
        else
        {
            act = 0;
            cnt = 0;
            pos = -1;
        }
    }

    if (act != 6) pos = -1;

    cout << pos;
}