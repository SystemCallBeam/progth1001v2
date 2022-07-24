#include <bits/stdc++.h>
using namespace std;

int i, j;
void print(char (*game_table)[20][20+1], int n, int m);
void solve(int (*Brick)[20], char (*game_table)[20][20+1], int n, int m);

int main()
{
    int n, m, Brick[20];
    char game_table[20][20+1] = {};
    cin >> n >> m;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cin >> game_table[i][j];
        }
    }

    for (i = 0; i < m; i++)
    {
        cin >> Brick[i];
    }

    solve(&Brick[], &game_table[20][], n, m);
    print(&game_table[20][], n, m);

    return 0;
}

void print(char (*game_table)[20][20+1], int n, int m){
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << game_table[i][j];
        }
        cout << endl;
    }
}

void solve(int (*Brick)[20], char (*game_table)[20][20+1], int n, int m){
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n && Brick[i] > 0; j++)
        {
            if ((j + 1 == n) && (game_table[j][i] == '.'))
            {
                for (int k = j; k > j - Brick[i]; k--)
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
}
        