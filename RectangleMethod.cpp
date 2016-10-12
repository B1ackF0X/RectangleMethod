#include<stdio.h>
#include<math.h>

#define A 0.0
#define B 1.57
#define EPSILON 0.000001

double CompositeMethod(double a, double b, double epsilon);
double RectangleMethod(double f, double h);
int RungesRule(double I2n, double In, double epsilon);
double f(double x);

int main(void)
{
	printf("%lf\n", CompositeMethod(A, B, EPSILON));
	
	return 0;
}

double CompositeMethod(double a, double b, double epsilon)
{
    int n;
    double In, I2n, h, xi;
    
    In = RectangleMethod(f((a+b)/2.0), b - a);
    I2n = RectangleMethod(f((3.0*a+b)/4.0), (b - a)/2.0) + 
        RectangleMethod(f((a+3.0*b)/2.0), (b - a)/2.0);
    
    for(n = 4; !RungesRule(I2n, In, epsilon); n *= 2)
    {
        h = (b - a)/n;
        xi = a;
        In = I2n;
        for(I2n = 0.0; b - xi - h > 0; xi += h)
            I2n += RectangleMethod(f(xi + h/2.0), h);
    }
    
    return I2n;
}

double RectangleMethod(double f, double h)
{
    return f*h;
}

int RungesRule(double I2n, double In, double epsilon)
{
    if(fabs(I2n-In)/3.0 < epsilon)
        return 1;
    
    return 0;
}

double f(double x)
{
    return sin(x);
}
