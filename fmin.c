#include <stdio.h>
#include <math.h>
double f(double x)
{
return  2*x*x*x-12*x*x+18*x+3;
	

	}
int min_half(double *x, double a, double b,double (*f)(double), double epsilon)
{ 	double x2=(a+b)/2.0; double f2=f(x2); 
	double x1=(a+x2)/2.0; double f1=f(x1);
	double x3=(x2+b)/2.0; double f3=f(x3);
	int k=0;
while( fabs(a-b)>epsilon && fabs(a-b)>epsilon*fabs(a+b)/2.0)	
	{ if(f1<f2 && f1<f3)
		{
		   x2=x1; 	
			b=x2;
            f2=f1;			
			}else if(f2<f1 && f2<f3)
		{
			a=x1;
			b=x3;
			}else {
				a=x2;
				x2=x3;
				f2=f3;
				}
		x1=(a+x2)/2.0;
		f1=f(x1);
		x3=(x2+b)/2.0;
		f3=f(x3);
		k++;
		}
	*x=x2;
	return k;
	}
int main ()
{ double x; int k;
k=min_half(&x,-1,3,f,1e-15);
printf("xmin=%lf f(xmin)=%lf k=%d",x,f(x),k);
return 0;
}
