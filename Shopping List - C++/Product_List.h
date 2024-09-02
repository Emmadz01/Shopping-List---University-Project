#pragma once // Allows to include libraries and files once

#include "Shopping_Cart.h" // Including header file of Shopping Cart to get access to its public methods

//-------------- Class --------------//

class Product_List { // Linked List for containing Products

private: // Private Attributes

	Product* first_product; // Head of the Linked List
	Product* last_product; // Tail of the Linked List

public: // Public Methods

	Product_List(); // Constructor


	//-------------- Getters and Setters --------------//

	void set_firstProduct(Product*); // For setting another Node (Product) as the head of the Linked List
	Product* get_firstProduct(); // For getting the Node (Product) which is set as the head of the linked list

	void set_lastProduct(Product*); // For setting another Node (Product) as the tail of the Linked List
	Product* get_lastProduct(); // For getting the Node (Product) which is set as the tail of the linked list

	int count_product(); // Counts the total number of products available in the Linked List

	void add_product(int, string, float); // For Adding a new product into the list with a unique Product ID
	void remove_product(int); // For Removing the existing product after entering it's Product ID to find it
	
	bool product_exists(int); // Returns Boolean, true if the product exists in the list and false when it doesn't exists in the list

	bool list_empty(); // Returns Boolean, true if the list is empty and false when the list is not empty

	Product* find_product(int); // Returns Product type pointer and returns the Node (Product) if it is in the list or returns NULL if it is not in the list

	void display_recentlyAdded(); // Displays Products available in the list. (Product which added to the list recently will be displayed first)

	void browse_products(); // Allows administrator to browse products using left and right arrow keys to navigate
	// Administrator can also add, remove, change price of the products

	Shopping_Cart browse_products(Shopping_Cart); // Allows User to browse products using left and right arrow keys to navigate
	// User can also add the products to their Shopping Cart after entering the quantity of each product they wish to add


	//-------------- End of Getters and Setters --------------//
};
//-------------- End of Class --------------//


//-------------------------------- End of File --------------------------------//