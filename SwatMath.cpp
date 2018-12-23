#include "SwatMath.h"

LagrangeInterpolation::LagrangeInterpolation()
{
}

LagrangeInterpolation::LagrangeInterpolation(int pointsCountNew, double* pointsValueNew, double* pointsNumberNew)
{
	pointsCount = pointsCountNew;
	pointsValue = pointsValueNew;
	pointsNumber = pointsNumberNew;
}

double LagrangeInterpolation::returnValue(double x)
{
	double *l = new double[pointsCount];
	for (int i = 0; i < pointsCount; i++)
	{
		double temp = 1;

		for (int j = 0; j < pointsCount; j++)
		{
			if (i != j)
			{
				temp = temp * ((x - pointsNumber[j]) / (pointsNumber[i] - pointsNumber[j]));
			}
		}

		l[i] = temp;
	}

	double value = 0;
	for (int i = 0; i < pointsCount; i++)
	{
		value = value + (pointsValue[i] * l[i]);
	}

	return value;
}

NewtonInterpolation::NewtonInterpolation()
{
}

NewtonInterpolation::NewtonInterpolation(int pointsCountNew, double* pointsValueNew, double* pointsNumberNew)
{
	pointsCount = pointsCountNew;
	pointsValue = pointsValueNew;
	pointsNumber = pointsNumberNew;
}

double NewtonInterpolation::returnValue(double x)
{
	double** values = new double*[pointsCount+1];

	values[0] = pointsValue;
	values[1] = new double;

	for (int i = 1; i < pointsCount; i++)
	{
		values[i] = new double;
		for (int j = 0; j < pointsCount - i; j++)
		{
			values[i][j] = (values[i - 1][j + 1] - values[i - 1][j]) / (pointsNumber[i + j] - pointsNumber[j]);
		}
	}

	double finalValue = values[0][0];

	double temp = x - pointsNumber[0];

	for (int i = 1; i < pointsCount; i++)
	{
		finalValue = (values[i][0] * temp) + finalValue;
		temp = temp * (x - pointsNumber[i]);
	}

	return finalValue;
}

Cramer::Cramer()
{
}

Cramer::Cramer(double **pointsXNew)
{
	pointsX = pointsXNew;
}

void Cramer::solve()
{
	double W = pointsX[0][0] * pointsX[1][1] * pointsX[2][2] + pointsX[0][1] * pointsX[1][2] * pointsX[2][0] + pointsX[0][2] * pointsX[1][0] * pointsX[2][1] - pointsX[0][2] * pointsX[1][1] * pointsX[2][0] - pointsX[0][0] * pointsX[1][2] * pointsX[2][1] - pointsX[0][1] * pointsX[1][0] * pointsX[2][2];

	double W1 = pointsX[0][3] * pointsX[1][1] * pointsX[2][2] + pointsX[0][1] * pointsX[1][2] * pointsX[2][3] + pointsX[0][2] * pointsX[1][3] * pointsX[2][1] - pointsX[0][2] * pointsX[1][1] * pointsX[2][3] - pointsX[0][3] * pointsX[1][2] * pointsX[2][1] - pointsX[0][1] * pointsX[1][3] * pointsX[2][2];

	double W2 = pointsX[0][0] * pointsX[1][3] * pointsX[2][2] + pointsX[0][3] * pointsX[1][2] * pointsX[2][0] + pointsX[0][2] * pointsX[1][0] * pointsX[2][3] - pointsX[0][2] * pointsX[1][3] * pointsX[2][0] - pointsX[0][0] * pointsX[1][2] * pointsX[2][3] - pointsX[0][3] * pointsX[1][0] * pointsX[2][2];

	double W3 = pointsX[0][0] * pointsX[1][1] * pointsX[2][3] + pointsX[0][1] * pointsX[1][3] * pointsX[2][0] + pointsX[0][3] * pointsX[1][0] * pointsX[2][1] - pointsX[0][3] * pointsX[1][1] * pointsX[2][0] - pointsX[0][0] * pointsX[1][3] * pointsX[2][1] - pointsX[0][1] * pointsX[1][0] * pointsX[2][3];

	if (W != 0)
	{
		cout << "W: " << W << endl;
		cout << "Wx: " << W1 << endl;
		cout << "Wy: " << W2 << endl;
		cout << "Wz: " << W3 << endl;
		cout << "x: " <<  W1 / W << endl;
		cout << "y: " << W2 / W << endl;
		cout << "z: " << W3 / W << endl;
		solved = true;
	}

	else if (W1 == 0 && W2 == 0 && W3 == 0 && W == 0)
	{
		cout << "W: " << W << endl;
		cout << "Wx: " << W1 << endl;
		cout << "Wy: " << W2 << endl;
		cout << "Wz: " << W3 << endl;
		cout << "Uklad jest nieoznaczony" << endl;
		solved = true;
	}

	else
	{
		cout << "W: " << W << endl;
		cout << "Wx: " << W1 << endl;
		cout << "Wy: " << W2 << endl;
		cout << "Wz: " << W3 << endl;
		cout << "Uklad jest sprzeczny" << endl;
		solved = true;
	}
}

