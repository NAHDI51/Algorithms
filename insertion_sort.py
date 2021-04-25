INSERTION_SORT(N) {
    for j = 2 to N.length                   
        key = N[j]
        i = j-1
        while i > 0 and key > N[i] 
            A[i+1] = A[i]
            i = i-1
        A[i] = key
}

Synopsis:
1. Take an index j. The ultimate goal after each iteration is:
    Arr |1, 2, ... j-1| will always be sorted.
    Arr |j... N.length| are to be sorted.

2. With each iteration, we will take a new key. Key = N[j]. Since Arr |1, ... , j-1| is sorted, we'll only need
   to find it's position, where it belongs.
   The position will be index i such that A[i+1] > key > A[i-1].

3. We will assign the value of key to the given position. Thus, making our |1, ... , j-1| sorted.
4. Continue 1 ~ N.length.