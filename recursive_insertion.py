INSERT(N, len, element) {
    i = len
    while(i >= 0 && N[i] > element) {
        N[i+1] = N[i]
        i--
    }
}

INSERTION_SORT(N, len) {
    N.length != 0 {
        INSERTION_SORT(N N.length-1)
        INSERT(N, N.length-1, N[N.length])
    }
}