#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int answer = 0;
    
    for(int i=1; i<land.size(); i++){
        land[i][0] += max({land[i-1][1], land[i-1][2], land[i-1][3]});
        land[i][1] += max({land[i-1][0], land[i-1][2], land[i-1][3]});
        land[i][2] += max({land[i-1][1], land[i-1][0], land[i-1][3]});
        land[i][3] += max({land[i-1][1], land[i-1][2], land[i-1][0]});
    }
    answer = max({land[land.size()-1][0],land[land.size()-1][1], land[land.size()-1][2], land[land.size()-1][3]});

    return answer;
}