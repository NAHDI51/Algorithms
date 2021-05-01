BINARY_SEARCH(N, p, q, key) {
    if p <= q
        m = (p+q) / 2
        if N[m] == key 
            return m
        if N[m] > key 
            return BINARY_SEARCH(N, p, m-1, key)
        if N[m] < key
            return BINARY_SEARCH(N, m+1, q, key)
    else
        return -1
}