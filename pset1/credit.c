/**
 * credit.c
 * 
 *      Bad Credit: The program determines the type of credit card, which is either American Express, Master Card, or Visa, based
 *                  on the credit card number provided by the user. By convention, American Express is a 15 digts length card with
 *                  prefix starting either 34 or 37, Master Card is a 16 digits card with prefix ranging from 51 - 55, and Visa
 *                  is a 13 digits or 16 digits length card with prefix starting 4. Based on the credit card type, the program outputs
 *                  AMEX for an American Express card, MASTERCARD for a Master Card, and VISA for a Visa card to the console. If nothing
 *                  applies, the program outputs the INVALID to the console. Also, if the credit card verification through checksum also fails,
 *                  the program also outputs INVALID to the console. If the input value contains anything other than numbers,
 *                  the program keeps asking for a new input.
 *
 * @input  valid credit card number in all digits typed in console
 * @output type of credit card as String to console
 * @class  CS50x 2014
 * @author Bryant Son
 * @since  06/30/2014 CST
 *
 */
 
#include <stdio.h>
#include <cs50.h>

/** 
 * Signature Interface for Bad Credit Application
 */
char * getCardType(int digitLength, int prefixCard);
int getSumDigits(int num);
int getLastDigit(int num);

/** 
 * Main function for the program. 
 */
int main(void) {
    // Stores the credit card number as read from input:
    long long numCreditCard = 0;
    
    do {
        // Reads the number as typed from the user through console:
        printf("%s","Number: ");
        numCreditCard = GetLongLong();
    }
    while(numCreditCard ==  LLONG_MAX);
    
    // Stores the position of the digit as going through the loop:
    int counterDigit = 0;
    
    // Keep track of the sum of the 2 * digits that occur in every even position:
    int totalChecksumValues = 0;
    
    // Keep track of the sum of the digits that occur in every odd position:
    int totalNonChecksumValues = 0;
    
    // Keep track of the multiplier in base 10:
    long long multiplier10Value = 1;
    
    // Copy of the original credit card number to operate on:
    long long remainNumCreditCard = numCreditCard;
    
    // Loop from right to left till all digits have been counted:
    while(remainNumCreditCard != 0) {
        if(counterDigit % 2 == 0) {
            // When the current digit position is first to last:
            totalNonChecksumValues += (remainNumCreditCard % 10);
        }
        else {
            // When the current digit position is second to last:
            totalChecksumValues += getSumDigits(2 * (remainNumCreditCard % 10));
        }
        
        // Move on to the next left digit:
        ++ counterDigit;
        
        // Increment the multiplier in base 10:
        multiplier10Value *= 10;
        
        remainNumCreditCard /= 10;
    }
    
    // Combines two summed up values as the credit card check sum test:
    int sumTotalCreditCard = totalChecksumValues + totalNonChecksumValues;
    
    // If the last digit of sum is not zero, print out INVALID and exit:
    if(getLastDigit(sumTotalCreditCard) != 0) {
        printf("%s\n","INVALID");
        return 0;
    }
    
   // Calculates the first two digits of the credit card:
   int prefixCard = numCreditCard / (multiplier10Value / 100);
     
    // Prints out the appropriate message:
    printf("%s\n", getCardType(counterDigit, prefixCard));
    return 0;
}

/** 
 * getCardType
 *
 * @param  digitLength is the length of the credit card, prefixCard is the first two digits of the credit card
 * @return appropriate message in string that tells what type of credit card it is. If invalid, prints out INVALID.
 */
char * getCardType(int digitLength, int prefixCard) {
    // Gets the first digit of the card:
    int firstPrefix = prefixCard / 10;
  
    // VISA: first digit starts with 4 AND the credit card length is either 13 or 16:
    if(firstPrefix == 4 && (13 == digitLength ||  digitLength == 16)) {
        return "VISA";
    }
    // MASTER CARD: first two digits start with 51 - 55 AND the credit card length is 16:
    else if (digitLength == 16 && (51 <= prefixCard && prefixCard <= 55)) {
        return "MASTERCARD";
    }
    // AMERICAN EXPRESS: first two digits start with either 34 or 37 AND the credit card lengt his 15:
    else if (digitLength == 15 && (prefixCard == 34 || prefixCard == 37)) {
        return "AMEX";
    }
    // Nothing fits in the rule:
    else {
        return "INVALID";
    }
}

/**
 * getLastDigit
 * 
 * @param  num 
 * @return the right most of the number value through the argument
 */
int getLastDigit(int num) {
    return num % 10;
}

/**
 * getSumDigits
 *
 * @param   num
 * @return  returns the combined sum of all occured digits in number value through the argument
 */
int getSumDigits(int num) {
    if(num < 10) {
        return num;
    }
    int sum = 0;
    
    while(num != 0) {
        sum += (num % 10);
        num /= 10;
    }
    
    return sum;
}
