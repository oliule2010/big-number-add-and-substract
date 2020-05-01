/*
github: big number 

Add and substract big numbers using vectors.
*/
#include <iostream>
#include <vector>
using namespace std;
void print(const vector<int> &input) {
	for (int value : input) {
		cout << value;
	}
	cout << "\n";
}
vector<int> add_vector(vector<int> a, vector<int> b) {
	vector<int> output(a.size(), 0);
	int extra = 0;
	for (int i = a.size()-1; i >= 0; i--) {
		if (a[i] + b[i] + extra < 10) {
			output[i] = a[i] + b[i] + extra;
			extra = 0;
		}
		else {
			output[i] = a[i] + b[i] + extra - 10;
			extra = 1;
		}
	}
	if (extra == 1) {
		output.insert(output.begin(), extra);
	}
	return output;
}
vector<int> subtract(vector<int> a, vector<int> b) {
	vector<int> output(a.size(), 0);
	for (int i = a.size()-1; i >= 0; i--) {
		if (a[i] - b[i] >= 0) {
			output[i] = a[i] - b[i];
		}
		else {
			output[i] = (a[i] + 10) - b[i];
			a[i - 1] -= 1;
		}
		
	}
	return output;
}
int main()
{
	print(add_vector({ 1, 1, 1, 1, 1 }, { 1, 1, 1, 1, 1 }));
	print(add_vector({ 6, 6, 6, 6, 6 }, { 5, 5, 5, 5, 5 }));
	print(subtract({ 4, 2 }, { 3, 6 }));
}