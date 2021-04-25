MERGE_1(A, p, q, r) {
    n1 = p-q + 1
    n2 = r-q

    L[n1+1], R[n2+1]

    for i = 1 to n1
        L[i] = A[p+i-1]
    for i = 1 to n2
        R[i] = A[q+i]
    
    L[n1+1] = 0
    R[n2+1] = 0

    l_indx = r_indx = 0
    for k = p to r 
        if L[l_indx] < R[r_indx] 
            A[k] = L[l_indx]
            l_indx++
        else if R[r_indx] < L[l_indx] 
            A[k] = R[r_indx]
            r_indx++
}

MERGE_2(A, p, q, r) {
    n1 = p-q+1
    n2 = r-q
    Let L[n1] and R[n2] be new arrays

    for i = 1 to n1
        L[i] = A[p+i-1]
    for i = 1 to n2
        R[i] = A[q+i]
    
    l_index = r_index = 1
    for k = p to r 
        if l_index = n1
            A[k] = R[r_index]
            r_index++
        else if r_index = n2
            A[k] = L[l_index]
            l_index++
        else if L[l_index] <= R[r_index] 
            A[k] = L[l_index]
            l_index++
        else if R[r_index] <= L[l_index]    #redundant condition. But used to make this algorithm easier to look at.
            A[k] = R[r_index]
            r_index++
}

MERGE_SORT(A, p, r) {
    if p < r
        q = avg(p, r)
        MERGE_SORT(A, p, q)
        MERGE_SORT(A, q+1, r)
        MERGE(A, p, q, r)
}

Synopsis:
1. Every sub-array has a starting point and a ceiling. Since we are dividing into arrays of two, they are
    p to q
    q+1 to r
    respectively.

2. q = middle point of each array. Upon that point, we divide. For example, 
    if p = 1, r = 16, q = (p+r) / 2 = 17/2 = 8 (rounded)

3. MERGE assumes that the two subarrays are in sorted order, thus, merges them.

4. if p <= r or p < r, then the array has 1 or 0 elements respectively.

5. int MERGE(A, p, q, r), q = p's ceiling, thus needs to be considered with extra

