#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

#define DBL_RAND (((long double)rand())/ RAND_MAX)

int main(int argc, const char * argv[])
{
    srand((unsigned int)time(NULL));

    long double V1 = 64.0L;//4*4*4
    long long N = 5000000;
    long double Fm = 0;

    for(int i = 0; i<N; ++i)
    {
        long double x = -2.0L + 4.0L*DBL_RAND;
        long double y = -2.0L + 4.0L*DBL_RAND;
        long double z = 4.0L*DBL_RAND;
        if(!(4.0L - x*x - y*y < z  || (4.0L-x*x) < 0))
            Fm+=y*y;
    }

    cout.setf(ios::fixed);
    cout.precision(10);
    cout << "Calculated answer: " << Fm * V1 / N<< endl;
    cout << "Real answer: " << 16.0L * M_PI / 3.0L << endl;
    cout << "Answer delta: " << fabsl(16.0L * M_PI / 3.0L - Fm * V1 / N) << endl;

    return 0;
}