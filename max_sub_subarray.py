#l_sum = left_sum, r_sum = right_sum, cr_sum = cross_sum
#Array[3] returns the corresponding three elements: start of the subset, end of the subset, total sum of the subset.

Array[3] MAXIMUM_SUM_SUBARRAY(A, low, high) {
    if low == high      #Means the array A has only one element
        return (low, high, A[low])
    else                #otherwise, divide into two and conquer.
        mid = (low+high) / 2
        (l_low, l_high, l_sum) = MAXIMUM_SUB_SUBARRAY(A, low, mid)
        (r_low, r_high, r_sum) = MAXIMUM_SUB_SUBARRAY(A, mid+1, high)
        (cr_low, cr_high, cr_sum) = MAXIMUM_CROSS_ARRAY(A, low, mid, high)

        if l_sum >= r_sum and l_sum >= cr_sum
            return (l_low, l_high, l_sum)

        else if r_sum >= l_sum and r_sum >= cr_sum
            return (r_low, r_high, r_sum)
        else 
            return (cr_low, cr_high, cr_sum)
}

Array[3] MAXIMUM_CROSS_ARRAY(A, low, mid, high) {
    l_sum = -infinity
    l_indx = mid
    sum = 0
    for i = mid and i >= low 
        sum += A[i]
        if sum > l_sum
            l_sum = sum
            l_indx = i
    
    r_sum = -infinity
    r_indx = mid+1
    sum = 0
    for i = mid+1 and i <= high 
        sum += A[i]
        if sum > r_sum
            r_sum = sum
            r_indx = i
    
    return (l_indx, r_indx, l_sum + r_sum)
}

SYNOPSIS:
This is an algorithm for finding the sub array whose sum is bigger than any other sum of the elements of the array.
STRATEGY: DIVIDE AND CONQUER
Time: O(nlog(n))

Procedure:
1. if low == high, we have only one element in the array, which is the base recursive case. In this case, 
        return one array, one index and the only one element's sum.
2. Let mid = average(low, high). Let the array be divided into two parts:
    A[1, 2, ... , mid], A[mid+1, ... , high]
3. There are only three possibilities for the sub array to be in.
    I. The left sub-array. 
        (In this case, A[1, ..., mid])
    II. The right sub-array. 
        (In this case, A[mid+1, ..., high])
    III. An array with at least one element from the both side.
        A[i, i+1, ... , mid, mid+1, ... , j-1, j]

4. CALL the functions for these two corresponding arrays. They will calculate the sum of the left and right side 
    of the array.
5. With that, we got our two possiblity. For the cross array, call the CROSS-CALCULATING-ARRAY.

6. return the the one with the highest value of sum.