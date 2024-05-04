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

void addNode() {
	Node* newNode = new Node();								//step 1: Membuat node baru
	cout << "\nEnter the roll number of the student : ";
	cin >> newNode->noMhs;									//Mengisi nilai pada field nomor mahasiswa dari node baru
	cout << "\nEnter the name of the student : ";
	cin >> newNode->name;									//Mengisi nilai pada field nama mahasiswa dari node baru
}

int main() {
}