#include <bits/stdc++.h>

using namespace std;

//https://practice.geeksforgeeks.org/problems/maximum-tip-calculator/0
//Maximum Tip Calculator

typedef vector<short>  lv;
typedef vector<lv>  lvv;
typedef vector<lvv>  tigad;

short maxnya(short a, short b){
    if(a>=b){
        return a;
    }
    return b;
}
short hasil(short arr1[],short arr2[],short x,short y,short n,tigad *memo){
    if(n==0)   
        return 0;
    
    if((*memo)[x][y][n]!=-1){
        return (*memo)[x][y][n];
    }

        if(x==0 && y>0){
            (*memo)[x][y][n] =arr2[n-1]+ hasil(arr1,arr2,x,y-1,n-1,memo);
            return (*memo)[x][y][n];

        } else if(x>0 && y==0){
             (*memo)[x][y][n] = arr1[n-1]+ hasil(arr1,arr2,x-1,y,n-1,memo);
            return (*memo)[x][y][n];
        } else if(x>0 &&y>0){
                short a = arr1[n-1]+ hasil(arr1,arr2,x-1,y,n-1,memo);
                short b = arr2[n-1]+ hasil(arr1,arr2,x,y-1,n-1,memo);
                (*memo)[x][y][n] = maxnya(a,b);
                return  (*memo)[x][y][n];

        } else if(x==0 && y==0){
            return 0;
        }
    
}


int main(){

    short t;
    //scanf("%d",&t);
    cin>>t;
    while(t){
        short n,x,y;
        //scanf("%d %d %d",&n,&x,&y);
        cin>>n>>x>>y;
        short arr1[n];
        for(int i=0;i<n;i++){
            //scanf("%d",&arr1[i]);
            cin>>arr1[i];
        }
        short arr2[n];
        for(int i=0;i<n;i++)
            //scanf("%d",&arr2[i]);
            cin>>arr2[i];
        tigad memo;
        for(int i=0;i<=x;i++){
            lvv temp2;
            for(int j=0;j<=y;j++){
                lv temp;
                for(int k=0;k<=n;k++){
                    temp.push_back(-1);
                }
                temp2.push_back(temp);
                temp.clear();
            }
            memo.push_back(temp2);
            temp2.clear();
        }
        cout<<hasil(arr1,arr2,x,y,n,&memo)<<endl;        
        t--;
    }
}