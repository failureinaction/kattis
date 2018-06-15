//Bus numbers
#include <iostream>
#include <algorithm>
using namespace std;



int main(){
	int N;
	cin >> N;
	int *buses = new int[N];
	for(int i = 0; i < N; i++){
		cin >> buses[i];
	}

	sort(buses, buses + N);
	/*
	for(int i = 0; i < N; i++){
		cout << buses[i] << " ";
	}
*/
	int counter = 0;
	while(counter < N){
		int start = counter;
		while(counter + 1 < N && buses[counter] + 1 == buses[counter + 1]) counter++;
		if(start == counter) cout << buses[counter];
		else if(start + 1 == counter) cout << buses[start] << " " << buses[counter];
		else{
			cout << buses[start] << "-" << buses[counter];
		}
		counter++;
		if(counter != N){
			cout << " ";
		}
	}
	cout << endl;

	return 0;
}
