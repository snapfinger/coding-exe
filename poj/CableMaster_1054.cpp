#include <iostream>
using namespace std;

const int MAX_N = 10010;
int n, k;
double lines[MAX_N];


int check(double x){
	int count = 0;
	for(int i = 0; i < n; i++){
		count += (int)(lines[i] / x);
	}

	return count >= k;
}

int main(){
	cin >> n >> k;
	for(int i = 0; i < n; i++){
		cin >> lines[i];
	}

	double l = 0,r = 1e5,mid,eps = 1e-8;
    while (l + eps < r){
        mid = (l + r)/2;
        if (check(mid)) l = mid;
        else r = mid;
    }
	printf("%.2f\n", (int)(r * 100) / 100.0);
	return 0;

}