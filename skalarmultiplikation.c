// Programm zur Multiplikation eines 2-dimensionalen Vektors mit einem Skalar
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

void vmult(double a, double b[2], double c[2])
// Multiplikation eines 2-dimensionalen Vektors mit einem Skalar
{
	c[0] = a * b[0];
	c[1] = a * b[1];
}

int main()
{
	double a, b[2], c[2];

	a = einlesen("a");									// Skalar einlesen

	// Vektor einlesen
	b[0] = einlesen("b_1");
	b[1] = einlesen("b_2");

	vmult(a, b, c);

	// Ergebnis ausgeben
	printf("c_1 = %lf\n", c[0]);
	printf("c_2 = %lf\n", c[1]);
}