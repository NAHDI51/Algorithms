The brute force version of the divide and conquer algorithm "max_sub_subarray.py".

#iteration = stuffs to be done in the inner loop.
#total = stuffs to be done in the outer loop.

#start_index ~ end_index = one sub array. The iteration sub array is to be compared with the total sub array after each
#iteration of the inner loop.

MAX_SUB_BRUTE_FORCE(N) {
    iteration_sum = -infinity
    total_sum = -infinity

    iter_start_index = iter_end_index = 0
    total_start_index = total_end_index = 0

    RENAMES()       #For readability convenience only. Otherwise, it's completely redundant.

    sum = 0

    for i = 1 to N.length 
        i_st = i
        sum = 0
        i_sum = -infinity

        for j = i to N.length
            sum += N[j]
            if sum > i_sum 
                i_sum = sum
                i_ed = j
        
        if i_sum > t_sum        #if the itertaion sum breaks the record, set it as the new record.
            t_sum = i_sum
            t_st = i_st
            t_ed = i_ed

}

RENAMES() {  
    i_sum = RENAME(iteration_sum)
    t_sum = RENAME(total_sum)
    i_st = RENAME(total_start_index)
    i_ed = RENAME(total_end_index)
    t_st = RENAME(total_start_index)
    t_ed = RENAME(total_end_index)
}

SYNOPSIS:
This is the brute force version of the algorithm "max_sub_subarray.py".
Idea: go through and enumerate the sum from every position of the given array.
Cost: O(n^2)

1. We will divide the 