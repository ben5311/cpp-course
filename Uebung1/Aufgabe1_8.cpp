#include <iostream>
	using namespace std;
    int main() {
        int n1, n2, a, sum1=0, sum2=0, sum3=0, sum4=0;
        cout << "Geben Sie bitte zwei Zahlen ein: ";
        cin >> n1 >>n2;

        if (n1>=n2){
            a=n1;
            n1=n2;
            n2=a;
        }

        for(int j=n1; j<=n2; j++){            // for Schleife
            sum1+=j;
        }

        int i=n1;
        while (i<=n2){                    // while Schleife
            sum2+=i;
            i+=1;
        }

        int h=n1;
        do                             // do while Schleife
        {
            sum3+=h;
            h+=1;
        } while (h<=n2);
        
        sum4=(n2*(n2+1)-(n1-1)*n1)/2;                       // ohne Schleife
        cout << sum1 << " " << sum2 << " " << sum3 << " " << sum4 << " ";
        return 0;
    }