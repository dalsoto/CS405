// Exceptions.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

// Creating the custom exception
class custom_exception : public std::exception {
public:
    virtual const char* what() const throw() {
        return "My Custom Exception";
    }
} customException;

bool do_even_more_custom_application_logic()
{
    // Throwing a standard exception
    throw std::exception("Standard Exception Thrown"); // Makes do_custom_application_logic() fail - catching this exception

    std::cout << "Running Even More Custom Application Logic." << std::endl;

    return true;
}
void do_custom_application_logic()
{
    // TODO: Wrap the call to do_even_more_custom_application_logic()
    //  with an exception handler that catches std::exception, displays
    //  a message and the exception.what(), then continues processing
    std::cout << "Running Custom Application Logic." << std::endl;

    try { //Try to call do_even_more_custom_application_logic
        if (do_even_more_custom_application_logic()) //Exception is thrown is it will fail
        {
            std::cout << "Even More Custom Application Logic Succeeded." << std::endl;
        }
    }
    catch (const std::exception& e) { //Always catch the standard exception
        std::cerr << "Application Logic Failed - " << e.what() << std::endl; //Output exception
    }

    //Throw the custom exception
    throw customException;

    std::cout << "Leaving Custom Application Logic." << std::endl;

}

float divide(float num, float den)
{
    // TODO: Throw an exception to deal with divide by zero errors using
    //  a standard C++ defined exception
    if (den == 0) {
        throw std::invalid_argument("A Number Can Not Be Divided By 0");
    }
    else {
        return (num / den);
    }
}

void do_division() noexcept
{
    //  TODO: create an exception handler to capture ONLY the exception thrown
    //  by divide.

    float numerator = 10.0f;
    float denominator = 0;

    try { //Dividing numerator and denominator
        auto result = divide(numerator, denominator);
        std::cout << "divide(" << numerator << ", " << denominator << ") = " << result << std::endl;
    }
    catch (const std::exception& e) { //Catch the standard exception thrown if division fails.  This will fail cause denom is 0
        std::cerr << "Division Failed - " << e.what() << std::endl; //Output exception from divide
    }
}

int main()
{
    std::cout << "Exceptions Tests!" << std::endl;

    // TODO: Create exception handlers that catch (in this order):
    //  your custom exception
    //  std::exception
    //  uncaught exception 
    //  that wraps the whole main function, and displays a message to the console.
    try {
        do_division();
        do_custom_application_logic();
    }
    catch (custom_exception& e) { //Handleer for custom exception
        std::cerr << "Custom Exception - " << e.what() << std::endl;
    }
    catch (std::exception& e) { //Handler for standard exceptions
        std::cerr << "Standard Exception - " << e.what() << std::endl;
    }
    catch (...) { //Handler for uncaught exception
        std::cerr << "Uncaught Exception" << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu