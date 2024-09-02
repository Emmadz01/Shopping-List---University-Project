#pragma once // Allows to include libraries and files once

#include <iostream>
#include <string>

using namespace std;


//-------------- Class --------------//

class Product { // Node of the linked list Product_List

private: // Private Attributes

	int ID; // For storing Product ID
	string name; // For storing Product Name
	float price; // For storing Product Price
	Product* previous_product; // Stores the previous Node (Product)
	Product* next_product; // Stores the next Node (Product)

public: // Public Methods

	Product(); // Constructor 1
	Product(int, string, float); // Constructor 2


	//-------------- Getters and Setters --------------//

	void set_ID(int); // For setting the Product ID
	int get_ID(); // For getting the Product ID

	void set_name(string); // For setting the Product Name
	string get_name(); // For getting the Product Name

	void set_price(float); // For setting the Product Price
	float get_price(); // For getting the Product Price

	void set_previousProduct(Product*); // For setting a Node (Product) as a Previous Node
	Product* get_previousProduct(); // For getting Previous Node (Product)
	
	void set_nextProduct(Product*); // For setting a Node (Product) as a Next Node
	Product* get_nextProduct(); // For getting Next Node (Product)


	//-------------- End of Getters and Setters --------------//
};
//-------------- End of Class --------------//


//-------------------------------- End of File --------------------------------//