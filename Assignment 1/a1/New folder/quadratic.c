#include "quadratic.h"
#include <math.h>
/**
 * Compute and return solution type of given quadratic equation ax*x + bx + c = 0
 *
 * @param a  - quadratic coefficient
 * @param b  - linear coefficient
 * @param c - constant coefficient
 * @return - 0 if not quadratic equation, i.e. a=0;
 *           1 for one unique real solution;
 *           2 for two distinct real solutions;
 *           3 for two complex solutiions
 */
int solution_type(float a, float b, float c){
    if(a == 0){
        return 0;
    }
    float d = b*b - 4*a*c;
    if(d > 0){
        return 2;
    }else if(d == 0){
        return 1;
    }else{
        return 3;
    }
}

/**
 * Compute and return unique or bigger real roots of given quadratic equation ax*x + bx + c = 0 of types 1 and 2.
 * @param a  - quadratic coefficient
 * @param b  - linear coefficient 
 * @param c - constant coefficient
 * @return - the unique real root or the bigger real root if the quadratic equation has two distinct real roots 
             Ohterwise, return 0.
 */
float real_root_big(float a, float b, float c){
    float ans = 0.0;
    if( solution_type(a,b,c) == 1 || solution_type(a,b,c) == 2){
        float d = b*b - 4*a*c; 
        ans = (-b + sqrt(d))/(2*a);
    }
    return ans;
}

/**
 * Compute and return unique or smaller real roots of given quadratic equation ax*x + bx + c = 0 of types 1 and 2.
 * @param a  - quadratic coefficient
 * @param b  - linear coefficient 
 * @param c - constant coefficient
 * @return - 0 if not a == 0
             1 if having two complex solutions
             2 if            the unique real root or the smaller real root if the quadratic equation has two distinct real roots 
             Ohterwise, return 0.
 */
float real_root_small(float a, float b, float c){
        float ans = 0.0;
    if( solution_type(a,b,c) == 1 || solution_type(a,b,c) == 2){
        float d = b*b - 4*a*c; 
        ans = (-b - sqrt(d))/(2*a);
    }
    return ans;
}