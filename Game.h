#pragma once.
#include <ctime>
#include <fstream>
#include <iostream>
#include "Bee.h"

using namespace std;

bee** new_bee(bee* Bee[], int& n, int col,int number, int num, int*& arr) {
	if (number == 1) {
		
		int m = 0;
		bee** be;
		n++;
		be = new bee * [n];
		for (int i = 0; i < n - 1; i++)
		{
			be[i] = Bee[i];
		}
		delete[] Bee;
		Bee = be;
		col -= 5;
		Bee[0]->col_bee = n;
		switch (col)
		{
		case 0:
			m = rand() % 5;
			if (m == 4) {
				Bee[n - 1] = new bee_trut[1];
				Bee[0]->col_trut += 1;
			}
			else
				Bee[n - 1] = new bee_ob[1];
			Bee[n - 1]->set_init_pos();
			break;
		case 1:	
			m = rand() % 5;
			if (m == 4) {
				Bee[n - 1] = new bee_trut[1];
				Bee[0]->col_trut += 1;
			}
			else
				Bee[n - 1] = new bee_work[1];
			Bee[n - 1]->set_init_pos();
			break;
		case 2:
			m = rand() % 5;
			if (m == 4) {
				Bee[n - 1] = new bee_trut[1];
				Bee[0]->col_trut += 1;
			}
			else {
				if (m == 3) {
					Bee[n - 1] = new bee_qwin[1];
					Bee[0]->col_qwin += 1;
				}
				else
					Bee[n - 1] = new bee_or[1];
			}
			Bee[n - 1]->set_init_pos();
			break;
		case 3:
			m = rand() % 5;
			if (m == 4) {
				Bee[n - 1] = new bee_trut[1];
				Bee[0]->col_trut += 1;
			}else
				Bee[n - 1] = new bee_med[1];
			Bee[n - 1]->set_init_pos();
			break;
		default:
			break;
		}
		for (int i = 0; i < n; i++) {
			if (Bee[i]->get() == 2)
				Bee[i]->posit = 0;
		}
		Bee[num]->posit = 0;
		return Bee;
	}
	if (number == 3) {
		//добыча мёда 1
//воск 2
//увеличить количество мест в улье 3
//убить трутня 5
		switch (col)
		{
		case 1:
			Bee[0]->col_med = Bee[0]->col_med + 50;
			Bee[num]->posit = 0;
			break;
		case 2:
			Bee[0]->col_vosk = Bee[0]->col_vosk + 80;
			Bee[num]->posit = 0;
			break;
		case 3:
			Bee[0]->col = Bee[0]->col + 1;
			Bee[num]->posit = 0;
			break;
		case 5:
			bee * *be;
			be = new bee * [n - 2];
			int j = 0, a, col = 0;
			int *ar;
			ar = new int[n - 2];
			for (int i = 0; i < n; i++)
			{
				a = Bee[i]->get();
				if (a == 2)
					col += 1;
				if (col == 2 && a == 2) {
					be[j] = Bee[i];
					ar[j] = arr[i];
					j++;
				}
				if (a != 3 && a != 2) {
					be[j] = Bee[i];
					ar[j] = arr[i];
					j++;
				}

			}
			delete[] arr;
			delete[] Bee;
			Bee = be;
			arr = ar;
			n -= 2;
			Bee[0]->col_bee = n;
			Bee[0]->col_trut -= 1;
			for (int i = 0; i < n; i++) {
				a = Bee[i]->get();
				if (a == 2)
					Bee[i]->posit = 0;
			}
			break;
		}
		
		return Bee;
	}
	if (number == 4) {
		//добыча мёда 1
//воск 2
//увеличить количество мест в улье 3
//убить трутня 5
		switch (col)
		{
		case 1:
			Bee[0]->col_med = Bee[0]->col_med + 50;
			Bee[num]->posit = 0;
			break;
		case 2:
			Bee[0]->col_vosk = Bee[0]->col_vosk + 30;
			Bee[num]->posit = 0;
			break;
		case 3:
			Bee[0]->col = Bee[0]->col + 1;
			Bee[num]->posit = 0;
			break;
		case 5:
			bee * *be;
			be = new bee * [n - 2];
			int* ar;
			ar = new int[n - 2];
			int j = 0, a, col = 0;
			for (int i = 0; i < n; i++)
			{
				a = Bee[i]->get();
				if (a == 2)
					col += 1;
				if (col == 2 && a == 2) {
					be[j] = Bee[i];
					ar[j] = arr[i];
					j++;
				}
				if (a != 4 && a != 2) {
					be[j] = Bee[i];
					ar[j] = arr[i];
					j++;
				}

			}

			delete[] arr;
			delete[] Bee;
			Bee = be;
			arr = ar;
			n -= 2;
			Bee[0]->col_bee = n;
			Bee[0]->col_trut -= 1;
			for (int i = 0; i < n; i++) {
				a = Bee[i]->get();
				if (a == 2)
					Bee[i]->posit = 0;
			}
			break;
		}

		return Bee;
	}
	if (number == 5) {
		//добыча мёда 1
//воск 2
//увеличить количество мест в улье 3
//убить трутня 5
		switch (col)
		{
		case 1:
			Bee[0]->col_med = Bee[0]->col_med + 20;
			Bee[num]->posit = 0;
			break;
		case 2:
			Bee[0]->col_vosk = Bee[0]->col_vosk + 30;
			Bee[num]->posit = 0;
			break;
		case 3:
			Bee[0]->col = Bee[0]->col + 1;
			Bee[num]->posit = 0;
			break;
		case 5:
			bee * *be;
			be = new bee * [n - 2];
			int* ar;
			ar = new int[n - 2];
			int j = 0, a, col = 0;
			for (int i = 0; i < n; i++)
			{
				a = Bee[i]->get();
				if (a == 2)
					col += 1;
				if (col == 2 && a == 2) {
					be[j] = Bee[i];
					ar[j] = arr[i];
					j++;
				}
				if (a != 5 && a != 2) {
					be[j] = Bee[i];
					ar[j] = arr[i];
					j++;
				}
				
			}

			delete[] arr;
			delete[] Bee;
			Bee = be;
			arr = ar;
			n -= 2;
			Bee[0]->col_bee = n;
			Bee[0]->col_trut -= 1;
			for (int i = 0; i < n; i++) {
				a = Bee[i]->get();
				if (a == 2)
					Bee[i]->posit = 0;
			}
			break;
		}

		return Bee;
	}
	if (number == 6) {
		//добыча мёда 1
//воск 2
//увеличить количество мест в улье 3
//убить трутня 5
		switch (col)
		{
		case 1:
			Bee[0]->col_med = Bee[0]->col_med + 100;
			Bee[num]->posit = 0;
			break;
		case 2:
			Bee[0]->col_vosk = Bee[0]->col_vosk + 30;
			Bee[num]->posit = 0;
			break;
		case 3:
			Bee[0]->col = Bee[0]->col + 1;
			Bee[num]->posit = 0;
			break;
		case 5:
			bee * *be;
			be = new bee * [n - 2];
			int j = 0, a, col = 0;
			int* ar;
			ar = new int[n - 2];
			for (int i = 0; i < n; i++)
			{
				a = Bee[i]->get();
				if (a == 2)
					col += 1;
				if (col == 2 && a == 2) {
					be[j] = Bee[i];
					ar[j] = arr[i];
					j++;
				}
				if (a != 6 && a != 2) {
					be[j] = Bee[i];
					ar[j] = arr[i];
					j++;
				}

			}

			delete[] arr;
			delete[] Bee;
			Bee = be;
			arr = ar;
			n -= 2;
			Bee[0]->col_bee = n;
			Bee[0]->col_trut -= 1;
			for (int i = 0; i < n; i++) {
				a = Bee[i]->get();
				if (a == 2)
					Bee[i]->posit = 0;
			}
			break;
		}

		return Bee;
	}
	else {
		return Bee;
	}
	
}

