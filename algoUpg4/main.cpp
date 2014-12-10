#include <iostream>

int fibonacci(int i)
{
	if(i <= 2)
		return 1;
	else
		return fibonacci(i - 1) + fibonacci (i - 2);
}



int main()
{
	std::cout << fibonacci(20);
}