double Cramer::getX()
{
	if (solved == false)
	{
		solve();
		return W1 / W;
	}
	return W1 / W;
}

double Cramer::getY()
{
	if (solved == false)
	{
		solve();
		return W2 / W;
	}
	return W2 / W;
}

double Cramer::getZ()
{
	if (solved == false)
	{
		solve();
		return W2 / W;
	}
	return W2 / W;
}

polynomialInterpolation::polynomialInterpolation()
{
}

polynomialInterpolation::polynomialInterpolation(double *pointsXNew, double *valuesNew)
{
	pointsX = pointsXNew;
	values = valuesNew;
}

void polynomialInterpolation::solve()
{
	double** temp = new double*[4];

	double x[4] = { pow(pointsX[0], 2), pointsX[0], 1, values[0] };
	double y[4] = { pow(pointsX[1], 2), pointsX[1], 1, values[1] };
	double z[4] = { pow(pointsX[2], 2), pointsX[2], 1, values[2] };

	temp[0] = x;
	temp[1] = y;
	temp[2] = z;

	Cramer tempCramer(temp);
	tempCramer.solve();
}

IntegrationRectangleMethod::IntegrationRectangleMethod()
{
}

IntegrationRectangleMethod::IntegrationRectangleMethod(double *formulaNew, int nNew, int startPointNew, int endPointNew, int formulaCountNew)
{
	formula = formulaNew;
	startPoint = startPointNew;
	endPoint = endPointNew;
	n = nNew;
	formulaCount = formulaCountNew;
}

void IntegrationRectangleMethod::solve()
{
	double dx = (double(endPoint) - double(startPoint)) / n;
	double result = 0;
	for (int i = (endPoint - startPoint)-1; i < endPoint+1; i++)
	{
		result = result + formulaResult(i);
	}
	result = result * dx;

	cout << result << endl;
}

double IntegrationRectangleMethod::formulaResult(int point)
{
	double returnedValue = 0;
	returnedValue = returnedValue + formula[0];
	for (int i = 1; i < formulaCount; i++)
	{
		returnedValue = returnedValue + pow(point, i)*formula[i];
	}
	return returnedValue;
}

IntegrationTrapezoidalMethod::IntegrationTrapezoidalMethod()
{
}

IntegrationTrapezoidalMethod::IntegrationTrapezoidalMethod(double *formulaNew, int nNew, int startPointNew, int endPointNew, int formulaCountNew)
{
	formula = formulaNew;
	startPoint = startPointNew;
	endPoint = endPointNew;
	n = nNew;
	formulaCount = formulaCountNew;
}

void IntegrationTrapezoidalMethod::solve()
{
	double dx = (double(endPoint) - double(startPoint)) / n;
	double result = 0;

	for (int i = 0; i < n; i++)
	{
		result = result + (((formulaResult(startPoint+i) + formulaResult(startPoint+i+1)) / 2) * dx);
	}

	cout << result << endl;
}

