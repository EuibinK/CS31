/* Author: Euibin Kim
 * Course: CS 31: Introduction to Computer Science 1
 * Date  : 5/1/2020
 * 
 * royalty.cpp
 *    Program that outputs total royalties earned based on user inputs.
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
  
  // take user input for unitsSent
  cout << "Units sent: "; 
  int unitsSent;
  cin >> unitsSent;
  cin.ignore(10000, '\n');

  // if user inputs negative value for unitsSent, print error message and terminate
  if(unitsSent < 0) {
    cout << "---" << endl << "The number of units sent must be nonnegative." << endl;
    return 1;
  }
  

  // take user input for title
  cout << "Title: ";
  string title;
  getline(cin, title);

  // if user inputs empty string for title, print error message and terminate
  if(title == "") {
    cout << "---" << endl << "You must enter a title." << endl;
    return 1;
  }


  // take user input for base price
  cout << "Base price: ";
  double basePrice;
  cin >> basePrice;
  cin.ignore(10000, '\n');

  // if user inputs negative value for basePrice, print error message and terminate
  if(basePrice < 0) {
    cout << "---" << endl << "The base price must be nonnegative." << endl;
    return 1;
  }


  // take user input to figure out whether it's premium or not
  cout << "Premium item? (y/n): ";
  string isPremium;
  getline(cin, isPremium);

  // if user input is neither y nor n, print error message and terminate
  if(isPremium != "y" && isPremium != "n") {
    cout << "---" << endl << "You must enter y or n." << endl;
    return 1;
  }


  // set constants for calculation
  const double TIER1 = 400;
  const double TIER2 = TIER1 + 800;

  const double RATE1 = 0.09;
  const double RATE2_BASE = 0.13;
  const double RATE2_PREMIUM = 0.16;
  const double RATE3 = 0.14;

  double totalFactor = 0;

  if(unitsSent <= TIER1)
    totalFactor = unitsSent * RATE1;
  else {
    totalFactor = TIER1 * RATE1;
    double rate2 = RATE2_BASE;

    if(isPremium == "y")
      rate2 = RATE2_PREMIUM;

    if(unitsSent <= TIER2) 
      totalFactor += (unitsSent - TIER1) * rate2;
    else {
      totalFactor += (TIER2 - TIER1) * rate2;
      totalFactor += (unitsSent - TIER2) * RATE3;
    }
  }

  double totalRoyalty = totalFactor * basePrice;
  cout.setf(ios::fixed);
  cout.precision(2);
  
  cout << "---" << endl;
  cout << title << " earned $" << totalRoyalty << " in royalties." << endl;

  return 0;
}
