#include <iostream>
#include <cmath>
#include <iomanip>

#define EPSILON 1e-10
#define MAX_TIMES 100

using namespace std;

double f(double x){
    return 2 * pow(x, 3) - pow(x, 2) - 4 * x + 2;
}

double df(double x){
    return 6 * pow(x, 2) - 2 * x - 4;
}

int main(void){
    double x[MAX_TIMES];
    double grad[MAX_TIMES];
    double y[MAX_TIMES];
    double alpha;

    cout << "初期点x0:"; cin >> x[0];

    for(int i = 0; i < MAX_TIMES; i++){
        grad[i] = df(x[i]);
        y[i] = f(x[i]);
        x[i+1] = x[i] - y[i]/grad[i];
        cout << "i:" << i << '\t' << "x[i]:" << x[i] << '\t' << "df[i]:" << grad[i] << '\t' << "f[i]:" << y[i] << endl;
        if(abs(x[i+1] - x[i]) < EPSILON){
            break;
        }
    }

    return 0;
}