double IntegrationTrapezoidalMethod::formulaResult(int point)
{
	double returnedValue = 0;
	returnedValue = returnedValue + formula[0];
	for (int i = 1; i < formulaCount; i++)
	{
		returnedValue = returnedValue + pow(point, i)*formula[i];
	}
	return returnedValue;
}

IntegrationSimpsonMethod::IntegrationSimpsonMethod()
{
}

IntegrationSimpsonMethod::IntegrationSimpsonMethod(double *formulaNew, int nNew, int startPointNew, int endPointNew, int formulaCountNew, double hNew)
{
	formula = formulaNew;
	startPoint = startPointNew;
	endPoint = endPointNew;
	n = nNew;
	formulaCount = formulaCountNew;
	h = hNew;
}

void IntegrationSimpsonMethod::solve()
{
	int pointsDistance = (endPoint - startPoint) / h;

	double endResult = 0;

	for (int i = 0; i < pointsDistance; i=i+2)
	{
		endResult = endResult + ((formulaResult(i+startPoint) + 4*formulaResult(i+h+startPoint) + formulaResult(i+h*2+startPoint)) * (h/3));
	}

	cout << endResult << endl;
}

double IntegrationSimpsonMethod::formulaResult(int point)
{
	double returnedValue = 0;
	returnedValue = returnedValue + formula[0];
	for (int i = 1; i < formulaCount; i++)
	{
		returnedValue = returnedValue + pow(point, i)*formula[i];
	}
	return returnedValue;
}

IntegrationMonteCarloMethod::IntegrationMonteCarloMethod()
{
}

IntegrationMonteCarloMethod::IntegrationMonteCarloMethod(double *formulaNew, int nNew, int startPointNew, int endPointNew, int formulaCountNew)
{
	formula = formulaNew;
	startPoint = startPointNew;
	endPoint = endPointNew;
	n = nNew;
	formulaCount = formulaCountNew;
}

void IntegrationMonteCarloMethod::solve()
{
	double* randomPoints = new double[n + 1];
	double result = 0;
	for (int i = 0; i < n; i++)
	{
		randomPoints[i] = randomBetween(startPoint, endPoint);
		result = result + formulaResult(randomPoints[i]) / n;
	}

	result = result * abs(endPoint - startPoint);
	cout << result << endl;
}

double IntegrationMonteCarloMethod::randomBetween(double min, double max)
{
	double f = (double)rand() / RAND_MAX;
	return min + f * (max - min);
}

double IntegrationMonteCarloMethod::formulaResult(int point)
{
	double returnedValue = 0;
	returnedValue = returnedValue + formula[0];
	for (int i = 1; i < formulaCount; i++)
	{
		returnedValue = returnedValue + pow(point, i)*formula[i];
	}
	return returnedValue;
}

GaussianQuadrature::GaussianQuadrature()
{
	wsp_x = new double[4];
	wsp_x[0] = 0;
	wsp_x[1] = 10;
	wsp_x[2] = 10;
	wsp_x[3] = 0;

	wsp_y = new double[4];
	wsp_y[0] = 0;
	wsp_y[1] = 0;
	wsp_y[2] = 10;
	wsp_y[3] = 10;
}

