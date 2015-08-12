/**********************************************
 * filename: "matrix.cpp"
 * author: Aliosha Gonzalez
 * synopsis: Multiplies two integer matrices A and B and
 *          puts the result on a matrix C.
*****************************************************/

#include <iostream>
#include <vector>
using std::cout;
using std::vector;
using std::endl;
using std::cin;
using std::cerr;

//print matrices
void printMatrix(vector <vector<int> > Matrix, int r, int c)
{
        for (int i = 0; i < r; i++)
        {
                for (int j = 0; j < c; j++)
                        cout << "," << Matrix[i][j];
                
                cout << endl;
        }
        cout << "\n\n";
}
//fills first matrix with row values
vector< vector<int> > inputMatrixA(vector <vector<int> > Mat, int Ar, int Ac)
{
        for (int r = 0; r < Ar; r++)
        {
                for (int c = 0; c < Ac; c++)
                        Mat[r][c] = r+1;
        }
       return Mat;
}
//fills second matrix with columns values
vector< vector<int> > inputMatrixB(vector <vector<int> > Mat, int Br, int Bc)
{
        for (int r = 0; r < Br; r++)
        {
                for (int c = 0; c < Bc; c++)
                        Mat[r][c] = c+1;
        }
        
       return Mat;
}
//matrix multiplication
vector< vector<int> > multiMat(vector <vector<int> > C, 
                vector <vector<int> > A, int Ar,
                vector <vector<int> > B, int Br, int Bc)
{
        for (int Arx = 0; Arx < Ar; Arx++)
                for (int Bcx = 0; Bcx < Bc; Bcx++)
                        for (int Brx = 0; Brx < Br; Brx++)
                                C[Arx][Bcx] += A[Arx][Brx] * B[Brx][Bcx];
        
        return C;
}

int main()
{

        //declaration and assigment definition of matrix A
        int Ar = 5;
        int Ac = 4;
        vector< vector<int> > A(Ar, vector<int>(Ac,0));
        A = inputMatrixA(A, Ar, Ac);
        //declaration and assigment definition of matrix B
        int Br = 4;
        int Bc = 5;
        vector< vector<int> > B(Br, vector<int>(Bc,0));
        B = inputMatrixB(B, Br, Bc);
        //declaration and assigment definiton of matrix C 
        vector< vector<int> > C(Ar, vector<int>(Bc,0)); //int Cr = Ar; int Cc = Bc;
        C = multiMat(C, A, Ar, B, Br, Bc);
        //print matrices tables
        printMatrix(A, Ar, Ac);
        printMatrix(B, Br, Bc);
        printMatrix(C, Ar, Bc);
        

        //input MatrixA size from standard input
        cout << "Enter matrix A rows: ";
        cin >> Ar;
        cout << "Enter matrix A columns: ";
        cin >> Ac;
        vector< vector<int> > A2(Ar, vector<int>(Ac,0));
        A2 = inputMatrixA(A2, Ar, Ac);
        //input MatrixB size from standard input
        cout << "Enter Matrix B rows: ";
        cin >> Br;
        cout << "Enter matrix B columns: ";
        cin >> Bc;
        //test if Matrices are ok to be multiply
        if (Ar != Bc)
        {
                cerr << "A rows and B columns are not the same. Program abort!.\n";
                exit(1);
        }
        vector< vector<int> > B2(Br, vector<int>(Bc,0));
        B2 = inputMatrixB(B2, Br, Bc);
        //declaration and assigment definiton of matrixC 
        vector< vector<int> > C2(Ar, vector<int>(Bc,0)); //int Cr = Ar; int Cc = Bc;
        C2 = multiMat(C2, A2, Ar, B2, Br, Bc);
        //print matrices tables
        printMatrix(A2, Ar, Ac);
        printMatrix(B2, Br, Bc);
        printMatrix(C2, Ar, Bc);
        
        return 0;
}
