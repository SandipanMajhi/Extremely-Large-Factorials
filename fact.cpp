#include<iostream>
#include<string>

using namespace std;

string big_multiply(string num1, string num2){
    string result[num2.length()];

    for(int i= 0; i<num2.length(); i++){
        result[i] = "";
    }

    for(int i = num2.length()-1; i>=0; i--){
        int carry  = 0;
        for(int j = num1.length()-1; j>=0; j--){
            int prod = (num2[i]-'0') * (num1[j]-'0');
            string in_place = to_string((prod+carry) % 10);
            carry = (prod+carry) / 10;
            result[i] += in_place ;
        }
        if (carry != 0)
            result[i] += to_string(carry) ;
    }

    for(int i=0;i<num2.length(); i++){
        for(int j = 1; j<num2.length()-i;j++){
            result[i] =   "0" +  result[i] ;
        }
    }

    int reslen = -1;
    for(int i= 0; i<num2.length(); i++){
        if(int(result[i].length()) > reslen)
            reslen = int(result[i].length()); 
    }

    int carry = 0;
    string final_result="";
    for(int pos = 0; pos< reslen; pos++){
        int sum = carry;
        for(int ladder = 0; ladder < num2.length() ; ladder++){
            if(pos < int(result[ladder].length())){
                sum += (result[ladder][pos] - '0');
            }else{
                sum += 0;
            }
        }

        string in_place = to_string((sum)%10);
        carry = sum /10;
        final_result = in_place + final_result;
    }

    if(carry!= 0)
        final_result = to_string(carry) + final_result;

    return final_result;
}

string factorial(int num1){
    string result="1";

    while(num1 > 0){
        result = big_multiply(result,to_string(num1));
        num1--;
    }

    return result;
}

int main() {
	int t;
	cin >> t;
	int num;
	string result[t];
	
	
	for(int i=0 ; i<t;i++){
	    cin >> num;
	    result[i] = factorial(num);
	}
	
	for(int i=0 ; i<t;i++){
	    cout << result[i] << endl;
	}
	
}
