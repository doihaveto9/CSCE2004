#include <iostream>
#include <iomanip>
#include <cctype>
#include <cmath>
using namespace std;
int main(){
	double xRad = 0;
	int Nterms = 0;
	double Nfact = 1;
	float xexpN = 0;
	float sincount = 0;
	float estsinx = 0;
	float errsinx = 0;
	float coscount = 0;
	float estcosx = 1;
	float errcosx = 0;

	//Enter values for X & N
	cout << "Enter a Radian value for x" << endl;
	cin >> xRad;
	if (xRad >= 0){
		cout << "Enter a value for the number of terms N: ";
		cin >> Nterms;
		if (Nterms >= 1){
			estsinx = xRad;

			//Forming of table
			cout << setw(15) << "N" << setw(15) << "N!" << setw(15) << "x^N" << setw(15) << "Sin(x)" << setw(15) << "Cos(x)" << endl;

			for (int N = 1; N <= Nterms; N++){
				Nfact = Nfact * N;
				if (N > 1){
					if (N % 2 == 0){
						coscount = coscount + 1;
						estcosx = estcosx + (pow(-1,coscount) * (pow(xRad, N) / Nfact));
					}
					else{
						sincount = sincount + 1;
						estsinx = estsinx + (pow(-1,sincount) * pow(xRad, N) / Nfact);
					}
				}
				cout << setw(15) << N << setw(15) << scientific << Nfact << setw(15) << scientific << pow(xRad, N) << setw(15) << setprecision(5) << fixed << estsinx << setw(15) << setprecision(5) << fixed << estcosx << endl;
			}
			cout << "The true value of Sin(x) is " << sin(xRad) << endl;
			errsinx = estsinx - sin(xRad);
			cout << "This creates an error value of " << scientific << errsinx << endl;
			cout << "The true value of Cos(x) is " << fixed << cos(xRad) << endl;
			errcosx = estcosx - cos(xRad);
			cout << "This creates an error value of " << scientific << errcosx << endl;
		}
		else
		return 0;
	else
	return 0;
	}
