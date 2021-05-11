#ALWAYS NOTE THAT the first subscript represents row and 2nd matrix represents col.

MATRIX_MULTIPLICATION(A, B) {    
    if A.col != B.row 
        return error("Matrix sizes don't match.")
    
    if A[i].length != A[j].length for 0 <= rand(i, j) 
        return error("Matrix is not rectangle.")
    else 
        let M[A.col][B.row] be the multiplication matrix

        for i = 1 to A.row {
            for j = 1 to B.col 
                sum = 0
                for k = 1 to B.row  
                    mult = A[i][k] * B[k][j]
                    sum += mult

                M[i][j] = sum

        return M
}