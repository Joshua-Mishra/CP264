#include "powersum.h"
/**
 * Depect if overflow in power computing of b to power of n  
 *
 * @param b - the base
 * @param n - the exponent
 * @return - 1 if overflow happens, 0 otherwise
 */
int power_overflow(int b, int n)
{
    int newnum = b;
    for(int i = 1; i < n; i++)
    {
        newnum = newnum * b;
    }
    if(newnum > 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

/**
 * Compute and return b to power of n.  
 *
 * @param b - the base
 * @param n - the exponent
 * @return - b to the power of n if no overflow happens, 0 otherwise
 */
int mypower(int b, int n)
{
    int newnum = b;
    if(power_overflow(b,n) == 0)
    {
        if (n==0)
        {
            return 1;
        }
        for(int i = 1; i < n; i++)
        {
        newnum = newnum * b;
        }
        return newnum;
    }
    else
    {
        return 0;
    }
}


/**
 * Compute and return the sum of powers.
 *
 * @param b - the base
 * @param n - the exponent
 * @return -  the sum of powers if no overflow happens, 0 otherwise 
 */
int powersum(int b, int n)
{
    int sum = 0;
    for(int i = 0; i <= n; i++)
    {
        sum += mypower(b,i);
        if (power_overflow(b,i) == 1)
        {
            return 0;
        }
    }
    if (sum <0)
    {
        sum = 0;
    }
    return sum;
}