// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
using namespace std;

class Matrix
{
private:
	int** _matrix;
	int rows, cols;

public:
	Matrix(int** matr = {}, int rowCount = 0, int colCount = 0) : //конструктр с параметрами
		_matrix(matr), rows(rowCount), cols(colCount)
	{

	}
	Matrix(const Matrix& obj) : _matrix(obj._matrix), rows(obj.rows), cols(obj.cols) // конструктр копирование
	{

	}
	~Matrix() // деструктр
	{
		delete[] _matrix;
	}

	Matrix* Ymnog(Matrix m) //функция умножнения матриц
	{
		int** result = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			result[i] = new int[rows];
		}
		for (int i = 0; i < rows; i++)
		{
			for (int j = 0;  j < rows; j++)
			{
				result[i][j] = 0;
				for (int k = 0; k < rows; k++)
				{
					result[i][j] += _matrix[i][k] * m._matrix[k][j];
			     }
		    }

	    }
	return new Matrix(result, rows, rows);
    }

	Matrix* Symma (Matrix* m) // функция сложения матриц
	{
		int** result = new int* [rows];
		for (int i = 0; i < rows; i++)
		{
			result[i] = new int[cols];
		}

		for (int i = 0; i < rows; i++)
		{
			for (int j = 0; j < cols; j++)
			{
				result[i][j] = _matrix[i][j] + m->_matrix[i][j];
			}
		}

		return new Matrix(result, rows, cols);
	}
	void Print()
	{
		cout << endl << "Матрица" << endl;
		for (int r = 0; r < rows; r++)
		{
			for (int c = 0; c < cols; c++)
			{
				auto temp = _matrix[r][c];
				cout << temp << " ";
			}
			cout << endl;
		}
	}
};

// функция вывода мартрицы на экран
void PrintMatr(int** matr, int* rowCount, int* colCount)
{
	cout << endl << "Матрица" << endl;
	for (int r = 0; r < *rowCount; r++)
	{
		for (int c = 0; c < *colCount; c++)
		{
			auto temp = matr[r][c];
			cout << temp << " ";
		}
		cout << endl;
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");

	//выделение памяти под указатели
	int* colCount = new int(0);
	int* rowCount = new int(0);
	//ввод размера матрицы
	cout << "Введите количество строк матрицы:" << endl;
	cin >> *rowCount;
	cout << "Введите количество столбцов матрицы:" << endl;
	cin >> *colCount;
	//выделение памяти под массив
	int** arr = new int* [*rowCount];

	for (int i = 0; i < *rowCount; i++)
	{
		arr[i] = new int[*colCount];
	}
	// ввод массива
	for (int r = 0; r < *rowCount; r++)
	{
		cout << "Строка " << r + 1 << ":" << endl;
		for (int c = 0; c < *colCount; c++)
		{
			cin >> arr[r][c];
		}
	}
	// исходный массив
	PrintMatr(arr, rowCount, colCount);

	//выделение памяти под указатели
	int* col2Count = new int(0);
	int* row2Count = new int(0);
	//ввод размера матрицы
	cout << "Введите количество строк матрицы:" << endl;
	cin >> *row2Count;
	cout << "Введите количество столбцов матрицы:" << endl;
	cin >> *col2Count;
	//выделение памяти под массив
	int** arr2 = new int* [*row2Count];
	for (int i = 0; i < *row2Count; i++)
	{
		arr2[i] = new int[*col2Count];
	}
	// ввод массива
	for (int r = 0; r < *row2Count; r++)
	{
		cout << "Строка " << r + 1 << ":" << endl;
		for (int c = 0; c < *col2Count; c++)
		{
			cin >> arr2[r][c];
		}
	}
	PrintMatr(arr2, row2Count, col2Count);

	Matrix* m1 = new Matrix(arr, *rowCount, *colCount);
	Matrix* m2 = new Matrix(arr2, *row2Count, *col2Count);
	Matrix* res = new Matrix();

	if (*rowCount == *row2Count && *colCount == *col2Count) //проверка на одинаковое количество строк и столбцов в матрицах
	{
		cout << "Сложение:" << endl;
			res = m1->Symma(m2);
			res->Print();
			delete res;
	}
	else
	{
		cout << "Матрицы не подходят для сложениея" << endl;
	}
	if (*rowCount == *col2Count && *colCount == *colCount)
	{
	cout << "Умножение:" << endl;
	res = m1->Ymnog(*m2);
	res->Print();
	delete res;
    }
	else 
    { 
	cout << "Матрицы не подходят для сложениея" << endl;
    }
}
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
