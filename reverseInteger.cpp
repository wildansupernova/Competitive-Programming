//https://leetcode.com/problems/reverse-integer/description/
//reverse Integer
class Solution {
public:
    int reverse(int x) {
        long long temp=0;
        long long y= x;
        while(y!=0){
            temp = 10*temp + (y%10);
            y/=10; 
        }
        if((temp>= 2147483648*(-1)) && temp<=2147483647){
            return (int)temp;
        }
        return 0;
    }
};