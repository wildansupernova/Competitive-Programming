#include <bits/stdc++.h>

using namespace std;

//https://practice.geeksforgeeks.org/problems/maximum-tip-calculator/0
//Maximum Tip Calculator

typedef vector<int>  lv;
typedef vector<lv>  lvv;
typedef vector<lvv>  tigad;

int maxnya(int a, int b){
    if(a>=b){
        return a;
    }
    return b;
}
int hasil(int arr1[],int arr2[],int x,int y,int n,tigad *memo){
    if(n==0|| (x==0 && y==0)) {  
        return 0;
    }
    if((*memo)[x][y][n]!=-1){
        return (*memo)[x][y][n];
    }
    if(y==0){
        //int a = arr1[n-1]+ hasil(arr1,arr2,x-1,y,n-1,memo);
        //int b = hasil(arr1,arr2,x,y,n-1,memo);
        (*memo)[x][y][n]= arr1[n-1]+ hasil(arr1,arr2,x-1,y,n-1,memo);;
        return (*memo)[x][y][n];
    } else if(x==0){
        //int a = arr2[n-1]+ hasil(arr1,arr2,x,y-1,n-1,memo);
        //int b = hasil(arr1,arr2,x,y,n-1,memo);
        (*memo)[x][y][n] = arr2[n-1]+ hasil(arr1,arr2,x,y-1,n-1,memo);
        return (*memo)[x][y][n];
    } else{
        int a = arr1[n-1]+ hasil(arr1,arr2,x-1,y,n-1,memo);
        int b = arr2[n-1]+ hasil(arr1,arr2,x,y-1,n-1,memo);
        //int c = hasil(arr1,arr2,x,y,n-1,memo);
        (*memo)[x][y][n] = maxnya(a,b);
        return  (*memo)[x][y][n];
    }


    
}


int main(){

    int t;
    scanf("%d",&t);

    while(t){
        int n,x,y;
        scanf("%d %d %d",&n,&x,&y);
                if(x+y<n){
            y=n-x;
        }
        int arr1[n];
        for(int i=0;i<n;i++){
            scanf("%d",&arr1[i]);
        }
        cin.ignore(1000, '\n');
        int arr2[n];
        for(int i=0;i<n;i++)
            scanf("%d",&arr2[i]);
        cin.ignore(1000, '\n');
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