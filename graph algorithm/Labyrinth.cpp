#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;

    vector<int> adj[n];
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++)
        {
            if (s[j] == '.')
                adj[i].push_back(1);
            else if (s[j] == 'A')
            {
                adj[i].push_back(0);
                x1 = i;
                y1 = j;
            }

            else if (s[j] == 'B')
            {
                adj[i].push_back(1);
                x2 = i;
                y2 = j;
            }
            else
                adj[i].push_back(-1);
        }
    }
    int matrix[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            matrix[i][j] = 1000000;
        }
    }
    matrix[x1][y1] = 0;

    queue<pair<int, int>> q;
    q.push(make_pair(x1, y1));

    while (!q.empty())
    {

        int indx = q.front().first;
        int indy = q.front().second;
        int dist = matrix[indx][indy];
        q.pop();
        // check top
        if (indx > 0 && adj[indx - 1][indy] == 1)
        {

            if (matrix[indx - 1][indy] > 1 + dist)
            {
                matrix[indx - 1][indy] = 1 + dist;
                q.push(make_pair(indx - 1, indy));
            }
        }
        // check bottom
        if (indx < n - 1 && adj[indx + 1][indy] == 1)
        {
            if (matrix[indx + 1][indy] > 1 + dist)
            {
                matrix[indx + 1][indy] = 1 + dist;
                q.push(make_pair(indx + 1, indy));
            }
        }
        // check left
        if (indy > 0 && adj[indx][indy - 1] == 1)
        {
            if (matrix[indx][indy - 1] > 1 + dist)
            {
                matrix[indx][indy - 1] = 1 + dist;
                q.push(make_pair(indx, indy - 1));
            }
        }

        // check right
        if (indy < m - 1 && adj[indx][indy + 1] == 1)
        {
            if (matrix[indx][indy + 1] > 1 + dist)
            {
                matrix[indx][indy + 1] = 1 + dist;
                q.push(make_pair(indx, indy + 1));
            }
        }
    }
    adj[x1][y1] = 1;

    int x = x2, y = y2, cnt = matrix[x2][y2];

    string ans(cnt, '*');

    cnt = cnt - 1;

    if (matrix[x2][y2] != 1000000)
    {
        cout << "YES" << endl;
        cout << matrix[x2][y2] << endl;
        // path
        while (x != x1 || y != y1)
        {

            // right
            if (y < m - 1 && adj[x][y + 1] == 1)
            {
                if ((matrix[x][y] - matrix[x][y + 1]) == 1)
                {
                    ans[cnt] = 'L';
                    cnt = cnt - 1;
                    y = y + 1;
                }
            }
            // left
            if (y > 0 && adj[x][y - 1] == 1)
            {
                if ((matrix[x][y] - matrix[x][y - 1]) == 1)
                {
                    ans[cnt] = 'R';
                    cnt = cnt - 1;

                    y = y - 1;
                }
            }
            // top
            if (x > 0 && adj[x - 1][y] == 1)
            {
                if ((matrix[x][y] - matrix[x - 1][y]) == 1)
                {

                    ans[cnt] = 'D';
                    cnt = cnt - 1;
                    x = x - 1;
                }
            }
            // bottom
            if (x < n - 1 && adj[x + 1][y] == 1)
            {
                if ((matrix[x][y] - matrix[x + 1][y]) == 1)
                {
                    ans[cnt] = 'U';
                    cnt = cnt - 1;

                    x = x + 1;
                }
            }
        }
        cout << ans << endl;
    }

    else
        cout << "NO" << endl;
    return 0;
}