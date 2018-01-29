//https://leetcode.com/problems/median-of-two-sorted-arrays/description/
//Median of Two Sorted Arrays
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  void getMedian(vector<int>& nums1, vector<int>& nums2,int im, int jm, int in, int jn,double *hasil1,double *hasil2){
        int m = jm-im+1;
        int n = jn-in+1;
        double bagi=2;
        if(m%2==0){
            //mGenap
            *hasil1 = (nums1[(m/2)+im]+ nums1[(m/2)+im-1])/bagi;
        } else if(m%2==1){
            //mGanjil
            *hasil1 = nums1[(m/2)+im];
        }

        if(n%2==0){
            //mGenap
            *hasil2 = (nums2[(n/2)+in]+ nums2[(n/2)+in-1])/bagi;
        } else if(n%2==1){
            //mGanjil
            *hasil2 = nums2[(n/2)+in];
        }
    }
    double minim(double a, double b){
        if(a<b)
            return a;
        return b;
    }
    double maxim(double a, double b){
        if(a>b)
            return a;
        return b;
    }
    double medianUtil(vector<int>& nums1, vector<int>& nums2,int im, int jm, int in, int jn){
        int m = jm-im+1;
        int n = jn-in+1;
        int total = m+n;
        double medM, medN; 

        getMedian(nums1,nums2,im,jm,in,jn,&medM,&medN);

        if(total==3){
            vector<int> temp;
            for(int i=im;i<=jm;i++){
                temp.push_back(nums1[i]);
            }
            for(int i=in;i<=jn;i++){
                temp.push_back(nums2[i]);
            }
            sort(temp.begin(),temp.end());
            return temp[1];
        }else if(m==2 && n==2){
                double bagi=2;
                return (max(nums1[im],nums2[in]) + min(nums1[jm],nums2[jn]))/bagi;
        } else if(m==1 && n==1){
                double bagi=2;
                return (nums1[im]+nums2[in])/bagi;
        } else if(m==1){
            vector<int> temp;
            if(medM>medN){

                temp.push_back(nums1[im]);
                for(int i=in+(n/2);i<=jn;i++){
                    temp.push_back(nums2[i]);
                }


            } else{
                temp.push_back(nums1[im]);
                for(int i=in;i<=in+(n/2);i++){
                    temp.push_back(nums2[i]);
                }
            }
            sort(temp.begin(),temp.end());
            int length = temp.size();
            if(length%2==0){
                double bagi =2;
                return (temp[length/2]+temp[(length/2)-1])/2;
            } else{
                return temp[length/2];
            }
        }   else if(n==1){
            vector<int> temp;
            if(medM>medN){

                temp.push_back(nums2[in]);
                for(int i=im;i<=im+(m/2);i++){
                    temp.push_back(nums1[i]);
                }


            } else{
                temp.push_back(nums2[in]);
                for(int i=im+(m/2);i<=jm;i++){
                    temp.push_back(nums1[i]);
                }
            }
            sort(temp.begin(),temp.end());
            int length = temp.size();
            if(length%2==0){
                double bagi =2;
                return (temp[length/2]+temp[(length/2)-1])/2;
            } else{
                return temp[length/2];
            }
        } 
        if(medM==medN){
            return medM;
        if(medM<medN){
            return medianUtil(nums1,nums2,im+(m/2),jm,in,in+(n/2));
        } else{
            return medianUtil(nums1,nums2,im,im+(m/2),in+(n/2),jn);
        }
    }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int hasil = m+n;
        if(m==0 && n!=0){
            double bagi=2;
            if(n%2==0)
                return (nums2[n/2]+nums2[(n/2) -1])/bagi;
            else 
                return nums2[n/2];
        } else if(m!=0 && n==0){
            double bagi=2;
            if(m%2==0)
                return (nums1[m/2]+nums1[(m/2) -1])/bagi;
            else 
                return nums1[m/2];            
        }
        return medianUtil(nums1,nums2,0,m-1,0,n-1); 
    }

};


/*
                if(m==1){
                    double medM, medN; 
                    getMedian(nums1,nums2,im,jm,in,jn,&medM,&medN);
                    if(medM==medN){
                        return medM;
                    } else if(medM>medN){
                        return minim(nums1[im],nums2[jn]);
                    } else if(medM<medN){
                        return maxim(nums1[im],nums2[in]);
                    }

                } else if(n==1){
                    double medM, medN; 
                    getMedian(nums1,nums2,im,jm,in,jn,&medM,&medN);
                    if(medM==medN){
                        return medM;
                    } else if(medM>medN){
                        return maxim(nums1[im],nums2[in]);
                    } else if(medM<medN){
                        return minim(nums1[jm],nums2[in]);
                    
                }
            } */