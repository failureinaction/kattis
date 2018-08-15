//curse the darkness at kattis. 0.01s
#include <bits/stdc++.h>

using namespace std;

float euclid_dist(float x, float y){
	return sqrt(x*x + y*y);
}
int main(){
	int T;
	scanf("%d", &T);
	float X, xbook, Y, ybook;
	int n;
	while(T--){
		scanf("%f%f%d", &xbook, &ybook, &n);
		bool light = false;
		while(n--){
			scanf("%f%f", &X, &Y);
			if(euclid_dist(xbook - X, ybook - Y) <= 8) light = true;
		}
		if(light) printf("light a candle\n");
		else printf("curse the darkness\n");
	}
	return 0;
}
