#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
using namespace std;
#include <vector>

int main()
{
    int i, j, k, pos, min, cnt = 1;
    vector<int> ans;
    ans = {45, 13, 12, 16, 9, 5, 7, 11, 100};
    if (ans.size() < 2)
    {
        printf("%d", ans.size());
        return 0;
    }

    vector<int> merge;
    sort(ans.begin(), ans.end());
    merge.push_back(ans[0] + ans[1]);

    for (i = 2; i < ans.size();)
    {
        if (ans[i] + merge[0] > ans[i] + ans[i + 1])
        {
            merge.push_back(ans[i] + ans[i + 1]);
            i += 2;
            cnt++;
        }
        else if (merge[0] < ans[i] && merge[1] < ans[i])
        {
            merge.push_back(merge[0] + merge[1]);
            merge.erase(merge.begin());
            merge.erase(merge.begin());
            cnt++;
        }
        else
        {
            merge.push_back(ans[i] + merge[0]);
            cnt++;
            merge.erase(merge.begin());
            i++;
        }
        if (ans.size() - i == 1 && merge.size() == 1)
        {
            cnt++;
            break;
        }
    }
    printf("%d", cnt);

    return 0;
}
