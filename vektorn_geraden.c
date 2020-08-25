// Programm zum Prüfen, ob ein Punkt auf einer Gerade liegt
// Autor: Fabian Prestros
// Datum: 25.08.2020
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

double pruefen(double a[2], double b[2], double c[2], double t[2])
// Prüfen, ob der Punkt c auf der durch a und b bestimmten Gerade liegt
{
	t[0] = (c[0] - a[0]) / b[0];
	t[1] = (c[1] - a[1]) / b[1];
}

int main()
{
	double P[2], g[2], X[2], t[2];

	// Vektoren einlesen
	P[0] = einlesen("P_1");
	P[1] = einlesen("P_2");
	g[0] = einlesen("g_1");
	g[1] = einlesen("g_2");
	X[0] = einlesen("X_1");
	X[1] = einlesen("X_2");

	pruefen(P, g, X, t);

	if (t[0] == t[1])
		printf("Der Punkt liegt auf der Gerade.");
	else
		printf("Der Punkt liegt nicht auf der Gerade.");
}