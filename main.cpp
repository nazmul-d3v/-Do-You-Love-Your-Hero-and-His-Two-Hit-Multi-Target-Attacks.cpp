#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while(t--)
    {
        int k;
        cin >> k;

        vector<pair<int,int>> points;

        if(k == 0)
        {
            cout << 1 << "\n0 0\n"; // safest output
            continue;
        }

        int y = 0;
        int currentX = 0; // VERY IMPORTANT

        while(k > 0)
        {
            int remainingSlots = 500 - points.size();

            int m = 1;

            while(m <= remainingSlots && (m*(m-1))/2 <= k)
            {
                m++;
            }
            m--;

            for(int i = 0; i < m; i++)
            {
                points.push_back({currentX++, y});
            }

            k -= (m*(m-1))/2;
            y++;
        }

        cout << points.size() << "\n";

        for(auto &p : points)
        {
            cout << p.first << " " << p.second << "\n";
        }
    }
}
