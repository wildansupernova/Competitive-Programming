#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    string s;
    cin >> s;
    int panjang = s.length();
    int i=0,counter=0;
    while(i<panjang){
        if (i==0){
           counter++;
        } else{
            if (s[i]>='A' && s[i]<='Z'){
                counter++;
            }
        }
	
        i++;
    }
    
    cout<<counter<<endl;
    return 0;
    
}

