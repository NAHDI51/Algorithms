#Algorithm for checking whether it is possible for the sum of two arbitrary elements of array A to be exactly equal
#to the value of a given key, at O(nlog(n)) time.
                                                            cost    times
SUM_OF_TWO_ELEMENTS(A, key) {   
    for i = 1 to A.length                                   c1      n+1
        if A[i] <= key                                      c2      n
            element = key - A[i]                            c3      O(n)
            j = binary_search(A, A.length, element)         c4      O(n) * O(log(n))

            if j != -1 and j != i                           c5      O(n)
                return true                                 c6      1
    return false
}

Synopsis:
1. key = A[i] + A[j], that means, there exists index i and j such that 0 <= i, j <= A.length. And for index i,
    A[j] = key - A[i].
2. Suppose, our first element index is i. Iterate i through the whole array. 
3. The (i,j) tuple exists if and only if for a certain i, there exists a certain j such that i != j.
4. If we get that certain j, we can return true.