#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <math.h>

using namespace std;

class LagrangeInterpolation {
private:
	int pointsCount;
	double *pointsValue;
	double *pointsNumber;
public:
	LagrangeInterpolation();
	LagrangeInterpolation(int, double*, double*);
	double returnValue(double);
};

class NewtonInterpolation {
private:
	int pointsCount;
	double *pointsValue;
	double *pointsNumber;
public:
	NewtonInterpolation();
	NewtonInterpolation(int, double*, double*);
	double returnValue(double);

};

class Cramer {
private:
	double **pointsX;
	double W1, W2, W3, W;
	bool solved = false;
public:
	Cramer();
	Cramer(double**);
	void solve();
	double getX();
	double getY();
	double getZ();
};

class polynomialInterpolation {
	double *pointsX;
	double *values;
public:
	polynomialInterpolation();
	polynomialInterpolation(double*, double*);
	void solve();
};

class IntegrationRectangleMethod {
	double *formula;
	int startPoint;
	int endPoint;
	int n;
	int formulaCount;
public:
	IntegrationRectangleMethod();
	IntegrationRectangleMethod(double*, int, int, int, int);
	void solve();
	double formulaResult(int point);
};

class IntegrationTrapezoidalMethod {
	double *formula;
	int startPoint;
	int endPoint;
	int n;
	int formulaCount;
public:
	IntegrationTrapezoidalMethod();
	IntegrationTrapezoidalMethod(double*, int, int, int, int);
	void solve();
	double formulaResult(int point);
};

class IntegrationSimpsonMethod {
	double *formula;
	int startPoint;
	int endPoint;
	int n;
	int formulaCount;
	double h;
public:
	IntegrationSimpsonMethod();
	IntegrationSimpsonMethod(double*, int, int, int, int, double);
	void solve();
	double formulaResult(int point);
};

class IntegrationMonteCarloMethod {
	double *formula;
	int startPoint;
	int endPoint;
	int n;
	int formulaCount;
public:
	IntegrationMonteCarloMethod();
	IntegrationMonteCarloMethod(double*, int, int, int, int);
	void solve();
	double randomBetween(double min, double max);
	double formulaResult(int point);
};

class GaussianQuadrature {
	double *wsp_x, *wsp_y;
public:
	GaussianQuadrature();
	double result();
};

class BisectionMethod {
	double *formula;
	int n;
	double a, b;
public:
	BisectionMethod();
	BisectionMethod(double*, int, double, double);
	double solve();
	double formulaResult(double);
};

class NewtonRaphsonMethod {
	double *formula;
	int n;
	double a, b;
public:
	NewtonRaphsonMethod();
	NewtonRaphsonMethod(double*, int, double, double);
	double solve();
	double formulaResult(double);
	double formulaDerivativeResult(double);
};

class Differentials
{
	double *formula;
	double n;
public:
	Differentials();
	Differentials(double*, double);
	double formulaResult(double*, double, double);
	double **eulerMethod(double, double, double);
	double **heunMethod(double, double, double);
	double **RK4Method(double, double, double);
};