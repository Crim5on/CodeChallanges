// kata source: https://www.codewars.com/kata/5263a84ffcadb968b6000513/train/cpp
/*
    Write a function that accepts two square (NxN) matrices (two dimensional arrays), and returns the product of the two. 
    Only square matrices will be given.

    How to multiply two square matrices:
    We are given two matrices, A and B, of size 2x2 (note: tests are not limited to 2x2). 
    Matrix C, the solution, will be equal to the product of A and B. 
    To fill in cell [0][0] of matrix C, you need to compute: A[0][0] * B[0][0] + A[0][1] * B[1][0].

    More general: 
    To fill in cell [n][m] of matrix C, you need to first multiply the elements in the nth row of matrix A 
    by the elements in the mth column of matrix B, then take the sum of all those products. 
    This will give you the value for cell [m][n] in matrix C.
    Example:

    A         B          C
    |1 2|  x  |3 2|  =  | 5 4|
    |3 2|     |1 1|     |11 8|

    Detailed calculation:

    C[0][0] = A[0][0] * B[0][0] + A[0][1] * B[1][0] = 1*3 + 2*1 =  5
    C[0][1] = A[0][0] * B[0][1] + A[0][1] * B[1][1] = 1*2 + 2*1 =  4
    C[1][0] = A[1][0] * B[0][0] + A[1][1] * B[1][0] = 3*3 + 2*1 = 11
    C[1][1] = A[1][0] * B[0][1] + A[1][1] * B[1][1] = 3*2 + 2*1 =  8

    A more visual explanation of matrix multiplication: http://matrixmultiplication.xyz
*/

#include <iostream>
#include <vector>

/*
    1 2 3       1 2 3       30 36 42
    4 5 6   x   4 5 6   =   66 81 96
    7 8 9       7 8 9       102 126 150
*/


static int multiplyVectors(std::vector<int> &a, std::vector<int> &b, size_t n)
{
	int result = 0;
	for(size_t i=0; i<n; i++){
		result = result + (a[i] * b[i]);
	}
	return result;
}


static std::vector<int> getColumnVectorFrom2DMatrix(std::vector<std::vector<int>> &matrix, int columnNr)
{
	std::vector<int> column;
	for(size_t lineNr=0; lineNr<matrix.size(); lineNr++){
		column.push_back(matrix[lineNr][columnNr]);
	}
	return column;
}


std::vector<std::vector<int>> matrix_multiplication(std::vector<std::vector<int>> &a, std::vector<std::vector<int>> &b, size_t n)
{
    std::vector<std::vector<int>> cMatrix(n, std::vector<int>(n, 0));

	for(size_t l=0; l<n; l++){
		for(size_t c=0; c<n; c++){
			std::vector<int> lineVec = a[l];
			std::vector<int> columnVec = getColumnVectorFrom2DMatrix(b, c);
			cMatrix[l][c] = multiplyVectors(lineVec, columnVec, n);
		}
	}

	return cMatrix;
}



int main(void)
{
	// test multiplyVectors: (passed)
	std::vector<int> a = {1, 2, 3};
	int vecResult = multiplyVectors(a, a, a.size());
	std::cout << "multiplyVectors (14): " << vecResult << std::endl;


	// test getColumnVectorFrom2DMatrix: (passed)
	std::vector<std::vector<int>> testMatrix = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	std::vector<int> testColumnVec = getColumnVectorFrom2DMatrix(testMatrix, 2);
	std::cout << "Vector Column (3, 6, 9): " << std::endl;
	for(auto i : testColumnVec){
		std::cout << i << ", " << std::endl;
	}
	std::cout << std::endl;


	// test matrix_multiplication (passed)
	std::vector<std::vector<int>> testResultMatrix = matrix_multiplication(testMatrix, testMatrix, testMatrix.size());
	for(size_t i=0; i<testMatrix.size(); i++){
		for(size_t j=0; j<testMatrix.size(); j++){
			std::cout << testResultMatrix[i][j] << ", ";
		}
		std::cout << std::endl;
	}

    std::cout << std::endl;
    return EXIT_SUCCESS;
}
