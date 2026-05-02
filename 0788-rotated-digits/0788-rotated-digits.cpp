class Solution {
public:
    int rotatedDigits(int n) {
     vector<int> t(n+1, -1);
    t[0]=0;
    int count =0;
    for(int i=1;i<=n;i++){
        int remain=t[i/10]; //solve(num/10)
        if(remain == 2){
            t[i]=2;
            continue;
        }
        int digit_check;
        int d=i%10;
        if(d==0 || d==1 || d==8){
            digit_check = 0;
        }
        else if( d==2 || d==5 || d==6 || d==9){
            digit_check = 1;
        }
        else{
            t[i]=2;
            continue;
        }
        if(remain == 0 && digit_check == 0){
            t[i]=0;
        }
        else{
            t[i]=1;
        }
        if(t[i]==1){
             count++;
        }
    }
    return count;
    }
};