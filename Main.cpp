#include "SwatMath.h"
#include "ctime"
#include "cstdlib"
#include <chrono>

using namespace std::chrono;

int main()
{
	srand(time(NULL));

	double lagrange1Values[3] = { 12, 4, 4 };
	double lagrange1Number[3] = { 1, 3, 5 };
	LagrangeInterpolation lagrange1(3, lagrange1Values, lagrange1Number);
	NewtonInterpolation newton1(3, lagrange1Values, lagrange1Number);
	cout << "Interpolation for points 1, 3 and 5 with values 12, 4, 4" << endl;
	high_resolution_clock::time_point t1 = high_resolution_clock::now();
	cout << "Value in x=4 using Lagrange: " << lagrange1.returnValue(4) << endl;
	high_resolution_clock::time_point t2 = high_resolution_clock::now();
	auto duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;
	t1 = high_resolution_clock::now();
	cout << "Value in x=4 using Newton: " << newton1.returnValue(4) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	t1 = high_resolution_clock::now();
	cout << "Value in x=16 using Lagrange: " << lagrange1.returnValue(16) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	t1 = high_resolution_clock::now();
	cout << "Value in x=16 using Newton: " << newton1.returnValue(16) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	t1 = high_resolution_clock::now();
	cout << "Value in x=7 using Lagrange: " << lagrange1.returnValue(7) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	t1 = high_resolution_clock::now();
	cout << "Value in x=7 using Newton: " << newton1.returnValue(7) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	t1 = high_resolution_clock::now();
	cout << "Value in x=2 using Lagrange: " << lagrange1.returnValue(2) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	t1 = high_resolution_clock::now();
	cout << "Value in x=2 using Newton: " << newton1.returnValue(2) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	cout << "================================" << endl;

	cout << "Interpolation for points 3, 8 and 1 with values 34, 22, 5" << endl;
	double lagrange2Values[3] = { 34, 22, 5 };
	double lagrange2Number[3] = { 3, 8, 1 };
	LagrangeInterpolation lagrange2(3, lagrange2Values, lagrange2Number);
	NewtonInterpolation newton2(3, lagrange2Values, lagrange2Number);

	t1 = high_resolution_clock::now();
	cout << "Value in x=4 using Lagrange: " << lagrange2.returnValue(4) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	t1 = high_resolution_clock::now();
	cout << "Value in x=4 using Newton: " << newton2.returnValue(4) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	t1 = high_resolution_clock::now();
	cout << "Value in x=16 using Lagrange: " << lagrange2.returnValue(16) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	t1 = high_resolution_clock::now();
	cout << "Value in x=16 using Newton: " << newton2.returnValue(16) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	t1 = high_resolution_clock::now();
	cout << "Value in x=7 using Lagrange: " << lagrange2.returnValue(7) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	t1 = high_resolution_clock::now();
	cout << "Value in x=7 using Newton: " << newton2.returnValue(7) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	t1 = high_resolution_clock::now();
	cout << "Value in x=2 using Lagrange: " << lagrange2.returnValue(2) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	t1 = high_resolution_clock::now();
	cout << "Value in x=2 using Newton: " << newton2.returnValue(2) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	cout << "================================" << endl;

	cout << "Interpolation for points 5, 1, 8 and 3 with values 3, 5, 4, 9" << endl;
	double lagrange3Values[4] = { 3, 5, 4, 9 };
	double lagrange3Number[4] = { 5, 1, 8, 3 };
	LagrangeInterpolation lagrange3(4, lagrange3Values, lagrange3Number);
	NewtonInterpolation newton3(4, lagrange3Values, lagrange3Number);

	t1 = high_resolution_clock::now();
	cout << "Value in x=4 using Lagrange: " << lagrange3.returnValue(4) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	t1 = high_resolution_clock::now();
	cout << "Value in x=4 using Newton: " << newton3.returnValue(4) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	t1 = high_resolution_clock::now();
	cout << "Value in x=16 using Lagrange: " << lagrange3.returnValue(16) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	t1 = high_resolution_clock::now();
	cout << "Value in x=16 using Newton: " << newton3.returnValue(16) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	t1 = high_resolution_clock::now();
	cout << "Value in x=7 using Lagrange: " << lagrange3.returnValue(7) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	t1 = high_resolution_clock::now();
	cout << "Value in x=7 using Newton: " << newton3.returnValue(7) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	t1 = high_resolution_clock::now();
	cout << "Value in x=2 using Lagrange: " << lagrange3.returnValue(2) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	t1 = high_resolution_clock::now();
	cout << "Value in x=2 using Newton: " << newton3.returnValue(2) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	cout << "================================" << endl;

	cout << "Interpolation for points 1, 66, 3 and 9 with values 58, 3728, 45, 20" << endl;
	double lagrange4Values[4] = { 58, 3728, 45, 20 };
	double lagrange4Number[4] = { 1, 66, 3, 9 };
	LagrangeInterpolation lagrange4(4, lagrange4Values, lagrange4Number);
	NewtonInterpolation newton4(4, lagrange4Values, lagrange4Number);

	t1 = high_resolution_clock::now();
	cout << "Value in x=4 using Lagrange: " << lagrange4.returnValue(4) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	t1 = high_resolution_clock::now();
	cout << "Value in x=4 using Newton: " << newton4.returnValue(4) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	t1 = high_resolution_clock::now();
	cout << "Value in x=16 using Lagrange: " << lagrange4.returnValue(16) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	t1 = high_resolution_clock::now();
	cout << "Value in x=16 using Newton: " << newton4.returnValue(16) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	t1 = high_resolution_clock::now();
	cout << "Value in x=7 using Lagrange: " << lagrange4.returnValue(7) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	t1 = high_resolution_clock::now();
	cout << "Value in x=7 using Newton: " << newton4.returnValue(7) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	t1 = high_resolution_clock::now();
	cout << "Value in x=2 using Lagrange: " << lagrange4.returnValue(2) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	t1 = high_resolution_clock::now();
	cout << "Value in x=2 using Newton: " << lagrange4.returnValue(2) << endl;
	t2 = high_resolution_clock::now();
	duration = duration_cast<nanoseconds>(t2 - t1).count();
	cout << "Time it took to execute: " << duration << " nanoseconds" << endl;

	cout << "================================" << endl;

	cout << "Solving equations using Cramer's rule" << endl;
	cout << "x:    2, 4, 3" << endl;
	cout << "y:    5, 2, 8" << endl;
	cout << "z:    3, 5, 4" << endl;
	cout << "f(x): 5, 4, 9" << endl;

	double** pointsXCramer1 = new double*[4];

	double xCramer1[4] = { 2, 5, 3, 5 };
	double yCramer1[4] = { 4,2,5,4 };
	double zCramer1[4] = { 3,8,4,9 };

	pointsXCramer1[0] = xCramer1;
	pointsXCramer1[1] = yCramer1;
	pointsXCramer1[2] = zCramer1;

	Cramer cramer1(pointsXCramer1);
	cramer1.solve();

	cout << "================================" << endl;

	cout << "x:    6, 5, 2" << endl;
	cout << "y:    5, 6, 8" << endl;
	cout << "z:    2, 11, 2" << endl;
	cout << "f(x): 9, 7, 3" << endl;

	double** pointsXCramer2 = new double*[4];

	double xCramer2[4] = { 6, 5, 2, 9 };
	double yCramer2[4] = { 5,6,11,7 };
	double zCramer2[4] = { 2,8,2,3 };

	pointsXCramer2[0] = xCramer2;
	pointsXCramer2[1] = yCramer2;
	pointsXCramer2[2] = zCramer2;

	Cramer cramer2(pointsXCramer2);
	cramer2.solve();

	cout << "================================" << endl;

	cout << "x:    2.33, 5.55, 2" << endl;
	cout << "y:    1.98, 8.2, 4" << endl;
	cout << "z:    5.69, 9.4, 5.09" << endl;
	cout << "f(x): 9, 3.2, 23" << endl;

	double** pointsXCramer3 = new double*[4];

	double xCramer3[4] = { 2.33, 1.98, 5.69, 9 };
	double yCramer3[4] = { 5.55,8.2,9.4,23 };
	double zCramer3[4] = { 2,4,5.09,23 };

	pointsXCramer3[0] = xCramer3;
	pointsXCramer3[1] = yCramer3;
	pointsXCramer3[2] = zCramer3;

	Cramer cramer3(pointsXCramer3);
	cramer3.solve();

	cout << "================================" << endl;

	cout << "x:    71, 1.01, 0.02" << endl;
	cout << "y:    22, 2, 2.59" << endl;
	cout << "z:    3, 5.9, 6.9" << endl;
	cout << "f(x): 6.9239, 2.1, 7.77" << endl;

	double** pointsXCramer4 = new double*[4];

	double xCramer4[4] = { 77, 22, 3, 6.9239 };
	double yCramer4[4] = { 1.01,2,5.9,2.1 };
	double zCramer4[4] = { 0.02,2.59,6.9,7.77 };

	pointsXCramer4[0] = xCramer4;
	pointsXCramer4[1] = yCramer4;
	pointsXCramer4[2] = zCramer4;

	Cramer cramer4(pointsXCramer4);
	cramer4.solve();

	cout << "================================" << endl;

	cout << "Solving integrals using Rectangle and Trapezoidal methods" << endl;
	cout << "f(x)=x^3+2" << endl;
	cout << "n=3" << endl << "Xp = 1" << endl << "Xk = 4" << endl;
	double formulaForIntegrals1[4] = { 2, 0, 0, 1 };
	IntegrationRectangleMethod testRectangle1(formulaForIntegrals1, 3, 1, 4, 4);
	cout << "Rectangle method: ";
	testRectangle1.solve();

	IntegrationTrapezoidalMethod testTrapezoidal1(formulaForIntegrals1, 3, 1, 4, 4);
	cout << "Trapezoidal method: ";
	testTrapezoidal1.solve();

	cout << "================================" << endl;

	cout << "f(x)=x^2-4" << endl;
	cout << "n=3" << endl << "Xp = 1" << endl << "Xk = 4" << endl;
	double formulaForIntegrals2[3] = { -4, 0, 1 };
	IntegrationRectangleMethod testRectangle2(formulaForIntegrals2, 3, 1, 4, 3);
	cout << "Rectangle method: ";
	testRectangle2.solve();

	IntegrationTrapezoidalMethod testTrapezoidal2(formulaForIntegrals2, 3, 1, 4, 3);
	cout << "Trapezoidal method: ";
	testTrapezoidal2.solve();

	cout << "================================" << endl;

	cout << "f(x)=x^4+x^2+2" << endl;
	cout << "n=3" << endl << "Xp = 1" << endl << "Xk = 4" << endl;
	double formulaForIntegrals3[5] = { 2, 0, 1, 0, 1 };
	IntegrationRectangleMethod testRectangle3(formulaForIntegrals3, 3, 1, 4, 5);
	cout << "Rectangle method: ";
	testRectangle3.solve();

	IntegrationTrapezoidalMethod testTrapezoidal3(formulaForIntegrals3, 3, 1, 4, 5);
	cout << "Trapezoidal method: ";
	testTrapezoidal3.solve();

	cout << "================================" << endl;

	cout << "f(x)=2x-2" << endl;
	cout << "n=3" << endl << "Xp = 1" << endl << "Xk = 4" << endl;
	double formulaForIntegrals4[2] = { -2, 2 };
	IntegrationRectangleMethod testRectangle4(formulaForIntegrals4, 3, 1, 4, 2);
	cout << "Rectangle method: ";
	testRectangle4.solve();

	IntegrationTrapezoidalMethod testTrapezoidal4(formulaForIntegrals4, 3, 1, 4, 2);
	cout << "Trapezoidal method: ";
	testTrapezoidal4.solve();

	cout << "================================" << endl;

	cout << "Solving integrals using Simpson's and Monte Carlo methods" << endl;
	cout << "f(x)=x^3+2" << endl;
	cout << "n=4" << endl << "Xp = 1" << endl << "Xk = 5" << endl << "h = 1" << endl;
	IntegrationSimpsonMethod simpson1(formulaForIntegrals1, 4, 1, 5, 4, 1);
	cout << "Simpson's method: ";
	simpson1.solve();

	IntegrationMonteCarloMethod monte1(formulaForIntegrals1, 4, 1, 5, 4);
	cout << "Monte Carlo method: ";
	monte1.solve();

	cout << "================================" << endl;

	cout << "f(x)=x^2-4" << endl;
	cout << "n=4" << endl << "Xp = 1" << endl << "Xk = 5" << endl << "h = 1" << endl;
	IntegrationSimpsonMethod simpson2(formulaForIntegrals2, 4, 1, 5, 3, 1);
	cout << "Simpson's method: ";
	simpson2.solve();

	IntegrationMonteCarloMethod monte2(formulaForIntegrals2, 4, 1, 5, 3);
	cout << "Monte Carlo method: ";
	monte2.solve();

	cout << "================================" << endl;

	cout << "f(x)=x^4+x^2+2" << endl;
	cout << "n=4" << endl << "Xp = 1" << endl << "Xk = 5" << endl << "h = 1" << endl;
	IntegrationSimpsonMethod simpson3(formulaForIntegrals3, 4, 1, 5, 5, 1);
	cout << "Simpson's method: ";
	simpson3.solve();

	IntegrationMonteCarloMethod monte3(formulaForIntegrals3, 4, 1, 5, 5);
	cout << "Monte Carlo method: ";
	monte3.solve();

	cout << "================================" << endl;

	cout << "f(x)=2x-2" << endl;
	cout << "n=4" << endl << "Xp = 1" << endl << "Xk = 5" << endl << "h = 1" << endl;
	IntegrationSimpsonMethod simpson4(formulaForIntegrals4, 4, 1, 5, 2, 1);
	cout << "Simpson's method: ";
	simpson4.solve();

	IntegrationMonteCarloMethod monte4(formulaForIntegrals4, 4, 1, 5, 2);
	cout << "Monte Carlo method: ";
	monte4.solve();

	cout << "================================" << endl;

	cout << "Solving nonlinear equations using Bisection and Newton-Raphson methods" << endl;
	cout << "f(x)=x^3+2" << endl;
	cout << "<-9; 12>" << endl;

	BisectionMethod testBisection1(formulaForIntegrals1, 4, -9, 12);
	NewtonRaphsonMethod testNRMethod1(formulaForIntegrals1, 4, -9, 12);
	cout << "Bisection: " << testBisection1.solve() << endl;
	cout << "Newton-Raphson: " << testNRMethod1.solve() << endl;

	cout << "================================" << endl;

	cout << "f(x)=x^2-4" << endl;
	cout << "<-9; 12>" << endl;

	BisectionMethod testBisection2(formulaForIntegrals2, 3, -9, 12);
	NewtonRaphsonMethod testNRMethod2(formulaForIntegrals2, 3, -9, 12);
	cout << "Bisection: " << testBisection2.solve() << endl;
	cout << "Newton-Raphson: " << testNRMethod2.solve() << endl;

	cout << "================================" << endl;

	cout << "f(x)=x^2-66" << endl;
	cout << "<-9; 12>" << endl;
	double formulaForIntegrals5[3] = { -66, 0, 1 };
	BisectionMethod testBisection3(formulaForIntegrals5, 3, -9, 12);
	NewtonRaphsonMethod testNRMethod3(formulaForIntegrals5, 3, -9, 12);
	cout << "Bisection: " << testBisection3.solve() << endl;
	cout << "Newton-Raphson: " << testNRMethod3.solve() << endl;

	cout << "================================" << endl;

	cout << "f(x)=x^3+x^2+x+1" << endl;
	cout << "<-9; 12>" << endl;
	double formulaForIntegrals6[4] = { 1, 1, 1, 1 };
	BisectionMethod testBisection4(formulaForIntegrals6, 4, -9, 12);
	NewtonRaphsonMethod testNRMethod4(formulaForIntegrals6, 4, -9, 12);
	cout << "Bisection: " << testBisection4.solve() << endl;
	cout << "Newton-Raphson: " << testNRMethod4.solve() << endl;

	cout << "================================" << endl;

	cout << "Solving differential equations using Euler, Heun and RK4 methods" << endl;
	cout << "f(x)=x^3+2" << endl;
	cout << "<0; 1>" << endl << "h = 0.1" << endl;
	Differentials newDifferential(formulaForIntegrals1, 4);
	cout << "Euler method: " << endl;
	t1 = high_resolution_clock::now();
	newDifferential.eulerMethod(0, 1, 0.1);
	t2 = high_resolution_clock::now();
	cout << "Time it took to execute: " << duration_cast<nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;
	cout << "Heun method: " << endl;
	t1 = high_resolution_clock::now();
	newDifferential.heunMethod(0, 1, 0.1);
	t2 = high_resolution_clock::now();
	cout << "Time it took to execute: " << duration_cast<nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;
	cout << "RK4 method: " << endl;
	t1 = high_resolution_clock::now();
	newDifferential.RK4Method(0, 1, 0.1);
	t2 = high_resolution_clock::now();
	cout << "Time it took to execute: " << duration_cast<nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	cout << "================================" << endl;

	cout << "f(x)=x^2-4" << endl;
	cout << "<0; 1>" << endl << "h = 0.1" << endl;
	Differentials newDifferential1(formulaForIntegrals2, 3);
	cout << "Euler method: " << endl;
	t1 = high_resolution_clock::now();
	newDifferential1.eulerMethod(0, 1, 0.1);
	t2 = high_resolution_clock::now();
	cout << "Time it took to execute: " << duration_cast<nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;
	cout << "Heun method: " << endl;
	t1 = high_resolution_clock::now();
	newDifferential1.heunMethod(0, 1, 0.1);
	t2 = high_resolution_clock::now();
	cout << "Time it took to execute: " << duration_cast<nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;
	cout << "RK4 method: " << endl;
	t1 = high_resolution_clock::now();
	newDifferential1.RK4Method(0, 1, 0.1);
	t2 = high_resolution_clock::now();
	cout << "Time it took to execute: " << duration_cast<nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	cout << "================================" << endl;
	cout << "f(x)=x^2-66" << endl;
	cout << "<0; 1>" << endl << "h = 0.1" << endl;
	Differentials newDifferential2(formulaForIntegrals5, 5);
	cout << "Euler method: " << endl;
	t1 = high_resolution_clock::now();
	newDifferential2.eulerMethod(0, 1, 0.1);
	t2 = high_resolution_clock::now();
	cout << "Time it took to execute: " << duration_cast<nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;
	cout << "Heun method: " << endl;
	t1 = high_resolution_clock::now();
	newDifferential2.heunMethod(0, 1, 0.1);
	t2 = high_resolution_clock::now();
	cout << "Time it took to execute: " << duration_cast<nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;
	cout << "RK4 method: " << endl;
	t1 = high_resolution_clock::now();
	newDifferential2.RK4Method(0, 1, 0.1);
	t2 = high_resolution_clock::now();
	cout << "Time it took to execute: " << duration_cast<nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	cout << "================================" << endl;
	cout << "f(x)=2x-2" << endl;
	cout << "<0; 1>" << endl << "h = 0.1" << endl;
	Differentials newDifferential3(formulaForIntegrals4, 2);
	cout << "Euler method: " << endl;
	t1 = high_resolution_clock::now();
	newDifferential3.eulerMethod(0, 1, 0.1);
	t2 = high_resolution_clock::now();
	cout << "Time it took to execute: " << duration_cast<nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;
	cout << "Heun method: " << endl;
	t1 = high_resolution_clock::now();
	newDifferential3.heunMethod(0, 1, 0.1);
	t2 = high_resolution_clock::now();
	cout << "Time it took to execute: " << duration_cast<nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;
	cout << "RK4 method: " << endl;
	t1 = high_resolution_clock::now();
	newDifferential3.RK4Method(0, 1, 0.1);
	t2 = high_resolution_clock::now();
	cout << "Time it took to execute: " << duration_cast<nanoseconds>(t2 - t1).count() << " nanoseconds" << endl;

	cout << "================================" << endl;
}