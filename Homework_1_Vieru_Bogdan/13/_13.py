import numpy as np 

def crMatrix(matrixsize):
    matrix=np.zeros((matrixsize,matrixsize,matrixsize))
    for i in range(matrixsize):
        for j in range(matrixsize):
            for k in range(matrixsize):
            
                matrix[i][j][k]=int(input("coeficientul lui x^{} = ".format(matrixsize-k-1)))
    return matrix   


def sumMatrix(matrix1,matrix2,matrixsize):
    for i in range(matrixsize):
        for j in range(matrixsize):
            for k in range(matrixsize):
                matrix1[i][j][k]=matrix1[i][j][k]+matrix2[i][j][k]
    return matrix1;

def printPolyMatrix(matrix,matrixsize):
    for i in range(matrixsize):
        for j in range(matrixsize):
            for k in range(matrixsize):
                if k==matrixsize-1:
                    print("{}x^{} ".format(matrix[i][j][k],matrixsize-k-1),end=" ")
                else:
                    print("{}x^{} +".format(matrix[i][j][k],matrixsize-k-1),end=" ")
            print("  ; ",end=" ")
        print("\n")
        
def evaluateMatrix(point,matrix,matrixsize):
    resmatrix=np.zeros((matrixsize,matrixsize))
    x=0
    for i in range(matrixsize):
        for j in range(matrixsize):
            for k in range(matrixsize):
                x=x+matrix[i][j][k]*point**(matrixsize-k-1)
            resmatrix[i][j]=x
            x=0
    return resmatrix

# def prodMatrix(matrix1,matrix2,matrixsize):


matrixSize=int(input("Size of matrix = "))
point=int(input("Point at which the product will be evaluated = "))
matrix=crMatrix(matrixSize)
printPolyMatrix(matrix,matrixSize)
matrix2=crMatrix(matrixSize)
printPolyMatrix(matrix2,matrixSize)
print("===Sum of the two matrices===")
c=sumMatrix(matrix,matrix2,matrixSize)
printPolyMatrix(c,matrixSize)
print("===Sum of the two matrices evaluated at {}===".format(point))
d=evaluateMatrix(point,c,matrixSize)
print(d)
 