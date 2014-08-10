#include <iostream>
using namespace std;

void getCode(char * c_str){
	cin.get(c_str, 33);
	// kill \n
	cin.get();
}

int main(){
	char upShifts[33];
	char downShifts[33];
	getCode(upShifts);
	getCode(downShifts);

	cout << upShifts << endl << downShifts << endl;
	char message[81];
	char decoded[17];
	cin.get(message, 81, '\n');
	// eat '\n'
	cin.get();
	bool notDone = true;
	while(notDone){
		int i=0;
		int group = 0;
		bool shift = true;
		while(message[i]){
			for(int x=0; x<5; x++){
				group = group << 1;
				group += message[i] - '0';
				i++;
			}
			if (group == 31){
				shift = false;
			} else if (group == 27){
				shift = true;
			}else{
				//cout << group << ' ' << upShifts[group] << ' ' << downShifts[group] << ' ' << shift << endl;
				if(shift){
					cout << upShifts[group];
				}else{
					cout << downShifts[group];
				}
			}
			group = 0;
		}
		shift = true;
		cout << endl;
		notDone = cin.good();
		cin.get(message, 81, '\n');
		// eat \n
		cin.get();
	}
}

