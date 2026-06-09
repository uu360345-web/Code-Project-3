 
#include <iostream>
#include <string>
using namespace std;
 
string customerName;
int customerID;
string customerType;
string paymentMethod;
 
string items[8] = {
   "Rice 1 KG",
   "Sugar 1 KG",
   "Cooking Oil 1 Litre",
   "Milk Pack",
   "Tea Pack",
   "Flour 5 KG",
   "Eggs Dozen",
   "Detergent"
};
 
double prices[8] = {
   350, 180, 580, 220,
   450, 950, 320, 600
};
 
double totalBill = 0;
 
void registerCustomer()
{
   cout << "Enter Customer Name: ";
   cin.ignore();
   getline(cin, customerName);
 
   cout << "Enter Customer ID: ";
   cin >> customerID;
 
   int choice;
 
   cout << "1. Regular Customer\n";
   cout << "2. Member Customer\n";
   cout << "Enter Customer Type: ";
   cin >> choice;
 
   if(choice == 1)
       customerType = "Regular";
   else
       customerType = "Member";
 
   cout << "\n1. Cash\n";
   cout << "2. Card\n";
   cout << "Enter Payment Method: ";
   cin >> choice;
 
   if(choice == 1)
       paymentMethod = "Cash";
   else
       paymentMethod = "Card";
}
 
void displayGroceryList()
{
   cout << "\n========== GROCERY ITEMS ==========\n";
 
   for(int i=0; i<8; i++)
   {
       cout << i + 1 << ". "
            << items[i]
            << " - Rs. "
            << prices[i]
            << endl;
   }
}
 
void addItemsToCart()
{
   int itemNo, quantity;
   char choice;
 
   do
   {
       displayGroceryList();
 
       cout << "\nEnter Item Number: ";
       cin >> itemNo;
 
       cout << "Enter Quantity: ";
       cin >> quantity;
 
       totalBill =
       totalBill +
       (prices[itemNo - 1] * quantity);
 
       cout << "Add More Items? (Y/N): ";
       cin >> choice;
 
   } while(choice == 'Y' || choice == 'y');
}
 
double calculateGrossBill()
{
   return totalBill;
}
 
double calculateSalesTax()
{
   double tax = 0;
 
   tax = totalBill * 0.05;
 
   return tax;
}
 
double calculateMembershipDiscount()
{
   if(customerType == "Member")
       return totalBill * 0.07;
   else
       return 0;
}
 
double calculateBillAmountDiscount()
{
   if(totalBill >= 5000 && totalBill <= 10000)
       return totalBill * 0.05;
 
   else if(totalBill > 10000)
       return totalBill * 0.10;
 
   else
       return 0;
}
 
double calculateCardCharges(double amount)
{
   if(paymentMethod == "Card")
       return amount * 0.02;
   else
       return 0;
}
 
int calculateLoyaltyPoints(double amount)
{
   return amount / 100;
}
 
void displayFinalBill()
{
   double grossBill = calculateGrossBill();
 
   double tax = calculateSalesTax();
 
   double memberDiscount =
   calculateMembershipDiscount();
 
   double billDiscount =
   calculateBillAmountDiscount();
 
   double amount =
   grossBill +
   tax -
   memberDiscount -
   billDiscount;
 
   double cardCharges =
   calculateCardCharges(amount);
 
   double finalBill =
   amount + cardCharges;
 
   int currentPoints =
   calculateLoyaltyPoints(finalBill);
 
   int oldPoints;
 
   cout << "\nEnter Existing Loyalty Points: ";
   cin >> oldPoints;
 
   int totalPoints =
   currentPoints + oldPoints;
 
   cout << "Updated Loyalty Points: "
        << totalPoints << endl;
 
   char redeem;
 
   cout << "Redeem Loyalty Points? (Y/N): ";
   cin >> redeem;
 
   if(redeem == 'Y' || redeem == 'y')
   {
       finalBill = finalBill - totalPoints;
 
       if(finalBill < 0)
           finalBill = 0;
   }
 
   cout << "\n========== GROCERY BILL ==========\n";
 
   cout << "Customer Name: "
        << customerName << endl;
 
   cout << "Customer ID: "
        << customerID << endl;
 
   cout << "Customer Type: "
        << customerType << endl;
 
   cout << "Payment Method: "
        << paymentMethod << endl;
 
   cout << "\nGross Bill: Rs. "
        << grossBill << endl;
 
   cout << "Sales Tax: Rs. "
        << tax << endl;
 
   cout << "Membership Discount: Rs. "
        << memberDiscount << endl;
 
   cout << "Bill Discount: Rs. "
        << billDiscount << endl;
 
   cout << "Card Charges: Rs. "
        << cardCharges << endl;
 
   cout << "Final Bill: Rs. "
        << finalBill << endl;
 
   cout << "Loyalty Points: "
        << totalPoints << endl;
 
   cout << "==================================\n";
}
 
void displayCustomerDetails()
{
   cout << "\nCustomer Name: "
        << customerName << endl;
 
   cout << "Customer ID: "
        << customerID << endl;
 
   cout << "Customer Type: "
        << customerType << endl;
 
   cout << "Payment Method: "
        << paymentMethod << endl;
}
 
int main()
{
   registerCustomer();
 
   int choice;
 
   do
   {
       cout << "\n========== MAIN MENU ==========\n";
       cout << "1. View Grocery Items\n";
       cout << "2. Add Items To Cart\n";
       cout << "3. Calculate Bill\n";
       cout << "4. View Customer Details\n";
       cout << "5. Exit\n";
 
       cout << "Enter Choice: ";
       cin >> choice;
 
       switch(choice)
       {
           case 1:
               displayGroceryList();
               break;
 
           case 2:
               addItemsToCart();
               break;
 
           case 3:
               displayFinalBill();
               break;
 
           case 4:
               displayCustomerDetails();
               break;
 
           case 5:
               cout << "Program Closed Successfully.\n";
               break;
 
           default:
               cout << "Invalid Choice!\n";
       }
 
   } while(choice != 5);
 
   return 0;
}
 
