#pragma once // Allows to include libraries and files once

#include "Product_List.h" // Including header file of Product List to get access to its public methods
#include <io.h> // Including Library for key navigation
#include <conio.h> // Including Library for key navigation


//-------------------------- Constructor --------------------------//
Product_List::Product_List() {

	this->first_product = NULL;
	this->last_product = NULL;
}
//-------------------------- End of Constructor --------------------------//


//-------------------------- Getters and Setters --------------------------//
void Product_List::set_firstProduct(Product* product) {

	this->first_product = product;
}

Product* Product_List::get_firstProduct() {

	return this->first_product;
}

void Product_List::set_lastProduct(Product* product) {

	this->last_product = product;
}

Product* Product_List::get_lastProduct() {

	return this->last_product;
}
//-------------------------- End of Getters and Setters --------------------------//


//-------------------------- Method to Count Products --------------------------//
int Product_List::count_product() {

	Product* temp = first_product;
	int counter = 0;

	while (temp != NULL) {
		counter++;
		temp = temp->get_nextProduct();
	}

	return counter;
}
//-------------------------- End of Method --------------------------//


//-------------------------- Method to Add Products --------------------------//
void Product_List::add_product(int product_ID, string product_name, float product_price) {

	string key = "";
	
	if (product_exists(product_ID)) {

		cout << "\n\tProduct with ID " << product_ID << " already exists\n\tPlease enter a unique Product ID";
	}
	else {
		Product* temp = new Product(product_ID, product_name, product_price);

		if (list_empty()) {

			first_product = temp;
			last_product = temp;
		}
		else {

			last_product->set_nextProduct(temp);
			temp->set_previousProduct(last_product);
			last_product = temp;
		}

		cout << "\n\tProduct Added to the List";
	}

	cout << "\n\n\tPress Enter to continue ---> ";

	cin.ignore();
	getline(cin, key);
}
//-------------------------- End of Method --------------------------//


//-------------------------- Method to Remove Products --------------------------//
void Product_List::remove_product(int ID) {

	Product* target = find_product(ID);
	string key = "";

	if (target == NULL) {

		cout << "\n\tProduct Not Found";
	}
	else {

		if (target == first_product && target == last_product) {
			first_product = NULL;
			last_product = NULL;

			delete target;
		}
		else if (target == first_product) {

			first_product = first_product->get_nextProduct();
			target->set_nextProduct(NULL);
			first_product->set_previousProduct(NULL);

			delete target;
		}
		else if (target == last_product) {

			last_product = last_product->get_previousProduct();
			target->set_previousProduct(NULL);
			last_product->set_nextProduct(NULL);

			delete target;
		}
		else {

			Product* temp_previous = target->get_previousProduct();
			Product* temp_next = target->get_nextProduct();

			temp_previous->set_nextProduct(temp_next);
			temp_next->set_previousProduct(temp_previous);

			target->set_previousProduct(NULL);
			target->set_nextProduct(NULL);
			delete target;
		}

		cout << "\n\tProduct Removed from the list";
	}

	cout << "\n\n\tPress Enter to continue ---> ";

	getline(cin, key);
}
//-------------------------- End of Method --------------------------//


//-------------------------- Method to check if the product exists in the list --------------------------//
bool Product_List::product_exists(int ID) {

	Product* temp = first_product;

	while (temp != NULL) {

		if (ID == temp->get_ID()) { return true; }

		temp = temp->get_nextProduct();
	}

	return false;
}
//-------------------------- End of Method --------------------------//


//-------------------------- Method to check if the list is empty or not --------------------------//
bool Product_List::list_empty() {

	if (first_product == NULL && last_product == NULL) { return true; }

	return false;
}
//-------------------------- End of Method --------------------------//


//-------------------------- Method to Find Product --------------------------//
Product* Product_List::find_product(int ID) {

	Product* temp = first_product;

	while (temp != NULL) {

		if (ID == temp->get_ID()) {
			return temp;
		}

		temp = temp->get_nextProduct();
	}

	return NULL;
}
//-------------------------- End of Method --------------------------//


