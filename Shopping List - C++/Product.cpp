#pragma once // Allows to include libraries and files once

#include "Product.h" // Including header of Products to get access to its public methods


//-------------------------- Constructors --------------------------//
Product::Product() {

    this->ID = 0;
    this->name = "";
    this->price = 0.0;
    this->previous_product = NULL;
    this->next_product = NULL;
}

Product::Product(int ID, string name, float price){

    this->ID = ID;
    this->name = name;
    this->price = price;
    this->previous_product = NULL;
    this->next_product = NULL;
}
//-------------------------- End of Constructors --------------------------//


//-------------------------- Getters and Setters --------------------------//
void Product::set_ID(int ID) {
    
    this->ID = ID;
}

int Product::get_ID() {

    return this->ID;
}

void Product::set_name(string name) {

    this->name = name;
}

string Product::get_name() {

    return this->name;
}

void Product::set_price(float price) {

    this->price = price;
}

float Product::get_price() {

    return this->price;
}

void Product::set_previousProduct(Product* product) {

    this->previous_product = product;
}

Product* Product::get_previousProduct() {

    return this->previous_product;
}

void Product::set_nextProduct(Product* product) {

    this->next_product = product;
}

Product* Product::get_nextProduct() {

    return this->next_product;
}
//-------------------------- End of Getters and Setters --------------------------//


//-------------------------------- End of File --------------------------------//