
#calculates the total number of A[i], A[j] exists which is equal to target.
K-ELEMENTS(A, target) {
    Let i = 1, j = target.
    count = 0
    while i < j
        sum = i + j
        if sum == target
            count++
            i++ or j--  #Note that either of them, not both of them. Doing either way is fine.
        else if sum > target  #Too big. Make the tuple bigger by incrementing i.
            i++
        else 
            j--
    
    return count
}

SPACE COMPELXITY: O(n)

SYNOPSIS OF TWO POINTERS APPROACH:
We have a sorted array |a1, a2 ... , aN|
We start with two polar indexs, typically the first and the last one. The idea is to:
1. Compare the value with the targetted one. 
2. If the value is equal, return positive (Not necessarily true).
3. If the value is smaller, decrement j, because that will decrease the total value.
4. Otherwise, increment i, that will increase the total value.
5. Do this as long as i < j. Because, otherwise we will get duplicated result. For instance, 
   consider when i = u, j = v. AFter incrementation and decrementation, j = u and i = v. They will necessarily give
   the same result. But it works the other way around in some particular instances, for example, finding the total pair OF
   a[i], a[j] such that a[i]-a[j] = target.
