#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

float sconto(int n, float perc);


int main(int argc, char* argv[]) {
	if (argc != 3) {
		cerr << "Necessita di un file di testo in entrata e uno in uscita." << endl;
		exit(0);
	} else {
		fstream input, output;
		input.open(argv[1], ios::in);
		output.open(argv[2], ios::out);
		int in;
		float out;
		while (!input.eof()) {
			input >> in;
			if (in < 50) {
				out = sconto(in, 8);
			} else if ((in >= 50) && (in < 100)) {
				out = sconto(in, 5);
			} else if (in >= 100) {
				out = sconto(in, 2);				
			}
			output << out << " ";
		}
		input.close();
		output.close();
	}
	return(0);
}

float sconto(int n, float perc) {
	float res;
	res = n*(1.00+(perc/100));
	return res;
}
