#pragma once

struct EquationRoots
{
	unsigned int numRoots = 0;
	double roots[4];
};

void PrintRoots(EquationRoots equationRoots, ostream &strm);
EquationRoots Solve4(double a, double b, double c, double d, double e);