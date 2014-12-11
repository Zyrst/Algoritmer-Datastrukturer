#include <iostream>



int trivial(int i)
{
	if(i = 1)
		return 1;
	else
	{
		return(trivial(i - 1) + trivial((i/2) + 1);
	}
}



int main()
{
	std::cout << fibonacci(20);
}