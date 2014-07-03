/**
 *  
 * mario.c
 * 
 *         The program prints out two half-out pyramids, one right triangle facing left and one right triangle facing right, separated by
 *         two spaces. Based on the input value N, which is spcified by the user from console, the pyramids will have the height N
 *         and width of each pyramid also N. 
 *
 * @input  valid credit card number in all digits typed in console
 * @output type of credit card as String to console
 * @class  EdX.org - CS50x 2014 - Pset 1 - Hacker Edition - Itsa Mario
 * @author Bryant Son
 * @since  07/02/2014 CST
 *
 * DISCLAIMER & LICENSE: This is a Hacker Edition of EdX's Havard CS50x course taken in 2014. Since Hacker Edition is an optional assignment
 * that does not give any point to the student of the class, you are not getting any advantage in terms of the grade by looking at this solution.
 * This solution is for the learning and a personal backup purposes only, and you should not use this code for a cheating or any other purpose
 * other than for the education purpose. Otherwise, you are free to read and to modify the code for your own program.
 *
 */

#include <stdio.h>
#include <cs50.h>

/**
 * Method Signature Interface 
 */
void printEmpty(int num);
void printHash(int num);

/**
 * Main method of the program
 */
int main(void) {
    int lengthPyramid = -1;
   
    // Asks for the user input a non-negative int value that is no greater than 23: 
    do {
        printf("%s","Height: ");
        lengthPyramid = GetInt();
    } while(lengthPyramid > 23 && lengthPyramid < 0);
    
    // Keep looping till the pyramids have been printed:
    for(int numHashCell = 1; numHashCell <= lengthPyramid; ++ numHashCell) {
        int numEmptyCell = lengthPyramid - numHashCell;
        
        // Print left empty cells:
        printEmpty(numEmptyCell);
        
        // Print left hash cells:
        printHash(numHashCell);
        
        // Print middle two spaces:
        printEmpty(2);
        
        // Print right hash cells:
        printHash(numHashCell);
        
        // Print right empty cells:
        printEmpty(numEmptyCell);
        
        // Print a blank line:
        printf("%s","\n");
    }
    
    return 0;
}

/** 
 * Implementation of methods 
 */
 
 /**
  * printEmpty
  *     Prints out the empty space by num amount
  *
  * @param num is the total space to be printed out
  */
 void printEmpty(int num) {
    for(int i=0; i < num; ++ i) {
        printf("%s"," ");
    }
 }
 
 /**
  * printHash
  *     Prints out the hash sign by num amount
  *
  * @param num is the total hash sign to be printed out
  */
 void printHash(int num) {
    for(int i=0; i < num; ++ i) {
        printf("%s","#");
    }
 }
