// Copyright (c) 2021 Jenoe Balote All rights reserved
//
// Created by Jenoe Balote
// Created on May 2021
// This program formats a proper mailing address for the user

#include <iostream>
#include <string>
#include <algorithm>

std::string AddressFormat(std::string name, std::string streetNumber,
                              std::string streetName, std::string city,
                              std::string province, std::string postalCode,
                              std::string apartmentNumber = "") {
    // This function formats the address
    std::string address;

    address = name + "\n";
    if (apartmentNumber.size() != 0) {
        address = address + apartmentNumber + "-";
    }
    address = address + streetNumber + " " + streetName + "\n"
        + city + " " + province + "  " + postalCode;

    return address;
}


main() {
    // This function gets the address informations
    std::string fullName;
    std::string apartmentQuestion;
    std::string apartmentNumber = "";
    std::string streetNumber;
    std::string streetName;
    std::string city;
    std::string province;
    std::string postalCode;
    std::string mAddress;

    // Input
    std::cout << "This program properly formats your mailing address."
        << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Enter your full name: ";
    getline(std::cin, fullName);
    std::cout << "Do you live in an apartment (yes/no)?: ";
    getline(std::cin, apartmentQuestion);
    if (apartmentQuestion == "yes") {
        std::cout << "Enter your apartment number: ";
        getline(std::cin, apartmentNumber);
    }
    std::cout << "Enter your street number: ";
    getline(std::cin, streetNumber);
    std::cout << "Enter your street name and type: ";
    getline(std::cin, streetName);
    std::cout << "Enter your city: ";
    getline(std::cin, city);
    std::cout << "Enter the abbreviation of your province: ";
    getline(std::cin, province);
    std::cout << "Enter your postal code: ";
    getline(std::cin, postalCode);

    // Call functions
    if (apartmentNumber != "") {
        mAddress = AddressFormat(fullName, streetNumber,
                                 streetName, city,
                                 province, postalCode,
                                 apartmentNumber);
    } else {
        mAddress = AddressFormat(fullName, streetNumber,
                                 streetName, city,
                                 province, postalCode);
    }


    // Output
    std::cout << "" << std::endl;
    std::cout << "Your mailing address is:" << std::endl;
    std::cout << "" << std::endl;
    std::transform(mAddress.begin(), mAddress.end(),
                   mAddress.begin(), ::toupper);
    std::cout << mAddress << std::endl;
    std::cout << "" << std::endl;
    std::cout << "Done." << std::endl;
}
