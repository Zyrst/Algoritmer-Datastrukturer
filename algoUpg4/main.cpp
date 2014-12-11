#include <iostream>
#include <vector>


int trivial(int i)
{
	if(i == 1)
		return 1;
	else
	{
		return(trivial(i - 1) + trivial((i/2) + i));
	}
}

std::vector<int> v;


int moreComplex(int i)
{
	if(i == 1)
		return 1;
	else{
		if(v[i] == -1)
		{
			int r 	= moreComplex((i-1) + ((i/2 ) +1));
			v[i] 	= r;
		}
		std::cout << v[i];
		return v[i];
	}

}

int main()
{
	int numb = 20;

	for(int i = 0; i < numb; i++)
		v.push_back(-1);

	std::cout << moreComplex(numb);
}