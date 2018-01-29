#include <bits/stdc++.h>

using namespace std;


bool isstringbener(string s ){
   int panjang = s.length();
   if (panjang ==1 ||panjang ==0){
	 return false;
   } else{
      char a = s[0], b=s[1];
      int i = 2;
      int bener = true;
      if (a==b){
        bener =false;
      } else{
                while(i<panjang && bener ){
                    if (i %2 ==0){
                        if (s[i]!=a){
                            bener=false;
                        }
                    } else{
                        if(s[i]!=b){
                            bener=false;
                        }
                    }
                    i++;
                }


            
      }
      return bener;

      
	}
}
/*string buatstrdari2(char a, char b, string s){
    int panjang = s.length();
    string baru="";
    for(int i=0;i<panjang;i++){
        if (s[i]==a || s[i]==b){
            baru.push_back(s[i]);
        }
    }
}*/



int  isbenercekdari2huruf(string s, char a, char b){
    int panjang = s.length();
    if (panjang == 0 || panjang == 1){
        return 0;

    } else{
        int count = 0;
        string stemp = "";
        for(int i =0;i<panjang;i++){
            if (s[i] ==a || s[i]==b){
                stemp.push_back(s[i]);

            }
        }
        int panjangtemp = stemp.length();

        if (isstringbener(stemp)){
            return panjangtemp;
        } else{
            return 0;

        }

    }
}

int cariterpanjang (string s){
    int max  = 0;

    for(int i = 0;i<25;i++){
        for(int j = i+1;j<=25;j++){
            int hasilcek = isbenercekdari2huruf(s,i+'a',j+'a');
            if (hasilcek>max){
                max = hasilcek;
            }

        }
    }
    return max;
}
int maxLen(string s){
    // Complete this function

   return cariterpanjang(s);

}

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int result = maxLen(s);
    cout << result << endl;
    return 0;
}

