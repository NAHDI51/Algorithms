SELECTION_SORT(N) {
    n = N.length
                                            cost    times
    for i = 1 to N.length - 1               c1      n
        min = N[i]                          c2      n-1
        indx = i                            c3      n-1

        for j = i+1 to N.length             c4      (n-1) summation(N.length - i + 1)
            if min > N[j]                   c5      (n-1) summation(N.length - i)
                min = N[j]                  c6      (n-1) summation(N.length - i)
                indx = j                    c7      (n-1) summation(N.length - i)

        swap(N[i], N[indx])                 c8      n-1
}

Synopsis:
1. The core value of this algorithm is to divide the array into two sub array.
    |1, 2, ... , i-1| = sorted
    |i, i+1, ... , N.length| = to be sorted

2. Now pick an index i, and find the minimum element from the unsorted array. 

3. Swap N[min_index] and N[i]. 
    With doing this way, we can be sure that,
    N[1] < N[2] ... < N[n-1] < N[n] where n = N.length.

4. increment i.