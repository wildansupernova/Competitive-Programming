//https://practice.geeksforgeeks.org/problems/min-cut-square/0
//Min Cut square

#include <bits/stdc++.h>

using namespace std;




int minimum(int a,int b){
    if(a<=b)
        return a;
    return b;
}

int hasil(int a, int b){
    int tab[a+1][b+1];
    //Inisiasi
    for(int i=0;i<=b;i++){
        tab[1][i] = i;
    }
    for(int i=0;i<=a;i++){
        tab[i][1] = i;
    } 
    for(int i=0;i<=a;i++){
        tab[i][i] = 1;
    }   
    //Mulai mengisi
    for(int i=2;i<=a;i++){
        for(int j=2;j<=b;j++){
            //Minimum vertikal;
            if(i!=j){
                int minver = INT_MAX;
                for(int k=1;k<=i/2;k++){
                    minver = minimum(minver,tab[k][j]+tab[i-k][j]);
                }
                int minhor = INT_MAX;
                for(int k=1;k<=j/2;k++){
                    minhor = minimum(minhor,tab[i][k]+tab[i][j-k]);
                }
                tab[i][j] = minimum(minhor,minver);        
            }

        }
    }
    /*for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            cout<<tab[i][j]<<" ";        
        }
        cout<<endl;
    }*/
    
    return tab[a][b];
}






int main(){

    int t;
    scanf("%d",&t);
    while(t){
        int a,b;
        scanf("%d %d",&a,&b );
        if(a<=b){
            printf("%d\n",hasil(a,b));
        } else{
            printf("%d\n",hasil(b,a));
        }
        
        t--;
    }


}