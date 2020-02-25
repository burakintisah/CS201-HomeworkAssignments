#include <iostream>
#include <chrono>

using namespace std;



//Binary Search

int binarySearch(int * A , int N, int value) {		
	int low = 0, high = N;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (A[mid] < value)
			low = mid + 1;
		else if (A[mid] > value)
			high = mid - 1;
		else
			return mid;
	}
	return -1;
}


// linear search

int linearSearch(int * A , int N, int value) {

	for (int i = 0; i < N; i++) {
		if (A[i] == value) {
			return i;
		}
	}
	return -1;

}



int main(){

	int again;
	again = 1 ;
	while (again != 0 ) {

		// declearing the arrays 
		int * A;
		int size;

		cout << "Enter your array size: " << endl;
		cin >> size;

		A = new int[size];

		// initiliazing the array

		for (int i = 0; i < size; i++) {
			A[i] = i + 1;
		}

		//Declare necessary variables
		std::chrono::time_point< std::chrono::system_clock > startTime;
		std::chrono::duration< double, milli > elapsedTime;

		//finding execution time for Binary Search

		//Store the starting time
		startTime = std::chrono::system_clock::now();
		//Code block
		binarySearch(A, size, 1);
		//Compute the number of seconds that passed since the starting time
		elapsedTime = std::chrono::system_clock::now() - startTime;
		cout << "Binary Search(close to beginning): " << endl;
		cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

		//Store the starting time
		startTime = std::chrono::system_clock::now();
		//Code block
		binarySearch(A, size, size / 2);
		//Compute the number of seconds that passed since the starting time
		elapsedTime = std::chrono::system_clock::now() - startTime;
		cout << "Binary Search (around the middle): " << endl;
		cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

		//Store the starting time
		startTime = std::chrono::system_clock::now();
		//Code block
		binarySearch(A, size, size);
		//Compute the number of seconds that passed since the starting time
		elapsedTime = std::chrono::system_clock::now() - startTime;
		cout << "Binary Search(close to end): " << endl;
		cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

		//Store the starting time
		startTime = std::chrono::system_clock::now();
		//Code block
		binarySearch(A, size, -1);
		//Compute the number of seconds that passed since the starting time
		elapsedTime = std::chrono::system_clock::now() - startTime;
		cout << "Binary Search(not exist): " << endl;
		cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;



		cout << "" << endl;



		// finding execution time for Linear Search

		//Store the starting time
		startTime = std::chrono::system_clock::now();
		//Code block
		linearSearch(A, size, 1);
		//Compute the number of seconds that passed since the starting time
		elapsedTime = std::chrono::system_clock::now() - startTime;
		cout << "Linear Search(close to beginning): " << endl;
		cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

		//Store the starting time
		startTime = std::chrono::system_clock::now();
		//Code block
		linearSearch(A, size, size / 2);
		//Compute the number of seconds that passed since the starting time
		elapsedTime = std::chrono::system_clock::now() - startTime;
		cout << "Linear Search(around the middle): " << endl;
		cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

		//Store the starting time
		startTime = std::chrono::system_clock::now();
		//Code block
		linearSearch(A, size, size);
		//Compute the number of seconds that passed since the starting time
		elapsedTime = std::chrono::system_clock::now() - startTime;
		cout << "Linear Search(close to end): " << endl;
		cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;

		//Store the starting time
		startTime = std::chrono::system_clock::now();
		//Code block
		linearSearch(A, size, -1);
		//Compute the number of seconds that passed since the starting time
		elapsedTime = std::chrono::system_clock::now() - startTime;
		cout << "Linear Search(not exist): " << endl;
		cout << "Execution took " << elapsedTime.count() << " milliseconds." << endl;
		delete[] A;

		cout << "" << endl;
		cout << "Again ? : " ;
		cin >> again;
		cout << "" << endl;

	}
	return 0;
}