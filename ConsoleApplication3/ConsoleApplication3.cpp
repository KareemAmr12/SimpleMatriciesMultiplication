#include <iostream>
#include <iomanip>
using namespace std;
#include <vector>

typedef  vector <int>  Row;
typedef  vector<Row> Matrix;  // vector <vector <int>> Matrix
typedef  std::vector<int>  Cols;

void display(const Matrix& A)
{
	int N = A.size();
	int L = A[0].size();

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < L; j++)
		{
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

Matrix multiply(const Matrix& A, const Matrix& B) {
	// A is a matrix of size N x L and
	// B is a matrix of size L x M
	// returns C = A*B  of size N x M
	
	int N = A.size();
	int L = A[0].size();
	int M = B[0].size();
	Matrix C(N, Cols(M));

	for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				int sum = 0;
				for (int k = 0; k < L; k++)
				{
					 
						sum = sum + A[i][k] * B[k][j];
						C[i][j] = sum;
				}
					
				
			}
		}
	
	

	return C;
}

int main()
{

	int nrows1, ncols1;
	int nrows2, ncols2;

	cout << "Enter number of rows first matrix: ";
	cin >> nrows1;

	cout << "Enter number of cols first matrix: ";
	cin >> ncols1;

	nrows2 = ncols1;
	cout << "Enter number of cols of second matrix: ";
	cin >> ncols2;

	Matrix a(nrows1, Cols(ncols1));   //N x L
	Matrix b(nrows2, Cols(ncols2));   //L x M
	Matrix c(nrows1, Cols(ncols2));   //N x M

	//Filling first matrix
	for (int i = 1; i <= nrows1; i++)
	{
		for (int j = 1; j <= ncols1; j++)
			a[i - 1][j - 1] = i * j;
	}

	//Filling second matrix
	for (int i = 1; i <= ncols1; i++)
	{
		for (int j = 1; j <= ncols2; j++)
			b[i - 1][j - 1] = i * j;
	}

	c = multiply(a, b);

	cout << endl << "The first matrix:" << endl;
	display(a);

	cout << endl << "The second matrix:" << endl;
	display(b);

	cout << endl << "The result of maliplying first matrix by second matrix:" << endl;
	display(c);

	system("pause");
	return 0;
}