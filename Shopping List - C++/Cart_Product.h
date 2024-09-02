#pragma once // Allows to include libraries and files once

#include "Product.h" // Including header file of Product to get access to its public methods

//-------------- Class --------------//
class Cart_Product { // Node of the linked list Shopping Cart

private: // Private Attributes
	
	Product* product; // Product type variable
	int quantity; // Stores the quantity of the product
	Cart_Product* previous_product; // Stores the previous Node (Cart Product)
	Cart_Product* next_product; // Stores the next Node (Cart Product)

public: // Public Methods

	Cart_Product(Product*, int); // Constructor


	//-------------- Getters and Setters --------------//

	void set_product(Product*); // For setting Product
	Product* get_product(); // For getting Product

	void set_quantity(int); // For setting quantity
	int get_quantity(); // For getting quantity

	void set_previousProduct(Cart_Product*); // For setting a Node (Cart Product) as a Previous Node
	Cart_Product* get_previousProduct(); // For getting Previous Node (Cart Product)

	void set_nextProduct(Cart_Product*); // For setting a Node (Cart Product) as a Next Node
	Cart_Product* get_nextProduct(); // For getting Next Node (Cart Product)


	//-------------- End of Getters and Setters --------------//
};
//-------------- End of Class --------------//


//-------------------------------- End of File --------------------------------//