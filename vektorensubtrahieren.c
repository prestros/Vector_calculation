// Programm zum Addieren von 2-dimensionalen Vektoren
// Autor: Fabian Prestros
// Datum: 21.08.2020
#include <stdio.h>

double einlesen(char koef[3])
{
	int chk;
	double zahl;

	do													// In einer Schleife einlesen, bis eine korrekte Zahl eingelesen wurde
	{
		printf("%s = ", koef);
		chk = scanf_s("%lf", &zahl);
		while (getchar() != '\n');						// Tastaturpuffer leeren.
		if (chk == 0)									// Fehlermeldung, wenn scanf_s meldet, dass keine Ganze Zahl eingegeben wurde
			printf("Bite geben Sie eine Zahl ein!\n");
	} while (chk == 0);									// Schleifendurchlauf, bis kein Fehler mehr vorliegt.

	return zahl;
}

int vsub(double a[2], double b[2], double c[2])
// Subtraktion von 2-dimensionalen Vektoren
{
	c[0] = a[0] - b[0];
	c[1] = a[1] - b[1];
}

int main()
{
	double a[2], b[2], c[2];

	// Vektoren einlesen
	a[0] = einlesen("a_1");
	a[1] = einlesen("a_2");
	b[0] = einlesen("b_1");
	b[1] = einlesen("b_2");

	vsub(a, b, c);

	// Ergebnis ausgeben
	printf("c_0 = %lf, c_1 = %lf\n", c[0],c[1]);
}