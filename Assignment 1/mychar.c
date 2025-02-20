/**
 * -------------------------------------
 * @file  mychar.c
 * file description
 * -------------------------------------
 * @author Joshua Mishra, 169063456, mish3456@mylaurier.ca
 *
 * @version 2025-01-12
 *
 * -------------------------------------
 */
#include "mychar.h"
/**
 * Determine the type of a char character.
 *
 * @param c - char type
 * @return - 0 if c is a digit
 1 if c is an arithmetic operator - 42 43 45 37 47
 2 if c is the left parenthsis (
 3 if c is the right parenthsis )
 4 if c is an English letter; - 65 to 90, and 97 122
 otherwise -1.
 */
int mytype(char c) {
	int type = 0;
	int ascii = (int) c;
	if (ascii >= 48 && ascii <= 57) {
		type = 0;
	} else if (ascii == 42 || ascii == 43 || ascii == 45 || ascii == 37
			|| ascii == 47) {
		type = 1;
	} else if (ascii == 40) {
		type = 2;
	} else if (ascii == 41) {
		type = 3;
	} else if ((ascii >= 65 && ascii <= 90) || (ascii >= 97 && ascii <= 122)) {
		type = 4;
	} else {
		type = -1;
	}
	return type;
}

/**
 * Flip the case of an English character.
 *
 * @param c - char type
 * @return -  c's upper/lower case letter if c is a lower/upper case English letter.
 */
char case_flip(char c) {
	int ascii = (int) c;
	if (ascii >= 65 && ascii <= 90) {
		ascii = ascii + 32;
	} else if (ascii >= 97 && ascii <= 122) {
		ascii = ascii - 32;
	}
	return (char) ascii;
}

/**
 * Convert digit character to the corresponding integer value.
 *
 * @param c - char type value
 * @return - its corresponding integer value if c is a digit character;
 *           otherwise -1.
 */
int digit_to_int(char c) {
	int num = -1;
	int ascii = (int) c;
	if (ascii >= 48 && ascii <= 57) {
		num = ascii - 48;
	}
	return num;
}
