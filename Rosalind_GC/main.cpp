// Problem taken from rosalind.info/problems/gc

/*	Given: At most 10 DNA strings in FASTA format (of length at most 1 kbp each).
	Return: The ID of the string having the highest GC-content, followed by the GC-content of that string.
*/

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

pair<string, string> get_fastaset(const ifstream & input) {

}

int main() {
	ifstream input("dataset.txt");

	if (input.is_open()) {

		pair<string, string> sequences[10];
		unsigned int sequence_pos = 0;
		string temp_holder;

		while (getline(input, temp_holder)) {
			if (temp_holder[0] != '>') {
				// if it doesn't start with >, then its not a name and we need to append it to the current sequence data
				sequences[sequence_pos].second.append(temp_holder);
			}
			else {
				// if it is a name after some data, then we need to make it the name of the next position and shift the position up
				if (!(sequences[sequence_pos].second.empty())) {
					sequence_pos++;
				}
				sequences[sequence_pos].first = temp_holder.substr(1, temp_holder.size() - 1);
			}
		}	
		input.close();
	}
	else {
		cout << "nope." << endl;
		return 1;
	}

	return 0;
}