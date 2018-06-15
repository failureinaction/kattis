#include <iostream>

int main(){
	int n, cold_days, curr_day;
	std::cin >> n;
	cold_days = 0;
	for(int i = 0; i < n; i++){
		std::cin >> curr_day;
		if(curr_day < 0){
			cold_days++;
		}
	}
	std::cout << cold_days << std::endl;
	return 0;
}