#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, i, j;
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
    for (i = 0; i < m; i++)
    {
        cout << i << endl;
        for (j = -1;j > n ; j++)
        {
            if ((game_table[j + 1][i] == 'O' || j + 1 == n))
            {
                for (int k = Brick[i]; k-- > 0 && j - k >= 0; )
                {
                    game_table[j - k][i] = '#';
                }
                i++;
                continue;
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
