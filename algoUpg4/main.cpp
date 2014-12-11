#include <iostream>
#include <vector>


int trivial(int i)
{
	if(i == 1)
		return 1;
	else
	{
		return trivial(i - 1) + trivial(i/2) + i;
	}
}

std::vector<int> v;


int moreComplex(int i)
{
	if(i == 1)
		v[i] = 1;
	else{
		if(v[i] == -1)
			v[i] = moreComplex(i - 1) + moreComplex(i/2) + i;
	}	
	return v[i];
}

int main()
{
	int numb = 500;

	for(int i = 0; i <= numb; i++)
		v.push_back(-1);


	std::cout <<  moreComplex(numb);

	getchar();

	std::cout << trivial(numb);
	
}