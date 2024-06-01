#include <iostream>

using namespace std;
void insert_item(char*** arr, int x, int y, int z, int shelf, int pos, char item[]);
void display_item(char*** arr, int x, int y, int z, int shelf);
void remove_item(char*** arr, int x, int y, int z, int shelf, int pos);
void remove_allitem(char*** arr, int x, int y, int z);
void total_item(char*** arr, int x, int y, int z, int shelf);
void total_allitem(char*** arr, int x, int y, int z);
void find_item(char*** arr, int x, int y, int z, char item[]);
void update_item(char*** arr, int x, int y, int z, int shelf, int pos, char item[]);
void empty_shelf(char*** arr, int x, int y, int z, int shelf);
void full_shelf(char*** arr, int x, int y, int z, int shelf);
bool compareArrays(char a[], char b[]);



int main() {
	int k, p;


	cout << "                DEPARTMENTAL STORE MANAGEMENT SYSTEM               " << endl;

	cout << "Enter the number of shelves : ";
	cin >> k;
	cout << "Enter the number of position in each shelves : ";
	cin >> p;
	int choice;
	char item[100];
	int shelfno, position;
	//column size
	int c = 50;

	//Dynamic memory allocation 
	char*** shelves;

	shelves = new char** [k];
	for (int i = 0; i < k; i++) {
		shelves[i] = new char* [p];
		for (int j = 0; j < p; j++) {
			shelves[i][j] = new char[c];


		}
	}
	//initialization of array to 0 which means initially the shelves and positions are empty
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < p; j++) {
			for (int k = 0; k < c; k++) {
				shelves[i][j][k] = 0;
			}
		}

	}





	do {
		cout << endl;

		cout
			<< "             ********** Menu **********                                    " << endl;
		cout << endl;
		cout << "        Press 1 for Inserting an item." << endl
			<< "        Press 2 for Displaying all items." << endl
			<< "        Press 3 for Remove an item." << endl
			<< "        Press 4 for Remove all the items " << endl
			<< "        Press 5 for Return total no of items in a given shelf." << endl
			<< "        Press 6 for Return total no of items in all the shelves." << endl
			<< "        Press 7 to find an item." << endl
			<< "        Press 8 for updating an item." << endl
			<< "        Press 9 to check if shelf is empty." << endl
			<< "        Press 10 to check if shelf is full." << endl
			<< "        Press 0 to Quit:  " << endl;
		cout << endl;

		cout << "NOW ENTER YOUR CHOICE: ";
		cin >> choice;

		cout << endl;
		if (choice > 10 || choice < 0) {
			cout << "YOU ENTERED AN INCORRECT CHOICE" << endl;
			cout << endl;

		}

		else {
			if (choice == 1)
			{
				cout << "Enter shelf no. between 0 to " << k - 1 << " : ";
				cin >> shelfno;
				if (shelfno >= k) {
					cout << "Shelf not found" << endl;
				}
				else {
					cout << "Enter position number between 0 to " << p - 1 << " : ";
					cin >> position;
					cout << endl;

					if (position >= p) {
						cout << "Position not found" << endl;

					}
					else {
						cin.ignore();
						cout << "Enter item name : ";
						cin.getline(item, 100);


						int flag = 0;

						for (int j = 0; j < p; j++) {

							if (shelves[shelfno][j][0] == 0) {
								flag++;

							}


						}

						if (flag == 0) {
							cout << "There is no empty position left on this shelf" << endl;
							flag = 0;

						}

						else {

							insert_item(shelves, k, p, c, shelfno, position, item);
						}
					}
				}
			}
			else if (choice == 2) {

				cout << "Enter shelf no. between 0 to " << k - 1 << " to display items : ";

				cin >> shelfno;
				if (shelfno >= k) {
					cout << "Shelf not found" << endl;
				}
				else {

					display_item(shelves, k, p, c, shelfno);

				}
			}
			else if (choice == 3) {

				cout << "To REMOVE AN ITEM" << endl;
				cout << "Enter shelf no. between 0 to " << k - 1 << " : ";

				cin >> shelfno;
				if (shelfno >= k) {
					cout << "Shelf not found" << endl;
				}
				else {
					cout << "Enter position number between 0 to " << p - 1 << " : ";

					cin >> position;
					if (position >= p) {
						cout << "Position not found" << endl;

					}
					else {



						remove_item(shelves, k, p, c, shelfno, position);

					}
				}


			}

			else if (choice == 4) {

				remove_allitem(shelves, k, p, c);




			}

			else if (choice == 5) {
				cout << "Enter shlef number between 0 to " << k - 1 << " to find the total number of item in the shelf : ";
				cin >> shelfno;
				if (shelfno >= k) {
					cout << "Shelf not found" << endl;
				}
				else {
					total_item(shelves, k, p, c, shelfno);
				}

			}
			else if (choice == 6) {
				total_allitem(shelves, k, p, c);


			}




			else if (choice == 7) {


				cin.ignore();
				cout << "Enter item name to find ";
				cin.getline(item, 100);
				find_item(shelves, k, p, c, item);





			}


			else if (choice == 8) {
				cout << "TO UPDATE AN ITEM" << endl;
				cout << "Enter shelf no. between 0 to " << k - 1 << " : ";

				cin >> shelfno;
				if (shelfno >= k) {
					cout << "Shelf not found" << endl;
				}
				else {

					cout << "Enter position number between 0 to " << p - 1 << " : ";

					cin >> position;
					if (position >= p) {
						cout << "Position not found" << endl;

					}
					else {
						cin.ignore();
						cout << "\nEnter item to update with: ";
						cin.getline(item, 100);


						update_item(shelves, k, p, c, shelfno, position, item);
					}
				}
			}

			else if (choice == 9) {
				cout << "TO CHECK IF SHELF IS EMPTY" << endl;
				cout << "Enter shelf no. between 0 to " << k - 1 << " : ";

				cin >> shelfno;
				if (shelfno >= k) {
					cout << "Shelf not found" << endl;
				}
				else {
					empty_shelf(shelves, k, p, c, shelfno);
				}

			}
			else if (choice == 10) {

				cout << "TO CHECK IF SHELF IS Full" << endl;
				cout << "Enter shelf no. between 0 to " << k - 1 << " : ";

				cin >> shelfno;
				if (shelfno >= k) {
					cout << "Shelf not found" << endl;
				}
				else {

					full_shelf(shelves, k, p, c, shelfno);
				}


			}






			else if (choice == 0) {


				cout << "Thank you" << endl;
			}




		}


	} while (choice != 0);





	for (int i = 0; i < k; i++) {
		for (int j = 0; j < p; j++) {
			delete[] shelves[i][j];
		}
		delete[] shelves[i];
	}
	delete[] shelves;
	shelves = NULL;



	return 0;
}

