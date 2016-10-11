#include<stdio.h>
#include<math.h>

double CompositeMethod(double a, double b, double epsilon);
double RectangleMethod(double f, double a, double b);
int RungesRule(double I2n, double In, double epsilon);
double f(double x);

int main(void)
{
	double a, b;
    
    a = 0;
    b = 1.5;
	
	printf("%lf\n", CompositeMethod(a, b, 0.000001));
	
	return 0;
}

double CompositeMethod(double a, double b, double epsilon)
{
    int n;
    double In, I2n, h, xi, xj;
    
    In = RectangleMethod(f((a+b)/2.0), a, b);
    I2n = RectangleMethod(f((3.0*a+b)/4.0), a, (a+b)/2.0) + 
        RectangleMethod(f((a+3.0*b)/2.0), (a+b)/2.0, b);
    n = 4;
    while(!RungesRule(I2n, In, epsilon))
    {
        h = (b - a)/n;
        xj = xi = a;
        In = I2n;
        I2n = 0.0;
        while(b - xj > 0)
        {
            xi = xj;
            xj = xi + h;
            I2n += RectangleMethod(f((xi+xj)/2.0), xi, xj);
        }
        
        n *= 2;
    }
    
    return I2n;
}

double RectangleMethod(double f, double a, double b)
{
    return f*(b - a);
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
