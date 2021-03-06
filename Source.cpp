#include <fstream>
#include <iostream>

using namespace std;

class Mass {
private: int row, *mas, *values, *index;
public:
	Mass();
	Mass(int);
	Mass(const Mass&);
	~Mass();
	void show() const;
	void fill() const;
	Mass operator+(const Mass&) const;
	Mass operator-(const Mass&) const;
	Mass getvalues();
	Mass getindex();
	Mass operator>> (int);
	Mass operator<<(int);

};

int main() {
	
	Mass a(6);
	cout << "Array 1" << endl;
	a.fill();
	cout << endl;

	cout << "Array 2" << endl;
	Mass b(6);
	b.fill();
	cout << endl;

	cout << "Summ" << endl;
	Mass Sum = a + b;
	Sum.show();
	cout << endl;

	cout << "Difference" << endl;
	Mass Dif = a - b;
	Dif.show();
	cout << endl;

	cout << "Indexes" << endl;
	a.getindex();
	cout << endl;

	cout << "Values" << endl;
	a.getvalues();
	cout << endl;

	cout << "Right shift(>>) to n (enter in main)" << endl;
	Mass sd = a >> 2;
	sd.show();
	cout << endl;

	cout << "Left shift(<<) to n (enter in main )" << endl;
	Mass sd2 = a << 1;
	sd2.show();
	cout << endl;

	cout << endl;
	system("pause");
	return 0;

}

Mass::Mass() {
	row = 10;

	values = new int[row];
	mas = new int[row];
	for (int i = 0; i < row; i++) {

		mas[i] = 0;
	}
}


Mass::Mass(int length) {
	row = length;
	mas = new int[row];
	for (int i = 0; i < row; i++) {

		mas[i] = 0;
	}
}

Mass::~Mass() {
	delete[] mas;
}

Mass::Mass(const Mass&a) {
	row = a.row;

	mas = new int[row];
	for (int i = 0; i < row; i++) {
		mas[i] = a.mas[i];
	}
}

void Mass::show() const {
	for (int i = 0; i < row; i++) {
		cout << mas[i] << "   ";
	}
}

void Mass::fill() const {
	int count;
	for (int i = 0; i < row; i++) {
		cin >> mas[i];
	}

}

Mass Mass::operator+(const Mass&a) const {
	Mass help(row);

	for (int i = 0; i < row; i++) {
		help.mas[i] = mas[i] + a.mas[i];
	}
	return help;
}

Mass Mass::operator-(const Mass&a) const {
	Mass help(row);

	for (int i = 0; i < row; i++) {
		help.mas[i] = mas[i] - a.mas[i];
	}
	return help;
}

Mass Mass::getindex() {
	int count=0;
	int j = 0;
	for (int i = 0; i < row; i++) {
		if (mas[i] != 0) {
			count++;
		}
	}
	index = new int[count];
	for (int i = 0; i < row; i++) {
		if (mas[i] != 0) {
				index[j] = i;
				cout << index[j] << "\t";
 				j++;
		}
	}
	return *this;
}

Mass Mass::getvalues() {
	int count = 0;
	int j = 0;
	for (int i = 0; i < row; i++) {
		if (mas[i] != 0) {
			count++;
		}
	}
	values = new int[count];
	for (int i = 0; i < row; i++) {
		if (mas[i] != 0) {
			values[j] = mas[i];
			cout << values[j] << "\t";
			j++;
		}
	}
	return *this;
}

Mass Mass::operator>> (int n) {
	Mass help(row);
	int j = row - n;

		for (int i = 1; i < row; i++) {
			help.mas[i] = mas[i-n];
		}
		for (int i = 0; i < n; i++) {
				help.mas[i] = mas[j];
				j++;
	}
	return help;
}


Mass Mass::operator << (int n) {
	Mass help(row);
	int j = 0;

	for (int i = 0; i < row; i++) {
		help.mas[i] = mas[i+n];
	}
	for (int i = row-n; i < row; i++) {
		help.mas[i] = mas[j];
		j++;
	}
	
	return help;
}
