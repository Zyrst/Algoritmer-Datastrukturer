#include <vector>
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <chrono>

// For extensive tests.
std::vector<int> createVector(int numbOfPosts)
{
	std::vector<int> v;
	srand(time(NULL));
	for (int i = 0; i < numbOfPosts; i++)
	{		
		v.push_back(rand() % numbOfPosts + 1);
	}
	return v;
}


/* Different sort algorithms 
 * returns the time it took to sort (NOT including print time.). */


double insertionSort(std::vector<int> v)
{	
	double timeToComplete;

	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	// Shitty sortering
	//while (!std::is_sorted(v.begin(), v.end()))
	for (int i = 1; i < v.size(); i++)
	{
		for (int i = 1; i < v.size(); i++)
		{
			if (v[i] < v[i - 1])
			{
				std::swap(v[i - 1], v[i]);
				if (i > 0)
					i--;
			}
		}
	}	
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	//for(auto i : v)
	//{
	//	std::cout << i << std::endl;
	//}

	return  timeToComplete = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

double bucketSort(std::vector<int> v)
{
	int biggestValue = 0;
	double timeToComplete;
	std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
	// Hittar största värde. 
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
		// Räknar antalet gånger en siffra kommer upp. 
		// Värdet i v blir en position i newBucket.
		newBucket[v[i]]++; 
	}
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	//for (auto k : newBucket)
	//{
	//	std::cout << k << std::endl;
	//}
	return  timeToComplete = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
}


int main()
{
	for (int i = 0; i <= 20; i++)
	{
		int numOfItems = 1000 + (i * 100);
		std::cout << "Time to sort " << numOfItems << " items with insertion sort " << insertionSort(createVector(numOfItems)) << "ms" << std::endl;
		//std::cout << "Time to sort " << numOfItems << " items with bucket sort 0." << bucketSort(createVector(numOfItems)) << "s";
	}

	
	getchar();
}
