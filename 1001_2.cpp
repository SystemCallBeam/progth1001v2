#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m, i, j;
    cin >> n >> m;
    char game_table[n][m + 1] = {};
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> game_table[i][j];
        }
    }
    int Brick[m];
    for (i = 0; i < m; i++)
    {
        cin >> Brick[i];
    }
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if ((j + 1 == n) && (game_table[j][i] == '.'))
            {
                for (int k = j; k > 0 && k > j - Brick[i]; k--)
                {
                    game_table[k][i] = '#';
                }
                i++;
                j = -1;
            }
            else if (game_table[j][i] == 'O')
            {
                for (int k = j - 1; k > 0 && k >= j - Brick[i]; k--)
                {
                    game_table[k][i] = '#';
                }
                i++;
                j = -1;
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
