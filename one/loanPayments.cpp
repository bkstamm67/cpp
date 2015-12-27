/****************************
 * Author:  Brian Stamm
 * Date:  1.11.15
 * Description:  This program calculates the total loan payment
 * after asking the user for some basic information about the
 * loan.
 * **************************/

#include<iostream>
#include<iomanip>
#include<cmath>

int main(){
   
   double loanAmt, //     This is the variable for Loan Amount
	  monthRt, //     For the % Interest
	  nPay, //        Number of Payments
	  monthPay,//     Monthly payment
	  percent, //     Percent - it changes the monthly rate into a percent
	  totalPay, //    Total amount paid with the loan
	  intPay;//       Total amount paid in interest
   
   std::cout<<"This program is designed to be a loan payment calculator."<<std::endl;//Basic instructions
   std::cout<<"Please enter whole numbers to the following questions"<<std::endl;

   std::cout<<"What is the loan amount? ";
   std::cin>>loanAmt;
   std::cout<<"What is the monthly interest rate, as a whole number? ";
   std::cin>>monthRt;
   std::cout<<"What is the total number of payments? ";
   std::cin>>nPay;   
  
   percent = monthRt / 100;// Done to make writing the equation easier

   monthPay = (percent * pow((1 + percent), nPay )) / (pow((1 + percent), nPay) - 1) * loanAmt; // Monthly payment calucation

   totalPay = monthPay * nPay;

   intPay = totalPay - loanAmt;
   
   std::cout<<"Loan Amount: $"<<std::fixed << std::setprecision(2)<<loanAmt<<std::endl;//Results as follows, fixed & set precision to make sure in proper format
   std::cout<<"Monthly Interest Rate: "<<std::fixed << std::setprecision(0)<<monthRt<<"%"<<std::endl;//Formatted for a whole number
   std::cout<<"Number of Payments: "<<nPay<<std::endl;   //Formatted for a whole number
   std::cout<<"Monthly Payments: $"<<std::fixed <<std::setprecision(2)<<monthPay<<std::endl;//Each formatted for $ currency
   std::cout<<"Amount Paid Back: $"<<totalPay<<std::endl;
   std::cout<<"Interest Paid: $"<<intPay<<std::endl;
   
   return 0;
}
