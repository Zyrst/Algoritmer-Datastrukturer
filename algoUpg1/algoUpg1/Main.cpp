#include <vector>
#include <iostream>



void bucketSort(std::vector<int> v)
{
	int biggestValue = 0;
	// Hittar st�rsta v�rde. 
	// dvs. K	
	for (int i = 0; i < v.size(); i++)
	{
		if (i == 0)
			biggestValue = v[i];

		else if (v[i] > biggestValue && i > 0)
		{
			biggestValue = v[i];
		}		 
	}

	// Skapar ny vector. 
	std::vector<int> newBucket;
	//Fyller alla utom sista elementet med 0
	for (int i = 0; i <= biggestValue; i++)
	{
		newBucket.push_back(0);
	}

	for (int i = 0; i < v.size(); i++)
	{
		// R�knar antalet g�nger en siffra kommer upp. 
		// V�rdet i v blir en position i newBucket.
		newBucket[v[i]]++; 
	}
	
	for (auto k : newBucket)
	{
		std::cout << k << std::endl;
	}
		
}

int main()
{
	std::vector<int> unsorted = { 5, 6, 4, 3, 2, 1, 0, 2, 1 };
	bucketSort(unsorted);
	getchar();
}