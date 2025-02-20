#include <stdio.h>
/**
 * Count the number words of given simple string. A word starts with an English charactor end with a charactor of space, tab, comma, or period.  
 *
 * @param s - char pointer to a string
 * @return - return the number of words. 
 */
int str_words(char *s){
    int space = 0;
    int count = 0, length = 0;
    while(s[length] != '\0')
    {
        length++;
    }
    for (int i = 0; i < length; i++)
    {
        if (space == -1)
        {
            if((s[i] == ' ' || s[i] == '\t' || s[i] == ',' || s[i] == '.'))
            {
                
                space = 0;
            }
        }
        else if (space == 0)
        {
            if((s[i] != ' ' && s[i] != '\t' && s[i] != ',' && s[i] != '.'))
            {
                space = -1;
                count++;
            }
            else{
                
            }
        }
        
    } 
    if(space == -1)
    {
        count++;
    }
    return count;

}

/**
 * Change every upper case English letter to its lower case of string passed by s
 *
 * @param s - char pointer to a string
 * @return - return the number of actual flips.   
 */
int str_lower(char *s){
    int count = 0;
    int length = 0;
    while(s[length] != '\0')
    {
        length++;
    }
    for (int i = 0; i < length; i++)
    {
        
	    if (s[i] >= 'A' && s[i] <= 'Z') {
		    s[i] += 32;
            count++;
	    }
    }
    return count;
}

/**
 * Remove unnecessary space characters in a simple string passed by `s`
 *
 * @param s - char pointer to a string
 */
void str_trim(char *s){
    int space = -1, length = 0;
    int start = -1, end = 0;
    while(s[length] != '\0')
    {
        length++;
    }
    for (int i = 0; i < length; i++)
    {
        if(start == -1)
        {
            if(s[i] != ' ')
            {
                start = i;
                
            }
        }
        else if(s[i] != ' ')
        {
            end = 0;
        }
        end--;

    }
    end += length;
    
    for(int i = start; i <= end; i++)
    {
        s[i-start] = s[i];
    }
    for(int i = end-start + 1; i <= length; i ++)
    {
        s[i] = '\0';
    }
    return;

}