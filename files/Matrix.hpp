#pragma once

#include <iostream>
template<typename TYPE>
class Matrix
{
private:
	int m_n;
	int m_m;
	TYPE** m_matrix = nullptr;
public:
	Matrix(int n = 1, int m = 1) : m_n(n), m_m(m)
	{
		if ((m_n < 0) || (m_m < 0) || (m_n > 3) || (m_m > 3))
		{
			abort();
		}
		m_matrix = new TYPE*[m_n];
		for (int i = 0; i < m_n; i++)
		{
			m_matrix[i] = new TYPE[m_m];
		}
		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
			{
				m_matrix[i][j] = TYPE();
			}
	}
	Matrix(const Matrix& M) : m_n(M.m_n), m_m(M.m_m)
	{
		m_matrix = new TYPE*[M.m_n];
		for (int i = 0; i < M.m_n; i++)
		{
			m_matrix[i] = new TYPE[M.m_m];
		}
		for (int i = 0; i < M.m_n; i++)
			for (int j = 0; j < M.m_m; j++)
			{
				m_matrix[i][j] = M.m_matrix[i][j];
			}
	}


	void set(TYPE c, int n, int m)
	{
		m_matrix[n - 1][m - 1] = c;
	}

	TYPE get(int n, int m)
	{
		return m_matrix[n - 1][m - 1];
	}

	TYPE det()
	{
		if ((m_n == 1) && (m_m == 1))
		{
			return m_matrix[0][0];
		}
		else if ((m_n == 2) && (m_m == 2))
		{
			return (m_matrix[0][0] * m_matrix[1][1]) + (m_matrix[1][0] * m_matrix[0][1]);
		}
		else if ((m_n == 3) && (m_m == 3))
		{
			return (m_matrix[0][0] * m_matrix[1][1] * m_matrix[2][2]) + (m_matrix[0][2] * m_matrix[1][0] * m_matrix[2][1]) + (m_matrix[0][2] * m_matrix[1][0] * m_matrix[1][2]);
		}
	}
	bool invDetCheck(TYPE z)
	{
		if ((m_n == 1) && (m_m == 1))
		{
			return m_matrix[0][0] >= z;
		}
		else if ((m_n == 2) && (m_m == 2))
		{
			return ((m_matrix[0][0] * m_matrix[1][1]) + (m_matrix[1][0] * m_matrix[0][1])) >= z;
		}
		else if ((m_n == 3) && (m_m == 3))
		{
			return ((m_matrix[0][2] * m_matrix[1][1] * m_matrix[2][0]) + (m_matrix[0][1] * m_matrix[1][0] * m_matrix[2][2]) + (m_matrix[0][0] * m_matrix[1][2] * m_matrix[2][1])) >= z;
		}
	}

	Matrix& operator=(Matrix &M)
	{
		std::swap(this->m_n, M.m_n);
		std::swap(this->m_m, M.m_m);
		m_matrix = static_cast<TYPE**>(realloc(m_matrix, sizeof(TYPE*) * m_n));
		for (int i = 0; i < m_n; i++)
		{
			this->m_matrix[i] = new TYPE[m_m];
		}
		for (int i = 0; i < m_n; i++)
			for (int j = 0; j < m_m; j++)
			{
				this->m_matrix[i][j] = M.m_matrix[i][j];
			}
		return *this;
	}
	Matrix& operator+=(const Matrix& M)
	{
		if (this->m_n != M.m_n && this->m_m != M.m_m)
		{
			abort();
		}
		for (int i = 0; i < this->m_n; i++)
			for (int j = 0; j < this->m_m; j++)
			{
				this->m_matrix[i][j] += M.m_matrix[i][j];
			}
		return *this;
	}

	Matrix operator+(const Matrix& M)
	{
		if (this->m_n != M.m_n && this->m_m != M.m_m)
		{
			abort();
		}
		Matrix temp = *this;
		for (int i = 0; i < this->m_n; i++)
			for (int j = 0; j < this->m_m; j++)
			{
				temp.m_matrix[i][j] += M.m_matrix[i][j];
			}
		return temp;
	}

	Matrix operator-(const Matrix& M)
	{
		if (this->m_n != M.m_n && this->m_m != M.m_m)
		{
			abort();
		}
		Matrix temp = *this;
		for (int i = 0; i < this->m_n; i++)
			for (int j = 0; j < this->m_m; j++)
			{
				temp.m_matrix[i][j] -= M.m_matrix[i][j];
			}
		return temp;
	}
	Matrix operator*(const Matrix& M)
	{
		if (this->m_m != M.m_n)
		{
			Matrix E(1, 1);
			E.set(false, 1, 1);
			return E;
			std::cout << "Невозможно умножить /n";
		}
		Matrix temp(this->m_n, M.m_m);
		for (int i = 0; i < this->m_n; i++)
			for (int j = 0; j < this->m_m; j++)
				for (int f = 0; f < M.m_m; f++)
				{
					temp.m_matrix[i][f] += this->m_matrix[i][j] * M.m_matrix[j][f];
				}
		return temp;
	}
	Matrix& operator*=(const Matrix& M)
	{
		if (this->m_m != M.m_n)
		{

			abort();

		}
		Matrix temp = *this;
		this->m_m = M.m_m;
		for (int i = 0; i < this->m_n; i++)
		{
			this->m_matrix[i] = static_cast<TYPE*>(realloc(this->m_matrix[i], sizeof(TYPE) * M.m_m));
			for (int j = 0; j < this->m_m; j++)
			{
				m_matrix[i][j] = TYPE();
				for (int f = 0; f < M.m_m; f++)
				{
					this->m_matrix[i][j] += temp.m_matrix[i][f] * M.m_matrix[f][j];
				}
			}
		}
		return *this;
	}

	Matrix& operator++()
	{
		for (int i = 0; i < this->m_n; i++)
		{
			this->m_matrix[i][this->m_m - 1]++;
		}
		return *this;
	}

	Matrix operator++(int)
	{
		Matrix old = *this;
		for (int i = 0; i < this->m_n; i++)
		{
			this->m_matrix[i][this->m_m - 1]++;
		}
		return old;
	}

	friend std::ostream& operator<<(std::ostream& out, Matrix& M)
	{
		for (int i = 0; i < M.m_n; i++)
		{
			for (int j = 0; j < M.m_m; j++)
			{
				out << M.m_matrix[i][j] << ' ';
			}
			out << std::endl;

		}
		out << "Тип матрицы: " << M.m_n << " x " << M.m_m << std::endl;
		if (M.m_n == M.m_m)
		{
			out << "Определитель: " << M.det() << std::endl;
		}
		return out;
	}

	~Matrix()
	{
		if (m_matrix != nullptr)
		{
			for (int i = 0; i < m_n; i++)
			{
				if (m_matrix[i] != nullptr)
				{
					delete[] m_matrix[i];
				}
			}
			delete[] m_matrix;
		}
	}
};

