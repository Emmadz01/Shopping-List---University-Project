#pragma once // Allows to include libraries and files once

#include "Shopping_Cart.h" // Including header file of Shopping Cart to get access to its public methods
#include <io.h> // Including Library for key navigation
#include <conio.h> // Including Library for key navigation


//-------------------------- Constructor --------------------------//
Shopping_Cart::Shopping_Cart() {

	this->first_product = NULL;
	this->last_product = NULL;
}
//-------------------------- End of Constructor --------------------------//


//-------------------------- Getters and Setters --------------------------//
void Shopping_Cart::set_firstProduct(Cart_Product* product) {

	this->first_product = product;
}

Cart_Product* Shopping_Cart::get_firstProduct() {

	return this->first_product;
}

void Shopping_Cart::set_lastProduct(Cart_Product* product) {

	this->last_product = product;
}

Cart_Product* Shopping_Cart::get_lastProduct() {

	return this->last_product;
}
//-------------------------- End of Getters and Setters --------------------------//


//-------------------------- Method to Count Products --------------------------//
int Shopping_Cart::count_product() {

	Cart_Product* temp = first_product;
	int counter = 0;

	while (temp != NULL) {
		counter++;
		temp = temp->get_nextProduct();
	}

	return counter;
}
//-------------------------- End of Method --------------------------//


//-------------------------- Method to Add Products --------------------------//
void Shopping_Cart::add_product(Product* product, int quantity) {

	string key = "";

	if (product_exists(product)) {

		cout << "\n\tProduct already Added | Try changing quantity of this product";
	}
	else {
		Cart_Product* temp = new Cart_Product(product, quantity);

		if (list_empty()) {

			first_product = temp;
			last_product = temp;
		}
		else {

			last_product->set_nextProduct(temp);
			temp->set_previousProduct(last_product);
			last_product = temp;
		}

		cout << "\n\tProduct Added to the your Shopping Cart";
	}

	cout << "\n\n\tPress Enter to continue ---> ";

	getline(cin, key);
}
//-------------------------- End of Method --------------------------//


//-------------------------- Method to Remove Products --------------------------//
void Shopping_Cart::remove_product(Product* product) {

	Cart_Product* target = find_product(product);
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

			Cart_Product* temp_previous = target->get_previousProduct();
			Cart_Product* temp_next = target->get_nextProduct();

			temp_previous->set_nextProduct(temp_next);
			temp_next->set_previousProduct(temp_previous);

			target->set_previousProduct(NULL);
			target->set_nextProduct(NULL);
			delete target;
		}

		cout << "\n\tProduct Removed from your Shopping Cart";
	}

	cout << "\n\n\tPress Enter to continue ---> ";


	getline(cin, key);
}
//-------------------------- End of Method --------------------------//


//-------------------------- Method to check if the product exists in the list --------------------------//
bool Shopping_Cart::product_exists(Product* product) {

	Cart_Product* temp = first_product;

	while (temp != NULL) { 

		if (temp->get_product() == product) { return true; }

		temp = temp->get_nextProduct();
	}

	return false;
}
//-------------------------- End of Method --------------------------//


//-------------------------- Method to check if the list is empty or not --------------------------//
bool Shopping_Cart::list_empty() {

	if (first_product == NULL && last_product == NULL) { return true; }

	return false;
}
//-------------------------- End of Method --------------------------//


//-------------------------- Method to Find Product --------------------------//
Cart_Product* Shopping_Cart::find_product(Product* product) {

	Cart_Product* temp = first_product;

	while (temp != NULL) {

		if (product == temp->get_product()) {
			return temp;
		}

		temp = temp->get_nextProduct();
	}

	return NULL;
}
//-------------------------- End of Method --------------------------//


//-------------------------- Method to Browse Products from the list --------------------------//
void Shopping_Cart::browse_products() {

	if (list_empty()) { // If the List is Empty
		
		cout << "\n\tYour Shopping Cart is Empty. Try Adding products from the list";

		string key = "";

		cout << "\n\tPress Enter to continue ---> ";

		cin.ignore();
		getline(cin, key);

	}
	else { // If the List is not Empty

		Cart_Product* temp = first_product;
		bool run_loop = true;
		int counter = 1, product_count = count_product(), key, quantity = 0;
		string skip = "";

		system("cls");
		cout << "\n---------------------------------------------\n";
		cout << "\nProduct " << counter << endl << endl;
		cout << "\tProduct Name: " << temp->get_product()->get_name() << endl;
		cout << "\tProduct Price: $" << temp->get_product()->get_price() << endl;
		cout << "\tProduct Quantity: " << temp->get_quantity() << endl;
		cout << "\n---------------------------------------------\n";

		cout << "\n\tEnter 1 to remove product from your Shopping Cart\n";
		cout << "\tEnter 2 to change the quantity of this product\n";
		cout << "\nPress ESC to exit from Browsing Mode\n";
		cout << "\tUse Left and Right Arrow Keys to navigate\n\n---> ";

		while (run_loop) { // While Loop - Iterates until user selects 'Exit Program'
			if (_kbhit()) {

				key = _getch();

				if (key > 0 && key < 224) {

					switch (key) { // Switch statement for selecting the case accordingly

					case 27: // For Escape Key
						run_loop = false;
						break;
					case 49: // For number 1

						remove_product(temp->get_product());

						run_loop = false;

						if (!list_empty()) {
							browse_products();
						}
						break;
					case 50: // For number 2

						cout << "\n\tEnter quanity in numbers: ";
						cin >> quantity;

						temp->set_quantity(quantity);

						cout << "\n\tNew quantity is " << quantity << endl;

						cout << "\n\n\tPress Enter to continue ---> ";

						cin.ignore();
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
							cout << "\tProduct Name: " << temp->get_product()->get_name() << endl;
							cout << "\tProduct Price: $" << temp->get_product()->get_price() << endl;
							cout << "\tProduct Quantity: " << temp->get_quantity() << endl;
							cout << "\n---------------------------------------------\n";

							cout << "\n\tEnter 1 to remove product from your Shopping Cart\n";
							cout << "\tEnter 2 to change the quantity of this product\n";
							cout << "\nPress ESC to exit from Browsing Mode\n";
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
							cout << "\tProduct Name: " << temp->get_product()->get_name() << endl;
							cout << "\tProduct Price: $" << temp->get_product()->get_price() << endl;
							cout << "\tProduct Quantity: " << temp->get_quantity() << endl;
							cout << "\n---------------------------------------------\n";

							cout << "\n\tEnter 1 to remove product from your Shopping Cart\n";
							cout << "\tEnter 2 to change the quantity of this product\n";
							cout << "\nPress ESC to exit from Browsing Mode\n";
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


//-------------------------- Method to Checkout all the products from the Shopping Cart --------------------------//
void Shopping_Cart::checkout() {

	float total_price = 0;
	int counter = 1;
	string key = "";

	Cart_Product* temp = first_product;

	while (temp != NULL) {

		cout << "\nProduct " << counter << "\n\n\tName: " << temp->get_product()->get_name();
		cout<<"\n\tPrice: $" << temp->get_product()->get_price();
		cout << "\nQuantity: " << temp->get_quantity();

		total_price += temp->get_product()->get_price() * temp->get_quantity();

		temp = temp->get_nextProduct();

		counter++;

		cout << endl;
	}

	cout << "\n\n\tGrand Total: " << total_price;

	cout << "\n\n\tPress Enter to continue ---> ";

	cin.ignore();
	getline(cin, key);
}
//-------------------------- End of Method --------------------------//


//-------------------------------- End of File --------------------------------//