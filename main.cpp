#include <Matrix.hpp>


int main()
{
	Matrix<int> A(2, 2);
	Matrix<int> B(3, 2);
	B.fill(1, 1, 3);
	B.fill(1, 2, 6);
	A = B;
	std::cout << A.get(1, 1);
	return 0;
}