//-------------------------- Method to display Products that are recently added to the list --------------------------//
void Product_List::display_recentlyAdded() {

	Product* temp = last_product;
	int counter = 1;
	string key = "";

	if (list_empty()) {
		cout << "\n\tThere are no Products in the list | Try Adding Products";
	}

	while (temp != NULL && !(list_empty())) {

		cout << "\n\t---------------------------------------------\n";
		cout << "\n\tProduct " << counter << endl << endl;
		cout << "\tProduct ID: " << temp->get_ID() << endl;
		cout << "\tProduct Name: " << temp->get_name() << endl;
		cout << "\tProduct Price: $" << temp->get_price() << endl;

		counter++;

		temp = temp->get_previousProduct();
	}

	cout << "\n\t---------------------------------------------\n";

	cout << "\n\tPress Enter to continue ---> ";

	cin.ignore();
	getline(cin, key);
}
//-------------------------- End of Method --------------------------//


//-------------------------- Method to Browse Products from the list - For Administrator --------------------------//
void Product_List::browse_products() {

	system("cls");

	if (list_empty()) { // If the List is Empty

		cout << "\n\tThere are no Products in the list | Try Adding Products";

		string key = "";

		cout << "\n\tPress Enter to continue ---> ";

		cin.ignore();
		getline(cin, key);
	}
	else { // If the List is not Empty

		Product* temp = first_product;
		bool run_loop = true;
		int counter = 1, product_count = count_product(), user_choice = 0, key = 0, quantity = 0;
		string skip = "";
		float new_price = 0;

		cout << "\n---------------------------------------------\n";
		cout << "\nProduct " << counter << endl << endl;
		cout << "\tProduct ID: " << temp->get_ID() << endl;
		cout << "\tProduct Name: " << temp->get_name() << endl;
		cout << "\tProduct Price: $" << temp->get_price() << endl;
		cout << "\n---------------------------------------------\n";

		cout << "\n\tPress 1 to Remove Product\n";
		cout << "\tPress 2 to Change Price\n";
		cout << "\tPress ESC to exit from Browsing Mode\n";

		cout << "\tUse Left and Right Arrow Keys to navigate\n\n---> ";

		while (run_loop) { // While Loop - Iterates until user selects 'Exit Program'
			if (_kbhit()) {

				key = _getch();

				if ((key > 0 && key < 224)) {

					switch (key) { // Switch statement for selecting the case accordingly

					case 27: // For Escape Key
						run_loop = false;
						break;
					case 49: // For number 1

						remove_product(temp->get_ID());

						if (!list_empty()) {
							browse_products();
						}

						run_loop = false;

						break;
					case 50: // For number 2

						cout << "\n\tEnter new price for this product: ";
						cin >> new_price;
						cin.ignore();
						
						temp->set_price(new_price);

						cout << "\n\tNew Price: $" << new_price;

						cout << "\n\n\tPress Enter to continue ---> ";
						getline(cin, skip);

						run_loop = false;
						browse_products();

						break;
					case 75: // For LEFT Arrow

						counter--;

						if (counter < 1) {
							counter = 1;
						}

						if (temp->get_previousProduct() != NULL) {
							temp = temp->get_previousProduct();

							system("cls");

							cout << "\n---------------------------------------------\n";
							cout << "\nProduct " << counter << endl << endl;
							cout << "\tProduct ID: " << temp->get_ID() << endl;
							cout << "\tProduct Name: " << temp->get_name() << endl;
							cout << "\tProduct Price: $" << temp->get_price() << endl;
							cout << "\n---------------------------------------------\n";

							cout << "\n\tPress 1 to Remove Product\n";
							cout << "\tPress 2 to Change Price\n";
							cout << "\tPress ESC to exit from Browsing Mode\n";

							cout << "\tUse Left and Right Arrow Keys to navigate\n\n---> ";
						}
						break;
					case 77: // RIGHT Arrow

						counter++;

						if (counter > product_count) {
							counter = product_count;
						}

						if (temp->get_nextProduct() != NULL) {
							temp = temp->get_nextProduct();

							system("cls");

							cout << "\n---------------------------------------------\n";
							cout << "\nProduct " << counter << endl << endl;
							cout << "\tProduct ID: " << temp->get_ID() << endl;
							cout << "\tProduct Name: " << temp->get_name() << endl;
							cout << "\tProduct Price: $" << temp->get_price() << endl;
							cout << "\n---------------------------------------------\n";

							cout << "\n\tPress 1 to Remove Product\n";
							cout << "\tPress 2 to Change Price\n";
							cout << "\tPress ESC to exit from Browsing Mode\n";

							cout << "\tUse Left and Right Arrow Keys to navigate\n\n---> ";
						}
						break;
					}
					// End of Switch Statement
				}
			}
		}
		// End of While Loop
	}
}
//-------------------------- End of Method --------------------------//


