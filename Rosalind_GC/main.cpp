// Problem taken from rosalind.info/problems/gc

/*	Given: At most 10 DNA strings in FASTA format (of length at most 1 kbp each).
	Return: The ID of the string having the highest GC-content, followed by the GC-content of that string.
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

pair<string, string> * get_fastaset(ifstream & input, unsigned int & num) {
	// Takes in open file, reads FASTA data to a pair<string, string>
	// .first is sequence name, .second is sequence itself

	string temp;
	unsigned int pos = 0;
	static pair<string, string> output[10];

	while (getline(input, temp)) {
		// Keeps reading file until end

		if (temp[0] == '>') {
			if (!(output[pos].second.empty())) {
				pos++;
			}
			output[pos].first = temp;
		}
		else {
			output[pos].second.append(temp);
		}
	}
	num = ++pos;
	return output;
}

float gc_percent(string input) {
	// Compares # of GC nucleotides in string to total size to return %GC

	unsigned int gc_num = 0;
	for (unsigned int i = 0; i < input.size(); i++) {
		if ((input[i] == 'G') || (input[i] == 'C')) {
			gc_num++;
		}
	}
	return (float(gc_num) / float(input.size()));
}

int main() {
	ifstream input("dataset.txt");

	if (input.is_open()) {
		unsigned int seq_size;
		pair<string, string> * sequences = get_fastaset(input, seq_size);
		input.close();

		int gc[10];
		for (unsigned int i = 0; i < seq_size; i++) {
			gc[i] = gc_percent(sequences[i].second);
		}

		unsigned int j = 0;
		float k = 0.0;

		for (unsigned int i = 0; i < seq_size; i++) {
			if (gc[i] > k) {
				k = gc[i];
				j = i;
			}
		}

		cout << sequences[j].first << "\n" << k << endl;

	}
	else {
		cout << "nope." << endl;
		return 1;
	}

	return 0;
}