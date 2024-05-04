#include <iostream>
#include <string>
using namespace std;

// Membuat struktur untuk menyatukan banyak data
struct Node
{
	int noMhs; //Nomor mahasiswa
	string name; // nama mahasiswa
	Node* next; // pointer ke node berikutnya
	Node* prev; // pointer ke node sebelumnya
};

Node* START = NULL; // pointer global yang menunjuk atau berada di awal / start linked list
int main() {
}