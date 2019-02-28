#include "CComplex.h"

int main()
{
	int n, i;
	CComplex z[30];
	cout << "Introduceti numarul de numere complexe: ";
	cin >> n;
	
	for (i = 1; i <= 2*n; i++)
	{
		cout << "Introduceti numarul complex z"<<i<<": ";
		cin >> z[i];
	}
	cout << endl;
	for (i = 1; i <= 2*n; i++)
	{
		cout << "z" << i << " = ";
		cout << z[i];
	}

	CComplex vNumarator, vNumitor, vTotal;
	for (i = 1; i <= 2*n - 1; i += 2)
	{
		vNumarator = vNumarator + (z[i] ^ 3);
	}

	for (i = 2; i <= 2 * n; i += 2)
	{
		vNumitor = vNumitor + (z[i] ^ 4);
	}
	
	vTotal = vNumarator / vNumitor;
	cout << "v = " << vTotal;

	return 0;
}