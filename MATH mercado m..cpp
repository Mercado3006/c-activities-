#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <limits>

using namespace std;

int main(){
double a,b,c,discriminant,quadratic,x1,x2,raise1,mul1,form1,form2,form3,form4,D;
a:
cout << " \nEnter value for a: ";
cin >> a;
if (a < 0) {
goto a;
}
b:
cout << " \nEnter value for b: ";
cin >> b;
if (b < 0) {
goto b;
}
c:
cout << " \nEnter value for c: ";
cin >> c;
if (c < 0) {
goto c;
}
x1:
cout << " \nEnter value for x1: ";
cin >> x1;
if (x1 < 0) {
goto x1;
}
x2:
cout << " \nEnter value for x2: ";
cin >> x2;
if (x2 < 0) {
goto x2;
}

system("cls");
cout << "\n*******************************************";
cout << "\n   Formula = ax^2 + bx + c = 0 where: ";
cout << "\n";
cout << "\n    a = " << a;
cout << "\n    b = " << b;
cout << "\n    c = " << c;
cout << "\n    x1 = " << x1;
cout << "\n    x2 = " << x2;
cout << "\n*******************************************";
raise1 = pow(x1,2.0);
mul1 = b * x2;
form1 = a * raise1;
quadratic = form1 + mul1 + c;
cout << "\n   quadratic equation answer: " << quadratic;
form2 = a * c;
form3 = 4 * form2;
form4 = pow(b,2.0);
D = form4 - form3;
cout << "\n";
cout << "\n";
cout << "\n   discriminant value answer: " << D;
cout << "\n";
if ( D > 0 ){
cout << "\n >> It has 2 real and distinct roots <<";
}
else if ( D == 0){
cout << "\n >> It has 1 real root <<";
}
else if ( D < 0 ){
cout << "\n >> It has complex root <<";
}

cout << "\n";

return 0;
}

