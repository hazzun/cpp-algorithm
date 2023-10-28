#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int answer = 0;
    
    sort(d.begin(), d.end());
    for(int i=0; i<d.size(); i++){
        budget -= d[i];
        if(budget < 0) break;
        else answer++;
    }
    
    return answer;
}

/*
1. 주어진 배열을 정렬
2. for문 돌려서 budget 보다 작은지 확인 
    -> 작다면 budget - d[i]
    -> count ++
    if) budget이 0보다 작아지면 리턴
*/