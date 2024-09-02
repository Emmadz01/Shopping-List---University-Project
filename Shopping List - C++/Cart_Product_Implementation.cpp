#pragma once // Allows to include libraries and files once

#include "Cart_Product.h" // Including header of Cart Products to get access to its public methods


//-------------------------- Constructor --------------------------//
Cart_Product::Cart_Product(Product* product, int quantity) {

    this->product = product;
    this->quantity = quantity;
    this->previous_product = NULL;
    this->next_product = NULL;
}
//-------------------------- End of Constructor --------------------------//


//-------------------------- Getters and Setters --------------------------//
void Cart_Product::set_product(Product* product) {
    this->product = product;
}

Product* Cart_Product::get_product() {

    return this->product;
}

void Cart_Product::set_quantity(int quantity) {
    this->quantity = quantity;
}

int Cart_Product::get_quantity() {

    return this->quantity;
}

void Cart_Product::set_previousProduct(Cart_Product* product) {

    this->previous_product = product;
}

Cart_Product* Cart_Product::get_previousProduct() {

    return this->previous_product;
}

void Cart_Product::set_nextProduct(Cart_Product* product) {

    this->next_product = product;
}

Cart_Product* Cart_Product::get_nextProduct() {

    return this->next_product;
}

//-------------------------- End of Getters and Setters --------------------------//


//-------------------------------- End of File --------------------------------//