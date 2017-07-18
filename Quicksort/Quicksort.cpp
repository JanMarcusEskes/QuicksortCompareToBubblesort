// Quicksort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <chrono>
typedef std::chrono::high_resolution_clock Clock;

int getMitte(std::vector<int>& zahlen, int start, int ende){
	int i = start;
	int j = ende-1;
	int mitte = zahlen[ende];

	do
	{
		while (zahlen[i] <= mitte && i < ende)
			i++;

		while (zahlen[j] >= mitte && j > start)
		{
			j--;
		}
		if (i < j){
			int zwichenspeicher = zahlen[i];
			zahlen[i] = zahlen[j];
			zahlen[j] = zwichenspeicher;
		}
	} while (i < j);

	if (zahlen[i] > mitte){
		int zwichenspeicher = zahlen[i];
		zahlen[i] = zahlen[ende];
		zahlen[ende] = zwichenspeicher;
	}
	return i;
}


void quicksort(std::vector<int>& zahlen, int listart, int liende){

	if (listart < liende){
		int mitte = getMitte(zahlen, listart, liende);
		quicksort(zahlen, listart, mitte - 1);
		quicksort(zahlen, mitte + 1, liende);
	}
}

void bubblesort(std::vector<int>& zahlen){
	for (int i = 1; i < zahlen.size(); i++)
	{
		for (int j = 1; j < zahlen.size(); j++)
		{
			if (zahlen[j] < zahlen[j - 1]){
				int zwichenspeicher = zahlen[j-1];
				zahlen[j - 1] = zahlen[j];
				zahlen[j] = zwichenspeicher;
			}
		}
	}
}

std::vector<int> verwürfeln(int maxcapacity){
	
	std::vector<int> zahlen(0);
	for (int i = 0; i < maxcapacity; i+=3)
		zahlen.push_back(i);

	for (int i = 1; i < maxcapacity; i += 3)
		zahlen.push_back(i);

	for (int i = 2; i < maxcapacity; i += 3)
		zahlen.push_back(i);
	return zahlen;
}

int _tmain(int argc, _TCHAR* argv[])
{
	std::vector<int> zahlen = verwürfeln(10000);
	std::vector<int> zahlen2 = verwürfeln(10000);

	std::system("pause");

	auto t1 = Clock::now();
	quicksort(zahlen, 0, zahlen.size()-1);
	auto t2 = Clock::now();
	
	std::cout << "Quicksort  brauchte fuer 10000 Ints "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count()
		<< " Millisekunden" << std::endl;

	auto z1 = Clock::now();
	bubblesort(zahlen2);
	auto z2 = Clock::now();

	for (int i = 0; i < zahlen.size()-1; i++)
	{
		if (zahlen[i] != zahlen[i + 1] - 1)
			std::cout << "Es ist ein Fehler aufgetreten!";
	}
	  

	std::cout << "Bubblesort brauchte fuer 10000 Ints "
		<< std::chrono::duration_cast<std::chrono::milliseconds>(z2 - z1).count()
		<< " Millisekunden" << std::endl;
	std::system("pause");
	return 0;
}