double GaussianQuadrature::result()
{
	wsp_x = new double[4];
	wsp_x[0] = 0;
	wsp_x[1] = 10;
	wsp_x[2] = 10;
	wsp_x[3] = 0;

	wsp_y = new double[4];
	wsp_y[0] = 0;
	wsp_y[1] = 0;
	wsp_y[2] = 10;
	wsp_y[3] = 10;

	double waga[2] = { 1, 1 };
	double punkt[2] = { -0.5773502692, 0.5773502692 };

	double pole = 0;
	double wsp = 0;

	double fksztalt[2][2][4];
	double po_ksi[2][4], po_ni[2][4], fun_detj[2][2];

	for (int ie = 0; ie < 4; ie++)
	{
		for (int je = 0; je < 4; je++)
		{
			for (int i = 0; i < 2; i++)
			{
				double ShapeF;

				for (int j = 0; j < 2; i++)
				{
					fksztalt[i][j][0] = 0.25 * (1 - punkt[i]) * (1 - punkt[j]);
					fksztalt[i][j][1] = 0.25 * (1 - punkt[i]) * (1 - punkt[j]);
					fksztalt[i][j][2] = 0.25 * (1 - punkt[i]) * (1 - punkt[j]);
					fksztalt[i][j][3] = 0.25 * (1 - punkt[i]) * (1 - punkt[j]);

					po_ni[j][0] = -0.25 * (1 - punkt[j]);
					po_ni[j][1] = 0.25 * (1 - punkt[j]);
					po_ni[j][2] = 0.25 * (1 + punkt[j]);
					po_ni[j][3] = -0.25 * (1 + punkt[j]);

					po_ksi[i][0] = -0.25 * (1 - punkt[i]);
					po_ksi[i][1] = -0.25 * (1 + punkt[i]);
					po_ksi[i][2] = 0.25 * (1 + punkt[i]);
					po_ksi[i][3] = 0.25 * (1 - punkt[i]);

					double FdXdQ, FdYdQ, FdXdE, FdYdE;

					FdXdQ = po_ni[j][0] * wsp_x[0] + po_ni[j][1] * wsp_x[1] + po_ni[j][2] * wsp_x[2] + po_ni[j][3] * wsp_x[3];
					FdYdQ = po_ni[j][0] * wsp_y[0] + po_ni[j][1] * wsp_y[1] + po_ni[j][2] * wsp_y[2] + po_ni[j][3] * wsp_y[3];
					FdXdE = po_ksi[i][0] * wsp_x[0] + po_ksi[i][1] * wsp_x[1] + po_ksi[i][2] * wsp_x[2] + po_ksi[i][3] * wsp_x[3];
					FdYdE = po_ksi[i][0] * wsp_y[0] + po_ksi[i][1] * wsp_y[1] + po_ksi[i][2] * wsp_y[2] + po_ksi[i][3] * wsp_y[3];

					fun_detj[i][j] = FdXdQ * FdYdE - FdXdE * FdYdQ;

					wsp = abs(fun_detj[i][j]) * waga[i] * waga[j];

					ShapeF = fksztalt[i][j][ie];
				}

				pole = pole + wsp * ShapeF;
			}
		}
	}

	return pole;
}

BisectionMethod::BisectionMethod()
{
}

BisectionMethod::BisectionMethod(double *formulaNew, int nNew, double aNew, double bNew)
{
	formula = formulaNew;
	n = nNew;
	a = aNew;
	b = bNew;
}

double BisectionMethod::solve()
{
	while (abs(a-b)>0.0001)
	{
		double x1 = (a + b) / 2;
		if (formulaResult(x1) == 0) return x1;
		if (formulaResult(x1)*formulaResult(a) < 0) b = x1;
		if (formulaResult(x1)*formulaResult(b) < 0) a = x1;
	}

	return (a + b) / 2;
}

double BisectionMethod::formulaResult(double point)
{
	double returnedValue = 0;
	returnedValue = returnedValue + formula[0];
	for (int i = 1; i < n; i++)
	{
		returnedValue = returnedValue + pow(point, i)*formula[i];
	}
	return returnedValue;
}

NewtonRaphsonMethod::NewtonRaphsonMethod()
{
}

NewtonRaphsonMethod::NewtonRaphsonMethod(double *formulaNew, int nNew, double aNew, double bNew)
{
	formula = formulaNew;
	n = nNew;
	a = aNew;
	b = bNew;
}


double NewtonRaphsonMethod::solve()
{
	double x[2] = { b, 0 };
	
	while (true)
	{
		x[1] = x[0] - (formulaResult(x[0]) / formulaDerivativeResult(x[0]));
		if(formulaResult(x[1]) <= 0.0001) return x[1];
		else x[0] = x[1];
	}
}

