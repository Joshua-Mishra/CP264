#include <stdio.h>
#include <stdlib.h>
#include "bigint.h"

BIGINT bigint(char *p) {
  BIGINT bn = {0};
  if (p == NULL) 
    return bn;
  else if (!(*p >= '0' && *p <= '9')) {// not begin with digits 
    return bn;
  }
  else if (*p == '0' && *(p+1) == '\0') {// just "0"
    dll_insert_end(&bn, dll_node(*p -'0'));
    return bn;
  }  
  else { 
    while (*p) {
      if (*p >= '0' && *p <= '9' ){
        dll_insert_end(&bn, dll_node(*p -'0'));
      } else {
        dll_clean(&bn);
        break;
      }
      p++;
    }
    return bn;
  }
}

BIGINT bigint_add(BIGINT op1, BIGINT op2) {
// your code
    BIGINT sum = bigint(NULL);
    NODE *p1 = op1.end;
    NODE *p2 = op2.end;
    int c = 0,a,b,s;
        while(p1 || p2) {
            //Addition algoithm
            a = 0;
            b = 0;
            if(p1){a = p1->data; p1 = p1->prev;}
            if(p2){b = p2->data; p2 = p2->prev;}
            if(c == 1) {s = (a+b+1)%10; c = (a+b+1)/10;}
            else{s = (a+b)%10; c = (a+b)/10;}
            NODE *n = dll_node(s);
            dll_insert_start(&sum,n);
        }
        if(c==1)
        {
            NODE *nn = dll_node(1);
            dll_insert_start(&sum,nn);
        }
        return sum;

}

BIGINT bigint_fibonacci(int n) {
// your code
BIGINT f1 = bigint("0");
BIGINT f2 = bigint("1");
BIGINT temp = bigint(NULL);
if(n == 0)
{
    return f1;
}
else if (n==1){
    return f2;
}
else{
  for(int i = 1; i < n; i++)
  {
    temp = bigint_add(f1,f2);
    f1 = f2;
    f2 = temp;
  }
  return f2;

}
}
