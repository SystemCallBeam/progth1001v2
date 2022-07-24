#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, i, j, k;
    cin >> n >> m;
    char game_table[21][21];
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> game_table[i][j];
        }
    }
    int Brick[21];
    for (i = 0; i < m; i++)
    {
        cin >> Brick[i];
    }
    for (i = 0; i < m;)
    {
        for (j = -1; j < n; j++)
        {
            if ((game_table[j + 1][i] == 'O' || j + 1 == n))
            {
                Brick[i]>j?k = j + 1:k = Brick[i];
                for (; k-- > 0 && j - k >= 0;)
                {
                    game_table[j - k][i] = '#';
                }
                i++, j = n;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << game_table[i][j];
        }
        cout << endl;
    }
    return 0;
}
