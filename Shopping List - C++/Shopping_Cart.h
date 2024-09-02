#pragma once // Allows to include libraries and files once

#include "Cart_Product.h" // Including header file of Cart Products to get access to its public methods

//-------------- Class --------------//

class Shopping_Cart {

private: // Private Methods

	Cart_Product* first_product; // Head of the Linked List
	Cart_Product* last_product; // Tail of the Linked List

public: // Public Methods

	Shopping_Cart(); // Constructor


	//-------------- Getters and Setters --------------//

	void set_firstProduct(Cart_Product*); // For setting another Node (Cart Product) as the head of the Linked List
	Cart_Product* get_firstProduct(); // For getting the Node (Cart Product) which is set as the head of the linked list

	void set_lastProduct(Cart_Product*); // For setting another Node (Cart Product) as the tail of the Linked List
	Cart_Product* get_lastProduct(); // For getting the Node (Cart Product) which is set as the tail of the linked list

	int count_product(); // Counts the total number of cart products available in the Linked List

	void add_product(Product*, int); // For Adding a new cart product into the list
	void remove_product(Product*); // For Removing the existing cart product

	bool product_exists(Product*); // Returns Boolean, true if the cart product exists in the list and false when it doesn't exists in the list

	bool list_empty(); // Returns Boolean, true if the list is empty and false when the list is not empty

	Cart_Product* find_product(Product*); // Returns Cart_Product type pointer and returns the Node (Cart Product) if it is in the list or returns NULL if it is not in the list

	void browse_products(); // Allows User to browse cart products using left and right arrow keys to navigate
	// User can also remove the products from their Shopping Cart or change the quantity of the products

	void checkout(); // Allows User to checkout which will calculate the total price that user have to pay


	//-------------- End of Getters and Setters --------------//
};
//-------------- End of Class --------------//


//-------------------------------- End of File --------------------------------//