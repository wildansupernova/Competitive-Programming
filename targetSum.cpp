//https://leetcode.com/problems/target-sum/description/
#include <bits/stdc++.h>
using namespace std;
///Brute Force Solution
class Solution {
public:


    int countWays(vector<int>& nums,int idx, int target){
        if(idx==0){
            if(target==0){
                return 1;
            } else{
                return 0;
            }
        } else{

            return countWays(nums,idx-1,target-nums[idx-1]) + countWays(nums,idx-1,target+nums[idx-1]) ;
        }
    }


    int findTargetSumWays(vector<int>& nums, int S) {
        return this->countWays(nums,nums.size(),S);
    }
};

int main(){

    int n;
    cin>>n;
    vector<int> temp(n,0);
    for(int i=0;i<n;i++){
        cin>>temp[i];
    }

    int s;
    cin>>s;
    Solution solusi;
    cout<<solusi.findTargetSumWays(temp,s)<<endl;

}