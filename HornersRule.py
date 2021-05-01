#Horner's rule is an algorithm O(C) for evaluating an n's polynomial.

HORNERS_RULE(C, x) //C = array of coefficients of n's ith power. 
    N = 0
    for i = C.length downto 0 
        N = C[i] + x.N
    return N