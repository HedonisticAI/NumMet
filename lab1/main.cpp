#include <iostream>
#include <cmath>
#include <windows.h>
#define PI 3.141592
#define e 2.718281
using namespace std;
double iterMethod(double firstX, double accuracy, double (*iterFunc)(double), double (*f)
(double));
// A0 - начальное приближение метода хорд
// B0 - начальное приближение метода касательных
double combMethod(double A0, double B0, double accuracy,
double (*chordsIterFunc)(double, double), double (*tangentsFunc)(double),
double (*f)(double));
double iterMethod(double firstX, double accuracy, double (*iterFunc)(double), double (*f)
(double))
int i = 1;
double prevX, nextX = firstX;
cout << "X" << 0 << " = " << firstX << endl;
do
{
prevX = nextX;
nextX = iterFunc(prevX);
cout << "X" << i << " = " << nextX << endl;
i++;
}
while (abs(f(nextX)) > accuracy);
return nextX;
}
double combMethod(double A0, double B0, double accuracy,
double (*chordsFunc)(double, double), double (*tangentsFunc)(double), double
(*f)(double))
{
int i = 1;
cout << "A" << 0 << " = " << A0 << " "
<< "B" << 0 << " = " << B0 << endl;
do
{
if(A0 == B0)return A0;
A0 = chordsFunc(A0, B0);
B0 = tangentsFunc(B0);
cout << "A" << i << " = " << A0 << " "
<< "B" << i << " = " << B0 << endl;
i++;
}
while (abs(f(abs(A0+B0)/2.)) > accuracy);
return A0;
}
double f1(double x) {return pow(x, 3) - 3*x + 12*x-12;}
double iterFunc1(double x) {return x - f1(x)/9;}
double f2(double x) {return  x*(pow((x+1,2)) );}
double iterFunc2(double x) {return x - f2(x)/7.5;}
double f3(double x) {return ctg(x)-x/4;}
double chordsIterFunc3(double x) {return x - f3(x)*(x - 1.2)/(f3(x) - f3(1.2));}
double f4(double x) {return pow(x, 3) - 3*pow(x, 2) + 9*x -8;}
double tangentsIterFunc4(double x) {return x- f4(x)/(3*pow(x, 2) - 6*x + 9);}
double f5(double x) {return  pow(x,3)+0.1*pow(x,2)2+0.4*x-1.2;}
double chordsIterFunc5(double x, double fixedX)
{return x - f5(x)*(fixedX - x)/(f5(fixedX) - f5(x));}
double tangentsIterFunc5(double x) {return x- f5(x)/(6*pow(x, 2) - 6*x - 12);}
int main()
{
cout << "Task 2.1\n";
double e1 = iterMethod(0, 0.001, iterFunc1, f1);
cout << "Approximate root x = " << e1 << endl;
cout << "f(x) = " << f1(e1) << endl;
cout << "Task 2.2\n";
double e2 = iterMethod(0, 0.001, iterFunc2, f2);
cout << "Approximate root x = " << e2 << endl;
cout << "f(x) = " << f2(e2) << endl;
cout << "Task 3.1\n";
double e3 = iterMethod(1, 0.0001, chordsIterFunc3, f3);
cout << "Approximate root x = " << e3 << endl;
cout << "f(x) = " << f3(e3) << endl;
cout << "Task 3.2\n";
double e4 = iterMethod(1, 0.001, tangentsIterFunc4, f4);
cout << "Approximate root x = " << e4 << endl;
cout << "f(x) = " << f4(e4) << endl;
cout << "Task 3.3\n";
double e5 = combMethod(0, 4, 0.001, chordsIterFunc5, tangentsIterFunc5, f5);
cout << "Approximate root x = " << e5 << endl;
cout << "f(x) = " << f5(e5) << endl;
system("pause");
return 0;
}
