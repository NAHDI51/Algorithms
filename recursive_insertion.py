INSERTION_SORT(N, len) {
    N.length != 1 {
        INSERTION_SORT(N N.length-1)
        INSERT(N, N.length-1, N[N.length])
    }
}