bee** prov_zad(bee* Bee[], int& n, clock_t t, int t1,int*& arr, int i) {

	if (Bee[i]->posit != 0 && i != 1 && Bee[i]->posit != 4 && t - t1 >= Bee[i]->Time[0] * 1000) {
		Bee = new_bee(Bee, n, Bee[i]->posit, Bee[i]->get(), i, arr);
	}
	return Bee;
}

bee** Input(bee* Bee[], int& n) {
	ifstream file;
	int col = 0, k;
	file.open("data.txt");
	file >> n;
	
	Bee = new bee * [n];
	for (int i = 0; i < n; i++) {
		file >> col;
		switch (col)
		{
		case 1:
			Bee[i] = new bee_qwin[1];
			break;
		case 2:
			Bee[i] = new bee_trut[1];
			break;
		case 3:
			Bee[i] = new bee_ob[1];
			break;
		case 4:
			Bee[i] = new bee_work[1];
			break;
		case 5:
			Bee[i] = new bee_or[1];
			break;
		case 6:
			Bee[i] = new bee_med[1];
			break;
		default:
			break;
		}
	}
	for (int i = 0; i < n; i++) {
		Bee[i]->set_init_pos();
		k = Bee[i]->get();
		if (k == 2)
			Bee[0]->col_trut += 1;
	}
	Bee[0]->col = n;
	Bee[0]->col_qwin = 1;
	file >> Bee[0]->col_med;
	file >> Bee[0]->col_vosk;
	
	file.close();
	return Bee;
}

void Ounput(bee* Bee[], int& n) {
	ofstream file;
	int col = 0, k;
	file.open("data.txt");
	file << n << endl;
	for (int i = 0; i < n; i++) {
		if (Bee[i] != NULL)
			file << Bee[i]->get() <<endl;
		else
			break;
	}
	file << Bee[0]->col_med << endl;
	file << Bee[0]->col_vosk<<endl;
	file.close();
}