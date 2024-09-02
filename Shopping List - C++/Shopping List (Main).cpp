#pragma once // Allows to include libraries and files once
#include "Product_List.h" // Including header file of Product List to get access to its public methods


Product_List product_list; // Declaring a variable of Product List type


//-------------------------- Printing Administrator Commands --------------------------//
void print_administratorCommands() {

	cout << "\n\tAdministrator Commands\n\n";
	cout << "\t1. Add Product\n";
	cout << "\t2. Remove Product\n";
	cout << "\t3. Display Recently Added Products\n";
	cout << "\t4. Browse Products\n";
	cout << "\t5. Exit Program";

	cout << "\n\tEnter Serial Number of the Option: ";
}

//-------------------------- End of Printing --------------------------//


//-------------------------- Method to get access as an Administrator --------------------------//
void administrator_control() {

	int administrator_choice, product_ID;
	string product_name, key;
	float product_price;
	bool run_loop = true;


	while (run_loop) { // While Loop - Iterates until user selects 'Exit Program'

		system("cls");
		print_administratorCommands();
		cin >> administrator_choice;

		switch (administrator_choice) { // Switch statement for selecting the case according to the entered number by the user
		case 1:
			cout << "\n\tEnter Product ID: ";
			cin >> product_ID;

			cin.ignore();

			cout << "\tEnter Product Name: ";
			getline(cin, product_name); 

			cout << "\tEnter Product Price: $";
			cin >> product_price;

			product_list.add_product(product_ID, product_name, product_price);

			break;
		case 2:
			cout << "\n\tEnter Product ID: ";
			cin >> product_ID;

			cin.ignore();
			product_list.remove_product(product_ID);

			break;
		case 3:
			product_list.display_recentlyAdded();
			break;
		case 4:
			product_list.browse_products();
			break;
		case 5:
			run_loop = false;
			system("cls");
			break;
		default:
			cout << "\n\tInvalid Input! Please Try Again!";
			cout << "\n\tPress Enter to continue ---> ";

			cin.ignore();
			getline(cin, key);
			break;
		}
		// End of Switch Statement
	}
	// End of While Loop
}
//-------------------------- End of Method --------------------------//


//-------------------------- Printing User Commands --------------------------//
void print_userCommands() {
	cout << "\n\t\tUser Commands\n\n";
	cout << "\t1. Browse Products and add them to your Shopping Cart\n";
	cout << "\t2. Browse products in your Shopping Cart\n";
	cout << "\t3. Checkout\n";
	cout << "\t4. Exit Program\n";
	cout << "\n\tEnter Serial Number of the Option: ";
}
//-------------------------- End of Printing --------------------------//


//-------------------------- Method to get access as User --------------------------//
void user_control() {

	Shopping_Cart user_cart;
	int user_choice;
	bool run_loop = true;
	string key;

	while (run_loop) { // While Loop - Iterates until user selects 'Exit Program'
		
		system("cls");
		print_userCommands();

		cin >> user_choice;

		switch (user_choice) { // Switch statement for selecting the case according to the entered number by the user

		case 1:
			user_cart = product_list.browse_products(user_cart);
			break;
		case 2:
			cin.ignore();
			user_cart.browse_products();
			break;
		case 3:
			user_cart.checkout();
			break;
		case 4:
			run_loop = false;
			system("cls");
			break;
		default:
			cout << "\n\tInvalid Input! Please Try Again!";
			cout << "\n\tPress Enter to continue ---> ";

			cin.ignore();
			getline(cin, key);
			break;
		}
		// End of Switch Statement
	}
	// End of While Loop
}
//-------------------------- End of Method --------------------------//


//-------------------------- Main Method --------------------------//
int main() {

	int choice = 0, password = 0;
	int const administrator_password = 7890;

	// choice will store the choice of the user
	// administrator_password will be compared with the password that the user enters if the Administrator is chosen, User access does not require password
	// password will store the user entered password which will be compared with the administrator_password. User will get access as an Administrator if correct password if entered

	bool run_loop = true; // If true the loop will iterate until it is false
	string key; // Variable to stop program temporarily until the user presses Enter


	while (run_loop) { // While Loop - Iterates until user selects 'Exit Program'

		cout << "\n\t\tWho Are You?\n\n";
		cout << "\t1. Administrator | Password: 7890\n";
		cout << "\t2. User\n";
		cout << "\t3. Exit Program\n";

		cout << "\n\tEnter Serial Number: ";
		cin >> choice;
		cin.ignore();

		
		switch (choice) { // Switch statement for selecting the case according to the entered number by the user

		case 1: // For Administrator

			cout << "\n\tEnter Password: ";
			cin >> password;

			if (password == administrator_password) { // If user entered the correct password

				system("cls"); // This will clear all of the text on the Console Window and make it blank
				administrator_control(); // Calls the corresponding method
			}
			else { // If user entered an incorrect password

				cout << "\n\tIncorrect Password | Press Enter to continue";

				cin.ignore();
				getline(cin, key);

				system("cls"); // This will clear all of the text on the Console Window and make it blank
			}
			break;

		case 2: // For User

			system("cls"); // This will clear all of the text on the Console Window and make it blank
			user_control(); // Calls the corresponding method
			break;

		case 3: // For Exiting the Program

			run_loop = false; // Stops the iteration of the While loop if false
			break;

		default: // When an Invalid Input is Entered

			cout << "\n\tInvalid Input! Please Try Again!";

			cout << "\n\tPress Enter to continue ---> ";
			
			cin.ignore(); // the getline will not automatically read the previous enter and make the program to continue
			getline(cin, key); // Will make the program to wait for user until Enter is pressed

			system("cls"); // This will clear all of the text on the Console Window and make it blank
			break;
		}
		// End of Switch Statement
	}
	// End of While Loop
	return 0;
}
//-------------------------- End of Main Method --------------------------//


//-------------------------------- End of File --------------------------------//