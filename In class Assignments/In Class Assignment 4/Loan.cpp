#include "Loan.h"
#include <math.h>
#include <iomanip>
#include <iostream>

void Loan::calcPayment()
{
    double term = pow((1 + (annualInterestRate / 100 / 12)), (years * 12));
    payment = (loan * (annualInterestRate / 100 / 12) * term) / (term - 1);
}
double Loan::AmountPaidBack()
{
    return payment;
}
void Loan::printData()
{
    std::cout << "Loan Amount:\t$" << std::fixed << std::setprecision(2) << loan << std::endl;
    std::cout << "Monthy Interest Rate: " << static_cast<int> (annualInterestRate / 12) << "%" << std::endl;
    std::cout << "Number of Payments: " << years * 12 << std::endl;
    std::cout << "Monthly Payment: $" << AmountPaidBack() << std::endl;
    std::cout << "Amount paid back: $" << AmountPaidBack() * 12 * years << std::endl;
    std::cout << "Interest paid: $" << AmountPaidBack() * 12 * years - loan << std::endl;
}


