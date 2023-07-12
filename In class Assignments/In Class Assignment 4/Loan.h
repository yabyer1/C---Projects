#pragma once
#ifndef LOAN_H
#define LOAN_H
class Loan
{
private:
    double payment = 0;
    double loan = 0;
    double annualInterestRate = 0;
    int years = 0;
public:
    Loan() { ; }
    Loan(double l, double a, int y) { loan = l; annualInterestRate = a; years = y; calcPayment(); }
    void calcPayment();
    double AmountPaidBack();
    //accessors
    double getPayment() { return payment; }
    double getLoan() { return loan; }
    double getAnnnualInterestRate() { return annualInterestRate; }
    double getYears() { return years; }
    //mutators
    void setLoan(double l) { loan = l; calcPayment(); }
    void setAnnualInterestRate(double l) { annualInterestRate = l; calcPayment(); }
    void setYears(int l) { years = l; calcPayment(); }

    void printData();


};
#endif

