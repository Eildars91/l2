#include <iostream> 
#include <cstdlib>
#include <ctime>

using namespace std;

typedef void(*func)(int* ar);

void invertir(int* ar)
{
	int temp;
	for (int i = 0, j = 15 - 1; i < j; ++i, --j)
	{
		temp = ar[i];
		ar[i] = ar[j];
		ar[j] = temp;
	}
}

void vozrast(int* ar)
{
	int temp;
	for (int i = 0; i < 15 - 1; i++)
	{
		for (int j = 0; j < 15 - i - 1; j++)
		{
			if (ar[j] > ar[j + 1])
			{
				temp = ar[j];
				ar[j] = ar[j + 1];
				ar[j + 1] = temp;
			}
		}
	}

}

void ybiv(int* ar)
{
	int temp;
	for (int i = 0; i < 15; i++)
	{
		for (int j = 15 - 1; j > i; j--)
		{
			if (ar[j - 1] < ar[j])
			{
				temp = ar[j - 1];
				ar[j - 1] = ar[j];
				ar[j] = temp;
			}
		}
	}
}

func MainFuncti(int* ar)
{
	void(*functi)(int* arr) = 0;
	int sum = 0;
	for (int i = 0; i < 15; i++)
	{
		sum = sum + ar[i];
	}
	if (sum == ar[0])
	{
		cout << "Invert the massiv." << endl;
		functi = invertir;
	}
	if (sum > ar[0])
	{
		cout << "Sort by increase." << endl;
		functi = vozrast;
	}
	if (sum < ar[0])
	{
		cout << "Sort by decrease." << endl;
		functi = ybiv;
	}
	return functi;
}

int main()
{
	srand(time(NULL));
	int a[15];
	for (int i = 0; i < 15; i++)
	{
		a[i] = rand() % 150 - 50;
	}
	cout << "Initial massif: ";
	for (int i = 0; i < 15; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
	void(*function)(int* a);
	function = MainFuncti(a);
	function(a);
	cout << "Recieved massif: ";
	for (int i = 0; i < 15; i++)
	{
		cout << a[i] << " ";
	}
	system("pause");
}