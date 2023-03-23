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
		m_matrix = new TYPE*[m_n];
		for(int i = 0; i < m_n; i++)
		{
			m_matrix[i] = new TYPE[m_m];
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

	void fill(int n, int m, TYPE c)
	{
		m_matrix[n - 1][m - 1] = c;
	}

	TYPE get(int n, int m)
	{
		return m_matrix[n - 1][m - 1];
	}
	Matrix& operator=(Matrix M)
	{
		std::swap(m_n, M.m_n);
		std::swap(m_m, M.m_m);
		m_matrix = static_cast<TYPE**>(realloc(m_matrix, sizeof(TYPE**) * m_n));
		for (int i = 0; i < m_n; i++)
		{
			m_matrix[i] = new TYPE[m_m];
		}
		return *this;
	}
	Matrix& operator+=(const Matrix& M)
	{
		Matrix temp = *this;
		for (int i = 0; i < M.m_n; i++)
			for (int j = 0; j < M.m_m; j++)
			{
				temp.m_matrix[i][j] += M.m_matrix[i][j];
			}
		return temp;
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