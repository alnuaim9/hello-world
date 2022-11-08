#include <iostream>
using std::cout; using std::endl;using std::fixed;using std::cin;
#include <iomanip>
using std::setprecision;
#include <cmath>
using std::abs;

double fn(double x){
    double fn_value;
    fn_value=-6*pow(x,2)+5*x+3;
    return fn_value;
}
double integral(double x){
    double fn_integral;
    fn_integral=-2*pow(x,3)+(5.0/2)*pow(x,2)+3*x;
    return fn_integral;
}
double EstimateWithTraps(double a,double b,double n){
    double fn_value=0 , sum_area,x=0;
    for (x=0;x<=1;x+=((b-a)/n)){
    if ((x==0) || (x==1)){
        fn_value+=fn(x);
}
    else{
        fn_value+=2*fn(x);
}
}
    sum_area=((b-a)/(2*n))*fn_value;
    return sum_area;
}
int main(){
    double tolerance,trapezoid_value,integral_value;
    double n;
    double a;
    double b;
    cout<<"lower range : ";
    cin>>a;
    cout<<"Upper range : ";
    cin>>b;
    cout<<"Tolerance: ";
    cin>>tolerance;
    cout<<"Initial trapezoid count: ";
    cin>>n;

    integral_value=integral(1);
    trapezoid_value=EstimateWithTraps(a,b,n);
    while(abs(integral_value-trapezoid_value)>tolerance){
        double difference;
        difference=abs(integral_value-trapezoid_value);
        cout<<"Result: "<<trapezoid_value<<", traps: "<<n<<", diff: "<<difference<<endl;
        n*=2;
        trapezoid_value=EstimateWithTraps(a,b,n);
}
    cout<<"Trap count: "<<n<<", estimate: "<<trapezoid_value<<", exact: "
    <<integral_value<<", tolerance: "<<tolerance<<endl;
    return 0;
}