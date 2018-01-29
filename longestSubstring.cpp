//https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
//Longest Substring Without Repeating Characters
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int maxx = 0;
        
        int length = s.length();
        for(int i=0;i<length;i++){
            int count=0;
            unordered_set<char> cek;
            for(int j=i;j<length;j++){
                if(cek.find(s[j])!=cek.end()){
                    break;
                } else{
                    count++;
                    cek.insert(s[j]);
                }
            }
            if(count>maxx){
                maxx=count;
            }
        }
        return maxx;
    }
};