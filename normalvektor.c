// Programm zur Berechnung des Normalenvektors eines 2-dimensionalen Vektors
// Autor: Fabian Prestros
// Datum: 24.08.2020
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

double normalenvektor_erzeugen(double a[2], double b[2])
// Berechnung des Normalenvektors eines 2-dimensionalen Vektors
{
	b[0] = -a[1];
	b[1] = a[0];
}

double skalarprodukt(double a[2], double b[2])
// Berechnung des Skalarproduktes 2er 2-dimensionaler Vektoren
{
	double c;

	c = a[0] * b[0] + a[1] * b[1];
	return c;
}

int main()
{
	double sp;
	double a[2], b[2];

	// Vektoren einlesen
	a[0] = einlesen("a_1");
	a[1] = einlesen("a_2");

	normalenvektor_erzeugen(a, b);
	printf("b_1 = %lf, b_2 = %lf\n", b[0], b[1]);		// Ergebnis ausgeben

	// Ergebnis prüfen
	sp = skalarprodukt(a, b);
	if (sp == 0)
		printf("Vektoren sind orthogonal.\n");
	else
		printf("Vektoren sind nicht orthogonal.\n");
	printf("Skalarprodukt = %lf\n", sp);
}