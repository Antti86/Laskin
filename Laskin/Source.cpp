#include <iostream>
#include <string>
#include <cmath>
#include <limits>

void virhe() // Virhe Funktio, tyhjent‰‰ cin streamin
{
	std::cout << "Virhe" << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int Fib(int n)
{
	if (n <= 1)
	{
		return n;
	}
	return Fib(n - 1) + Fib(n - 2);
}
void Fibonacci()
{
	int n;
	std::cout << "Anna haluamasi fib numero ";
	std::cin >> n;
	if (std::cin.fail() || n > 30)
	{
		virhe();
	}
	else
	{
		std::cout << "Fib numero on " << Fib(n) << std::endl;
	}
	
}

void keskiarvo()
{
	double a, b;
	std::cout << "Anna kaksi numeroa" << std::endl;
	std::cin >> a >> b;
	if (std::cin.fail())
	{
		virhe();
	}	
	else
	{
		std::cout << "Tulos: " << (a + b) / 2;
	}
}


void power()
{
	int kanta, potenssi;

	std::cout << "\nAnna kanta ja potenssi" << std::endl;
	std::cin >> kanta >> potenssi;
	if (std::cin.fail())
	{
		virhe();
	}	
	else
	{
		std::cout << pow(kanta, potenssi);
	}
}

double laskin()
{
	double a, b, tulos;
	char toimitus;
	{	
		std::cout << "Anna laskutoimitus" << std::endl;
		std::cin >> a >> toimitus >> b;
		if (std::cin.fail()) 
		{
			virhe();
			return 0;
		}
		else if (toimitus == '+')
		{
			tulos = a + b;
		}
		else if (toimitus == '-')
		{
			tulos = a - b;
		}
		else if (toimitus == '*')
		{
			tulos = a * b;
		}
		else if (toimitus == '/')
		{
			tulos = a / b;
		}
		std::cout << "\nTulos: " <<  tulos;

	}
	while (!std::cin.fail())
	{

		std::cin >> toimitus >> a;
		if (std::cin.fail()) 
		{
			virhe();
			return 0;
		}
		else if (toimitus == '+')
		{
			tulos = tulos + a;
		}	
		else if (toimitus == '-')
		{
			tulos = tulos - a;
		}	
		else if (toimitus == '*')
		{
			tulos = tulos * a;
		}
		else if (toimitus == '/')
		{
			tulos = tulos / a;
		}
		std::cout << "\nTulos: " << tulos;

	}
	return tulos;
}

int main() {

	int valinta;
	do 
	{
		std::cout << "\n0.Lopetus\n" << "1.Laskin\n" << "2.Potensilaskuri\n";
		std::cout << "3.Keskiarvo_Laskin" << std::endl;
		std::cout << "4.Fibonacci Laskin" << std::endl;
		std::cin >> valinta;

		switch (valinta)
		{
		case 0:
			std::cout << "Lopetetaan" << std::endl;
			return 0;
		case 1:
			laskin();
			break;
		case 2:
			power();
			break;
		case 3: 
			keskiarvo();
			break; 
		case 4:
			Fibonacci();
			break;
		}
	}
	while (valinta != 0);

}