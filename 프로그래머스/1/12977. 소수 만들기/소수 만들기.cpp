#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

bool sosuCheck(int k){
    int chk = 0;
    for(int i=1; i<=k; i++){
        if(k % i == 0)
            chk++;
    }
    if(chk == 2) return true;
    else return false;
}

int solution(vector<int> nums) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int answer = 0;
    vector<int> tmp;
    for(int i=nums.size(); i>0; i--){
        if(i <= 3)
            tmp.push_back(1);
        else
            tmp.push_back(0);
    }
    
    do{
        int sum = 0;
        for(int i=0; i< nums.size(); i++){
            if(tmp[i] == 1){
                sum += nums[i];
            }
        }
        if(sosuCheck(sum))
            answer++;
    } while (next_permutation(tmp.begin(), tmp.end()));

    return answer;
}