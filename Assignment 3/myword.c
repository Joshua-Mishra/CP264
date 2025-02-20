#include <stdio.h>
#include <string.h>
#include "mystring.h"
#include "myword.h"
#define MAX_LINE_LEN 1000
#define MAX_WORDS 1000



/*
 * Load word data from file, and insert words a directory represented by char array.
 * 
 * @param  FILE *fp -   file pointer to an opened text file
 * @param *dictionary - char pointer to a char array where dictionary words are stored. 
 *                      It's up to your design on how to store words in the char array.
 * @return - the number of words added into the dictionary.   
 */
int create_dictionary(FILE *fp, char *dictionary){
    char line[MAX_LINE_LEN];
    char delimiters[] = " .,\n\t\r";
    char *word;
    int count = 0;
    dictionary[0] = '\0'; 
    while(fgets(line, MAX_LINE_LEN, fp) != NULL){
        str_lower(line);
        str_trim(line);
        word = strtok(line, delimiters);
        while(word != NULL){
            count++;
            strcat(dictionary, word);
            word = strtok(NULL, delimiters);

            
        }
    }
    return count;
}


/*
 * Determine if a given word is contained in the given dictionary.  
 * 
 * @param *dictionary -  char pointer to a char array of given dictionary.
 * @param *word  -  pointer to a given word.  
 *                     
 * @return - TRUE if the word is in the dictionary, FALSE otherwise.   
 */
BOOLEAN contain_word(char *dictionary, char *word){
    // your code

    if(!dictionary || !word){
        return FALSE;
    }
    char temp[20];
    snprintf(temp, 20, "%s", word);
    if (strstr(dictionary, temp) != NULL){
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

/*
 * Process text data from a file for word statistic information of line count, word count, keyword count, and frequency of keyword.   
 * 
 * @param *fp -  FILE pointer of input text data file. .
 * @param *words  -  WORD array for keywords and their frequencies.
 * @param *dictionary  -  stop-word/common-word dictionary.    
 *                     
 * @return - WORDSTATS value of processed word stats information.   
 */
WORDSTATS process_words(FILE *fp, WORD *words, char *dictionary){
    char line[MAX_LINE_LEN];
    char *word;
    int line_count = 0;
    int word_count = 0;
    int keyword_count = 0;
    int word_index = 0;
    while(fgets(line, MAX_LINE_LEN, fp) != NULL){
        line_count++;
        str_lower(line);
        str_trim(line);
        char delimiters[] = " .,\n\t\r";
        word = strtok(line, delimiters);
        while(word != NULL){
            word_count++;
            if(contain_word(dictionary, word) == FALSE){
                int j =0;
                while (j < keyword_count && strcmp(word, words[j].word) != 0) j++;
                if (j < keyword_count) 
                {
                    words[j].count++; 
                } 
                else
                {
                    strcpy(words[j].word, word); 
                    words[j].count = 1;
                    keyword_count++;
                }
            }
            word = strtok(NULL, delimiters);
        }
    }
    WORDSTATS stats;
    stats.line_count = line_count;
    stats.word_count = word_count;
    stats.keyword_count = keyword_count;
    return stats;
}

int Inttobinary(int a)
{
    if(a == 0)return 0;
    if(a == 1)return 1;
    else return (a%2 + 10 * Inttobinary(a/2));
}