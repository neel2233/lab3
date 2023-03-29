#include <Matrix.hpp>


int main()
{
	using namespace std;
	setlocale(LC_ALL, "Russian");
	int a;
	Matrix<int> A(3, 3);
	Matrix<int> B(3, 3);
	Matrix<int> C(2, 3);
	for(int i = 1; i <= 3; i++)
		for (int j = 1; j <= 3; j++)
		{
			A.set(i + j, i, j);
			B.set(i + j, i, j);

		}
	for (int i = 1; i <= 2; i++)
		for (int j = 1; j <= 3; j++)
		{
			C.set(i + j, i, j);
		}
	Matrix<int> D;
	Matrix<int> E;
	Matrix<int> F;
	D = A + B;
	D = D - B;
	D += B;
	D *= B;
	E = A * C;
	F = C * B;
	int i, j, z;
	cin >> i >> j;
	cout << A.get(i, j) << std::endl;
	z = B.det();
	A.set(z, i, j);
	A++;
	cout << A;
	return 0;
}