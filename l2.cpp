#include <iostream>

using namespace std;

int max(int a, int b, int c)
{
	if (a > b && a > c) return a;
	if (b > a && b > c) return b;
	if (c > a && c > b) return c;
}

int min(int a, int b, int c)
{
	if (a < b && a < c) return a;
	if (b < a && b < c) return b;
	if (c < a && c < b) return c;
}

int main()
{
	int(*func)(int, int, int);
	int a, b, c, operation;
	cout << "Enter three numbers: ";
	cin >> a >> b >> c;
	if ((a + b + c) % 2 == 0)
		func = max;
	else
		func = min;
	operation = func(a, b, c);
	cout << "Result: " << operation << endl;
	system("pause");
	return 0;
}