void insert_item(char*** arr, int x, int y, int z, int shelf, int pos, char item[]) {




	int insert = 0;
	if (arr[shelf][pos][0] == 0) {
		for (int i = 0; i < z; i++) {

			arr[shelf][pos][i] = item[i];
			if (item[i] == '/0')
				break;

		}
		cout << "Item inserted successfully" << endl;


	}


	else if (arr[shelf][pos][0] != 0) {
		for (int i = pos; arr[shelf][i][0] != 0; i++) {
			pos++;

		}

		if (arr[shelf][pos][0] == 0) {
			for (int j = 0; j < z; j++) {

				arr[shelf][pos][j] = item[j];
				if (item[j] == '/0')
					break;
				insert = 1;

			}
		}



	}

	if (insert == 1) {
		cout << "Item inserted successfully " << endl;
	}




}








void display_item(char*** arr, int x, int y, int z, int shelf) {





	for (int j = 0; j < y; j++) {
		cout << "\n Items present on shelf " << shelf << " and position " << j << " : ";

		cout << arr[shelf][j] << " ";

		cout << endl;
	}



}
void remove_item(char*** arr, int x, int y, int z, int shelf, int pos) {


	if (arr[shelf][pos][0] != 0) {
		for (int k = 0; k < z; k++) {
			arr[shelf][pos][k] = 0;
		}

		cout << " \nITEM HAS BEEN REMOVED SUCCESSFULLY" << endl;


	}
	else {
		cout << "\nThere is no item present at this shelf " << endl;
	}





}
void remove_allitem(char*** arr, int x, int y, int z) {

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			for (int k = 0; k < z; k++) {
				arr[i][j][k] = 0;
			}
		}
	}
	cout << "\nALL ITEMS HAVE BEEN REMOVED SUCCESSFULLY" << endl;






}

void total_item(char*** arr, int x, int y, int z, int shelf) {



	int count = 0;
	for (int j = 0; j < y; j++) {

		if (arr[shelf][j][0] != 0) {

			count++;



		}
	}

	cout << "\n" << count << " items are present in this shelf" << endl;


}
void total_allitem(char*** arr, int x, int y, int z) {
	int count = 0;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {

			if (arr[i][j][0] != 0) {

				count++;



			}
		}
	}
	cout << "\n" << count << " items are present in the shelves" << endl;

}
void find_item(char*** arr, int x, int y, int z, char item[]) {

	int flag = 0;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			if (compareArrays(arr[i][j], item)) {
				cout << "\nItem found at shelf no: " << i << " and postion no " << j << " ." << endl;

				flag = 1;
			}
		}
		
	}
	if (flag != 1) {
		cout << "Item not found" << endl;
	}
	


}
void update_item(char*** arr, int x, int y, int z, int shelf, int pos, char item[]) {


	for (int k = 0; k < z; k++) {
		arr[shelf][pos][k] = item[k];
	}

	cout << "\nITEM UPDATED SUCCESSFULLY" << endl;




}
void empty_shelf(char*** arr, int x, int y, int z, int shelf) {

	bool flag = 0;
	for (int j = 0; j < y; j++) {
		for (int k = 0; k < z; k++) {
			if (arr[shelf][j][k] != 0) {
				flag = 1;

			}

		}
	}


	if (flag == 1) {
		cout << "\nShelf is not empty" << endl;

	}
	else {
		cout << "\nShelf is empty" << endl;
	}

}
void full_shelf(char*** arr, int x, int y, int z, int shelf) {


	int flag = 0;

	for (int j = 0; j < y; j++) {

		if (arr[shelf][j][0] == 0) {
			flag++;

		}


	}

	if (flag != 0) {
		cout << "\nShelf is not full" << endl;
		flag = 0;

	}

	else {
		cout << "\nShelf is full" << endl;


	}







}
bool compareArrays(char a[], char b[]) {
	int alen = 0;
	while (a[alen]) ++alen;
	int blen = 0;
	while (b[blen]) ++blen;

	int n = ++alen;
	int m = ++blen;

	if (n != m)
		return false;

	for (int i = 0; i < n; i++) {
		if (a[i] != b[i]) 
			return false;
	}

	return true;
}

