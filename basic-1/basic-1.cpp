//CPP functions practice

#include <iostream>
#include <exception>

using namespace std;

double addi(double a, double b){
    double f = a + b;
    return f;
}

double subt(double a, double b){
    double f = a - b;
    return f;
}

double mulp(double a, double b){
    double f = a * b;
    return f;
}

double divs(double a, double b){
    double f = a / b;
    return f;
}

int main (){
    double a, b, f;
    int mode;
    try{
        cout << "Calculator" << endl;
        cout << "Which calculation do you want to do?" << endl;
        cout << "1 = add, 2 = sub, 3 = mul, 4 = div" << endl;
        cin >> mode;
        if(mode < 1 || mode > 4) throw -1;
        if (cin.fail()) throw -2;
        cout << "What is your first number?" << endl;
        cin >> a;
        cout << "What is your second number?" << endl;
        cin >> b;
    }
    catch(int & err){
        cout << "Error: " << err << endl;
        return err;
    }

    switch(mode){
        case 1: 
            f = addi(a,b);
            break;
        case 2:
            f = subt(a,b);
            break;
        case 3:
            f = mulp(a,b);
            break;
        case 4:
            if(b == 0){
                cout << "Cannot calculate division" << endl;
            }
            else{
                f = divs(a,b);
            }
            break;
        default: break;
    }

    cout << "The result is " << f << endl;
    
    return 0;
}