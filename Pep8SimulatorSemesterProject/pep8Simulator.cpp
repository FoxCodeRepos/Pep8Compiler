#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int m[655346]; //memory array



struct i4_1_3 {

	unsigned int i3 : 3;

	unsigned int i1 : 1;

	unsigned int i4 : 4;

};

struct i5_3 {

	unsigned int i3 : 3;

	unsigned int i5 : 5;

};

struct i7_1 {

	unsigned int i1 : 1;

	unsigned int i7 : 7;

};

struct i4_4 {
	unsigned int secondHalf : 4;

	unsigned int firstHalf : 4;
};


union opcode {

	i4_1_3 i413;

	i5_3 i53;

	i7_1 i71;

	i4_4 i44;

	unsigned int full8 : 8;

};


opcode op; //opcode structure

struct split {
	unsigned int mem : 16;

	unsigned int opcode : 8;
};

union instruction {
	split i816;

	unsigned int wholeInstruction;
};

instruction i; //instruction structure



int main() {
	bool cont = true;
	int instruction;
	unsigned int r;
	while (cont = true) {
		cout << "Enter the 6 hexadecimal instruction: ";

		cin >> instruction;

		i.wholeInstruction = instruction;


		
		//m[i.i816.mem]


		if (op.full8 == 0) { //STOP
			cont = false;
		}

		if (op.i71.i7 == 3) { // Bitwise invert r
			r = m[i.i816.mem];
			~r;	//bitwise NOT

			cout << "r = " << r << endl;
		}

		if (op.i71.i7 = 14) { //Arithmetic shift left r
			r = m[i.i816.mem];
			r << 1;

			cout << "r = " << r << endl;
		}

		if (op.i71.i7 == 15) { //Arithmetic shift right r
			r = m[i.i816.mem];
			r >> 1;

			cout << "r = " << r << endl;
		}

		if (op.i71.i7 == 16) {//Rotate left r
			r = m[i.i816.mem];

			unsigned mask;
			mask = (1 << 1) - 1;
			unsigned int lastBit = r & mask;

			r << 1;

			r = r | lastBit;

			cout << "r = " << r << endl;
		}


		if (op.i71.i7 == 17) {//Rotate right r
			r = m[i.i816.mem];

			unsigned mask;
			mask = (1 << 1) - 7;
			unsigned int firstBit = r & mask;

			r >> 1;

			r = r | firstBit;

			cout << "r = " << r << endl;
		}

		if (op.i53.i5 == 6) { //DECI
			cout << "Enter a decimal integer: ";

			int decInput;

			cin >> decInput;

			m[i.i816.mem] = decInput;

			cout << "r = " << r << endl;
		}

		if (op.i53.i5 == 7) { //DECO

			cout << m[i.i816.mem];

			cout << "r = " << r << endl;
		}
		if (op.i53.i5 == 9) { // CHARI

			cout << "Enter a character: ";

			char input;

			cin >> input;

			m[i.i816.mem] = input;

			cout << "r = " << r << endl;
		}
		if(op.i53.i5 == 10){ // CHARO
			
			cout << m[i.i816.mem] << endl;

			cout << "r = " << r << endl;
		}
		if(op.i413.i4 == 7){ //ADD to r
			
			cout << "Input an integer to add to r: ";

			char addToR;

			cin >> addToR;

			m[i.i816.mem] += addToR;

			cout << "r = " << r << endl;
		}
		if(op.i413.i4 == 8){ //SUB from r
			
			cout << "Input an integer to subtract from r: ";

			char subFromR;

			cin >> subFromR;

			m[i.i816.mem] -= subFromR;

			cout << "r = " << r << endl;
		}
		if (op.i413.i4 == 9) { //Bitwise AND to r

			cout << "Input an integer to compare to r: ";
			
			char bitAnd;
			
			cin >> bitAnd;

			m[i.i816.mem] = m[i.i816.mem] & bitAnd;

			cout << "r = " << r << endl;
		}
		if(op.i413.i4 == 10){ //Bitwise OR to r
		
			cout << "Input an integer to compare to r: ";

			char bitOr;

			cin >> bitOr;

			m[i.i816.mem] = m[i.i816.mem] | bitOr;

			cout << "r = " << r << endl;
		}

		if(op.i413.i4 == 11){ //Load r from memory
			r = m[i.i816.mem];
			cout << "r = " << r << endl;
		}
		if (op.i413.i4 == 12) { //Load byte from memory
			r = m[i.i816.mem];
			cout << "byte = " << r << endl;//Need to figure out how to load a byte
		}
		if (op.i413.i4 == 13) { //Store r to memory
			m[i.i816.mem] = r;

			cout << "r = " << r << endl;
		}
		if (op.i413.i4 == 14) { //Store byte r to memory
			m[i.i816.mem] = op.i44.secondHalf;

			cout << "r = " << r << endl;
		}
	}
	return 0;
}