double NewtonRaphsonMethod::formulaResult(double point)
{
	double returnedValue = 0;
	returnedValue = returnedValue + formula[0];
	for (int i = 1; i < n; i++)
	{
		returnedValue = returnedValue + pow(point, i)*formula[i];
	}
	return returnedValue;
}

double NewtonRaphsonMethod::formulaDerivativeResult(double point)
{
	double returnedValue = 0;
	for (int i = 1; i < n; i++)
	{
		returnedValue = returnedValue + i*pow(point, i-1)*formula[i];
	}
	return returnedValue;
}

Differentials::Differentials()
{
}

Differentials::Differentials(double *formulaNew, double nNew)
{
	formula = formulaNew;
	n = nNew;
}

double Differentials::formulaResult(double * formula, double point, double n)
{
	double returnedValue = 0;
	returnedValue = returnedValue + formula[0];
	for (int i = 1; i < n; i++)
	{
		returnedValue = returnedValue + pow(point, i)*formula[i];
	}
	return returnedValue;
}

double **Differentials::eulerMethod(double x0, double b, double h)
{
	double y0 = formulaResult(formula, x0, n);
	int iterations = (b - x0) / h;
	double x = x0, y = y0;
	double const formulaLenght = 2;
	double formula[2] = { 0,1 };

	double** returnedValue = new double*[iterations + 1];
	for (int i = 0; i < iterations + 1; i++)
		returnedValue[i] = new double[iterations + 1];

	returnedValue[0][0] = x;
	returnedValue[1][0] = y;

	cout << y0 << endl;

	for (int i = 1; i <= iterations; i++)
	{
		y = y + h * formulaResult(formula, y, formulaLenght);
		x = x + h;
		returnedValue[0][i] = x;
		returnedValue[1][i] = y;

		cout << returnedValue[1][i] << endl;
	}

	return returnedValue;
}

double **Differentials::heunMethod(double x0, double b, double h)
{
	double y0 = formulaResult(formula, x0, n);
	int iterations = (b - x0) / h;
	double x = x0, y = y0;
	double formula[2] = { 0,1 };
	double const formulaLenght = 2;

	double** returnedValue = new double*[iterations + 1];
	for (int i = 0; i < iterations + 1; i++)
		returnedValue[i] = new double[iterations + 1];

	returnedValue[0][0] = x;
	returnedValue[1][0] = y;
	for (int i = 1; i <= iterations; i++)
	{
		y = y + h / 2 * (formulaResult(formula, y, formulaLenght) + formulaResult(formula, y + h * formulaResult(formula, y, formulaLenght), formulaLenght));
		x = x + h;
		returnedValue[0][i] = x;
		returnedValue[1][i] = y;

		cout << returnedValue[1][i] << endl;
	}

	return returnedValue;
}

double **Differentials::RK4Method(double x0, double b, double h)
{
	double y0 = formulaResult(formula, x0, n);
	int iterations = (b - x0) / h;
	double x = x0, y = y0;
	double k1, k2, k3, k4;
	double formula[2] = { 0,1 };
	double const formulaLenght = 2;

	double** returnedValue = new double*[iterations + 1];
	for (int i = 0; i < iterations + 1; i++)
		returnedValue[i] = new double[iterations + 1];

	returnedValue[0][0] = x;
	returnedValue[1][0] = y;
	for (int i = 1; i <= iterations; i++)
	{
		k1 = h * formulaResult(formula, y, formulaLenght);
		k2 = h * formulaResult(formula, y + 0.5*k1, formulaLenght);
		k3 = h * formulaResult(formula, y + 0.5*k2, formulaLenght);
		k4 = h * formulaResult(formula, y + k3, formulaLenght);

		y = y + (k1 + 2 * k2 + 2 * k3 + k4) / 6;
		x = x + h;
		returnedValue[0][i] = x;
		returnedValue[1][i] = y;

		cout << returnedValue[1][i] << endl;
	}

	return returnedValue;
}
