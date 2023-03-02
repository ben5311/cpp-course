#include <iostream>
#include <cmath>
	using namespace std;
    int main() {
        int a,b,c, result;
        cout << "Geben Sie drei Zahlen ein: ";
        cin >> a >> b >>c;
        if(a>=b){
            if(a>=c){
                result=a;
            }else
            {
                result=c;
            }  
        }else{
           if(b>=c){
                result=b;
            }else
            {
                result=c;
            }   
        }
        cout << "Maximale Zahl: " << result;
        return 0;
    }