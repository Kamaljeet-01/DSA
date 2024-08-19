//Bit_Manipulation

// Convert Decimal to Binary:    TC : log2(n)   SC : log2(n) 
//CODE:

#include <iostream>
#include<algorithm>
using namespace std;
string toBinary(int num){
    string res="";
    while(num!=1){
        if(num%2==1) res+="1";
        else res+="0";
        num/=2;
    }
    res+="1";
    reverse(res.begin(),res.end());
    return res;
}
int main() {
    int num;
    cin>>num;
    string result = toBinary(num);
    cout<<result;
    return 0;
}



//CODE:

#include <iostream>
#include<algorithm>
using namespace std;
int toDecimal(string res){
    int num=0,p2=1;
    int len = res.length();
    for(int i= len - 1;i>=0;i--){
        if(res[i]=='1') num+=p2;
        p2*=2;
    }
    return num;
}
int main() {
    string res;
    cin>>res;
    int result = toDecimal(res);
    cout<<result;
    return 0;
}

//Shift operator :
//general trick formula :
//num << k  is equivalent to (num * (2^k))
//num >> k  is equivalent to (num / (2^k))

//Not operator :

//~(+ve number)  =  -(number + 1)
//~(-ve number)  =  +(number - 1)

