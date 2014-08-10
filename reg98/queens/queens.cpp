#include <iostream>
#include <cmath>
using namespace std;


void permutate(int q[8], int index);

int main(){
	int queens[8] = {-1, -1, -1, -1, -1, -1, -1, -1 };

	int x, y;
	cin >> x >> y;
	while(cin.good()){
		queens[x-1] = y-1;
		cin>> x >> y;
	}

	permutate(queens, 0);
}

void permutate(int q[8], int index){
	if(index == 8){
		for(int i=0; i < 8; i++){
			cout << q[i]+1 << ' ';
		}
		cout << endl;
		return;
	}
	if(q[index] != -1){
		permutate(q, index+1);
		return;
	}

	for(int y=0; y < 8; y++){
		bool ok = true;
		for(int x=0; x < 8 && ok; x++){
			if(q[x] != -1){
				if (q[x] == y){
					ok = false;
				} else if (abs(x - index) == abs(y - q[x])){
					ok = false;
				}
			}
		}
		if (ok){
			int b[8];
			for (int i=0; i < 8; i++){
				b[i] = q[i];
			}
			b[index] = y;
			permutate(b, index+1);
		}
	}
}