//-------------------------- Method to Browse Products from the list - For User --------------------------//
Shopping_Cart Product_List::browse_products(Shopping_Cart user_cart) {

	system("cls");

	if (list_empty()) { // If the List is Empty

		cout << "\n\tProducts not available at the moment";

		string key = "";

		cout << "\n\tPress Enter to continue ---> ";

		cin.ignore();
		getline(cin, key);

		
	}
	else { // If the List is not Empty

		Product* temp = first_product;
		bool run_loop = true;
		int counter = 1, product_count = count_product(), user_choice = 0, key = 0, quantity = 0;

		cout << "\n---------------------------------------------\n";
		cout << "\nProduct " << counter << endl << endl;
		cout << "\tProduct ID: " << temp->get_ID() << endl;
		cout << "\tProduct Name: " << temp->get_name() << endl;
		cout << "\tProduct Price: $" << temp->get_price() << endl;
		cout << "\n---------------------------------------------\n";

		cout << "\n\tAdd this product to your Shopping Cart?\n";
		cout << "\tEnter 1 to add or, ESC number to exit Browsing Mode\n";

		cout << "\tUse Left and Right Arrow Keys to navigate\n\n---> ";

		while (run_loop) { // While Loop - Iterates until user selects 'Exit Program'
			if (_kbhit()) {

				key = _getch();

				if ((key > 0 && key < 224)) {
					
					switch (key) { // Switch statement for selecting the case accordingly

					case 27: // For Escape Key
						run_loop = false;
						break;
					case 49: // For number 1

						cout << "\tEnter product quantity in numbers: ";
						cin >> quantity;
						cin.ignore();

						user_cart.add_product(temp, quantity);

						run_loop = false;

						browse_products(user_cart);

						break;
					case 75: // For LEFT Arrow

						counter--;

						if (counter < 1) {
							counter = 1;
						}

						if (temp->get_previousProduct() != NULL) {
							temp = temp->get_previousProduct();

							system("cls");

							cout << "\n---------------------------------------------\n";
							cout << "\nProduct " << counter << endl << endl;
							cout << "\tProduct Name: " << temp->get_name() << endl;
							cout << "\tProduct Price: $" << temp->get_price() << endl;
							cout << "\n---------------------------------------------\n";

							cout << "\n\tAdd this product to your Shopping Cart?\n";
							cout << "\tEnter 1 to add or, ESC to exit from Browsing Mode\n";

							cout << "\tUse Left and Right Arrow Keys to navigate\n\n---> ";
						}
						break;
					case 77: // RIGHT Arrow

						counter++;

						if (counter > product_count) {
							counter = product_count;
						}

						if (temp->get_nextProduct() != NULL) {
							temp = temp->get_nextProduct();

							system("cls");

							cout << "\n---------------------------------------------\n";
							cout << "\nProduct " << counter << endl << endl;
							cout << "\tProduct Name: " << temp->get_name() << endl;
							cout << "\tProduct Price: $" << temp->get_price() << endl;
							cout << "\n---------------------------------------------\n";

							cout << "\n\tAdd this product to your Shopping Cart?\n";
							cout << "\tEnter 1 to add or, ESC to exit from Browsing Mode\n";

							cout << "\tUse Left and Right Arrow Keys to navigate\n\n---> ";
						}
						break;
					}
					// End of Switch Statement
				}
			}
		}
		// End of While Loop
	}

	return user_cart;
}
//-------------------------- End of Method --------------------------//


//-------------------------------- End of File --------------------------------//