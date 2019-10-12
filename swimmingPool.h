#include <iostream>
#include <string>
#include <iomanip>

#ifndef H_swimmingPool
#define H_swimmingPool

using namespace std;

class swimmingPool
{
	public :
	
		swimmingPool(double length, double width, double depth, double fillRate, double drainRate)
		{
			length = l;
			width = w;
			depth = d;
			fillRate = fRate;
			drainRate = dRate;
		}
		
	void setDemensions(double length, double width, double depth)
	{
		l = length;
		w = width;
		d = depth;
	}
	
	void setRates(double fillRate, double drainRate)
	{
		fRate = fillRate;
		dRate = drainRate;
	}
	
	void printGalNeeded()
	{
		cout << "Gallons needed to completely fill the pool: " << (((l*w)*d)*7.5);
	}

	void printPartGalNeeded(int currentGal)
	{
		cout << "Gallons needed to finish filling the pool: " << ((((l*w)*d)*7.5)-currentGal);
	}


	void printFillTime()
	{	
		if (((((l*w)*d)*7.5)/fRate) < 60)
		{
			cout << "Time needed to completly fill the pool: " << ((((l*w)*d)*7.5)/fRate) << " minutes"; 
		}
		else if (((((l*w)*d)*7.5)/fRate) >= 60) 
		{
			cout << fixed << setprecision(2);
			cout << "Time needed to completly fill the pool: " << (((((l*w)*d)*7.5)/fRate)/60) << " hours";
		}
	}

	void printDrainTime()
	{
		if (((((l*w)*d)*7.5)/dRate) < 60)
		{			
			cout  << "Time needed to completly drain the pool: " << ((((l*w)*d)*7.5)/dRate) << " minutes"; 
		}
		else if (((((l*w)*d)*7.5)/dRate) >= 60)
		{
			cout << fixed << setprecision(2);
			cout << "Time needed to completly drain the pool: " << (((((l*w)*d)*7.5)/dRate)/60) << " hours";
		}
	}

	void printPartFillTime(int currentGal)
	{
		if (((((l*w)*d)*7.5)/fRate) < 60)
		{			
			cout << "Time needed to completly fill the pool: " << (((((l*w)*d)*7.5)-currentGal)/fRate) << " minutes"; 
		}
		else if (((((l*w)*d)*7.5)/fRate) >= 60)
		{
			cout << fixed << setprecision(2);
			cout << "Time needed to completly fill the pool: " << ((((((l*w)*d)*7.5)-currentGal)/fRate)/60) << " hours";
		}
	}

	void printPartDrainTime(int currentGal)
	{
		if (((((l*w)*d)*7.5)/dRate) < 60)
		{			
			cout << "Time needed to completly drain the pool: " << ((currentGal)/dRate) << " minutes"; 
		}
		else if (((((l*w)*d)*7.5)/dRate) >= 60)
		{
			cout << fixed << setprecision(2);
			cout << "Time needed to completly drain the pool: " << (((currentGal)/dRate)/60) << " hours";
		}
	}
	
	void printTimedFillAmount(int time) //minutes
	{
		if ((fRate * time) > (((l*w)*d)*7.5))
			cout << "This amount of time would overflow the pool by " << ((fRate * time) - (((l*w)*d)*7.5)) << " gallons";
		else
			cout << "There would be " << (fRate * time) << " gallons in the pool after filling for " << time << " minutes";					
	}
	
	void printTimedDrainAmount(int time) //minutes
	{
		if ((dRate * time) > (((l*w)*d)*7.5))
			cout << "The pool would be completly empty after " << ((((l*w)*d)*7.5)/dRate) << " minutes";
		else 
			cout << "There would be " << ((((l*w)*d)*7.5)-(dRate * time)) << " gallons in the pool after draining " << time << " minutes";
	}

	
	

	private :
	double l,w,d,fRate,dRate;
};

#endif
