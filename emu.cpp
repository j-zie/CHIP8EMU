#include <iostream>
#include <vector>
using namespace std;

typedef unsigned char BYTE;
typedef unsigned short WORD;
const int pixels = 2048;
// We got 4k bytes. First 512 bytes is for the intrepreter,
// The programs are stored beginning at location 512 (0x200)
class CHIP8 {
    private:
    BYTE mem[4096];
    BYTE registers[16];
    BYTE graphics[64 * 32];
    std::vector<WORD> stack; 
    WORD opcode;
    WORD I, PC; 
    public:

    void initialize() {
	PC = 0x200; 
	stack.clear();
    }

    void another_clear();
    // TODO: this is an opcode, change the name.. 
    // 00E0
    void clear_screen() {
	for (int i = 0; i < pixels; i++) {
	    graphics[i] = 0;	
	}
	cout << "i'm here!";
    }


    void set_graphics() {
	// This method is jsut for testing	
	for (int i = 0; i < pixels; i++) {
	    graphics[i] = 1;
	}
	cout << "i'm here!";
    }

    // Let's just implement some op codes..

    void OP_1NNN (BYTE adr) {
	opcode = adr;	
    }

    // I need a timer, and a stack  
};


void CHIP8::another_clear() {
    cout << "hey this syntax works aswell" << endl;
}

int main() {

    CHIP8 new_chip;
    new_chip.clear_screen();
    new_chip.set_graphics();
    new_chip.another_clear();
}
