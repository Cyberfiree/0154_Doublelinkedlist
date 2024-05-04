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

	// Node yang akan dihapus adalah node pertama
	if (current == START) {
		START = START->next;	
		if (START != NULL) {
			START->prev = NULL;
		}
	}

	else {
		//Node yang akan dihapus bukan node pertama
		previous->next = current->next; {	//If there's a successor, update its prev pointer
			current->next->prev = previous;
		}
	}

	// Membebaskan memori dari node yang ditandai sebagai current
	delete current;
	cout << "\x1b[32mRecord with roll number" << rollNo << "deleted\x1b[0m" << endl;
}

bool listEmpty() {
	return (START == NULL);
}

void traverse() {
	if (listEmpty())
		cout << "\nList is empty" << endl;
	else {
		cout << "\nRecords in ascending order of roll number are :" << endl;
		Node* currentNode = START;	//Step 1
		while (currentNode != NULL) {	//Step 2
			cout << currentNode->noMhs << " " << currentNode->name << endl;	//Step 3
			currentNode = currentNode->next;	// step 4
		}
	}
}

void revtraverse() {
	if (listEmpty())
		cout << "\nList is Empty" << endl;
	else {
		cout << "\nRecords in descending order of roll number are :" << endl;
		Node* currentNode = START;
		while (currentNode->next != NULL)
			currentNode = currentNode->next;

		while (currentNode != NULL) {
			cout << currentNode->noMhs << " " << currentNode->name << endl;
			currentNode = currentNode->prev;
		}
	}
}

void searchData() {
	if (listEmpty() == true) {
		cout << "\nList is empty" << endl;
	}
	Node* prev, * curr;
	prev = curr = NULL;
	cout << "\nEnter the roll number of the student whose record you want to search :";
	int num;
	cin >> num;
	if (search(num, &prev, &curr) == false)
		cout << "\nRecord not found" << endl;
	else {
		cout << "\nRecord found" << endl;
		cout << "\nRoll number :" << curr->noMhs << endl;
		cout << "\nNmae :" << curr->name << endl;
	}
}

int main() { // memulai program utama.
	while (true) {
		// Ini adalah loop yang akan terus berjalan sampai pengguna memilih untuk keluar.
		try {  // Ini adalah blok percobaan
			cout << "\nMenu" << endl;
			cout << "1. add arecord to the list" << endl;
			cout << "2. Delete a record from the list" << endl;
			cout << "3. View all records in the ascending order of roll numbers" << endl;
			cout << "4. View all records in the descending order of roll numbers" << endl;
			cout << "5. search for a record in the list" << endl;
			cout << "6. Exit" << endl;
			cout << "\nEnter your choice (1-6) :";
			char ch; // Variabel untuk menyimpan pilihan pengguna.
			cin >> ch; // Mengambil input dari pengguna.


			switch (ch) {
				// Memproses pilihan pengguna menggunakan switch case.
			case '1':
				// Jika pengguna memilih opsi 1, panggil fungsi untuk menambah rekaman.
				addNode();
				break;
			case'2':
				// Jika pengguna memilih opsi 2, panggil fungsi untuk menghapus rekaman.
				deleteNode();
				break;
			case '3':
				// Jika pengguna memilih opsi 3, panggil fungsi untuk melihat rekaman secara menaik.
				traverse();
				break;
			case '4':
				// Jika pengguna memilih opsi 4, panggil fungsi untuk melihat rekaman secara menurun.
				revtraverse();
				break;
			case '5':
				// Jika pengguna memilih opsi 5, panggil fungsi untuk mencari rekaman.
				searchData();
				break;
			case '6':
				// Jika pengguna memilih opsi 6, keluar dari program.
				return 0;
			default:
				// Jika pengguna memilih opsi yang tidak valid, tampilkan pesan kesalahan.
				cout << "\nInvalid option" << endl;
				break;
			}
		}
		catch (exception& e) {
			// Tangkap dan tangani pengecualian jika terjadi.
			cout << "Check for the values entered." << endl;
		}
	}
}