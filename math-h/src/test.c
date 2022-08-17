#include <stdio.h>
#include <math.h>

int main() {
    // const double nan = 0.0/0.0;
    // const double inf = 1.0/0.0;
    // if (__builtin_isnan(-nan)) {
    //     printf("Is nan \n");
    // } else {
    //     printf("%lf \n", nan);
    // }
    // if (__builtin_isinf(-inf)) {
    //     printf("Is infinity \n");
    // } else {
    //     printf("%lf \n", inf);
    // }


    // All is output as nan
    /*
    printf("sin NaN = %lf \n", sin(NAN));
    printf("sin +NaN = %lf \n", sin(+NAN));
    printf("sin -NaN = %lf \n", sin(-NAN));
    printf("sin infinity = %lf \n", sin(INFINITY));
    printf("sin +NaN = %lf \n", sin(+INFINITY));
    printf("sin -NaN = %lf \n", sin(-INFINITY));
    */

    const long double nan = 7ff800000000000f;
    printf("%Lf \n", nan);
    if (__builtin_isnan(-nan)) {
        printf("Is nan \n");
    } else {
        printf("Not nan \n");
    }
    return 0;
}