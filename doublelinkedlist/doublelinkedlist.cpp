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

	// Memasukkan node baru ke dalam linked list
	if (START == NULL || newNode->noMhs <= START->noMhs) { //Langkah 2: Memasukkan node baru

		if (START != NULL && newNode->noMhs == START->noMhs) {
			cout << "\033[31mDuplicate roll numbers not allowed\033[0m" << endl;
			return;
		}
		// Jika linked list kosong, node baru menjadi START
		newNode->next = START;								//Langkah 3: Menjadikan node baru menunjuk ke node pertama			
		if (START != NULL) {
			START->prev = newNode;							//Langkah 4: Menjadikan node pertama menunjuk ke node baru
		}
		newNode->prev = NULL;								//Langkah 5: Menjadikan node baru menunjuk ke NULL
		START = newNode;									//Langkah 6: Menjadikan node baru sebagai node pertama
	}
	else {
		//Memasukkan node baru di tengah atau di akhir linked list
		Node* current = START;								//step 1.a : Mulai dari node pertama
		Node* previous = NULL;								//step 1.b : Node sebelumnya NULL pada awalnya

		while (current != NULL && current->noMhs < newNode->noMhs) { // step 1.c : Penelusuran
			previous = current;								//step 1.d : Pindahkan node sebelumnya ke node saat ini
			current = current->next;						//step 1.e : Pindahkan node saat ini ke node berikutnya
		}
		newNode->next = current;							//step 4 : Menjadikan field next dari node baru menunjuk ke node saat ini
		newNode->prev = previous;							//step 5 : Menjadikan field prev dari node baru menunjuk ke node sebelumnya

		if (current != NULL) {
			current->prev = newNode;						//step 6 : Menjadikan field prev dari node saat ini menunjuk ke node baru
		}

		if (previous != NULL) {
			previous->next = newNode;						//step 7 : Menjadikan field next dari node sebelumnya menunjuk ke node baru
		}
		else {
			//Jika node sebelumnya masih NULL, artinya newNode sekarang adalah node pertama
			START = newNode;
		}
	}
}

bool search(int rollNo, Node** previous, Node** current) {
	*previous = NULL;
	*current = START;
	while (*current != NULL && (*current)->noMhs != rollNo) {
		*previous = *current;
		*current = (*current)->next;
	}
	return (*current != NULL);
}

void deleteNode() {
	Node* previous, * current;
	int rollNo;

	cout << "\nEnter the roll number of the student whose record is to be deleted :";
	cin >> rollNo;	//step 3: get the roll number to be deleted

	if (START == NULL) {
		cout << "List is empty" << endl;
		return;
	}

	current = START;	// Step 1: mulai dari node baru
	previous = NULL;

	// Mencari node yang akan dihapus
	while (current != NULL && current->noMhs != rollNo) {
		previous = current;
		current = current->next;
	}

	if (current == NULL) {
		cout << "\033[31the record with roll number" << rollNo << "not found\033[0m" << endl;
		return;
	}
}

int main() {
}