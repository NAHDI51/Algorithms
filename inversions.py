INVERSION: given an array|N|,
if the sort has to be done in the order of ascendence, then, if i < j, then A[i] > A[j].
else, if i < j, then A[i] < A[j].

for example, given an array A = |2,3,8,6,1|, and the array has to be sorted in the order of ascendence,
inversions : [(2,1), (3,1), (8,1), (6,1), (8,6)], total: 5.

The number of swaps an insertion sort has to do is equal to the number of inversions an arary has.