#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string key[])
{
    // check if number of arugments submitted is exactly 2 - program name and key
    if (argc != 2)
    {
        printf("Error. Usage: ./substitution key\n");
        return 1;
    }

    // check if length of key is exactly 26
    int length = strlen(key[1]);
    if (length != 26)
    {
        printf("Error. Key must be 26 alphabetic characters only\n");
        return 1;
    }

    // check if key is entirely composed of alphabetical characters
    for (int i = 0; i < length; i++)
    {
        if (isalpha(key[1][i]))
        {

        }
        else
        {
            printf("Error. Key contains a non-alphabetic character\n");
            return 1;
        }
    }

    //check that each letter is used exactly once
    char alphabet[26];
    int k = 0;
    //build array alphabet with all 26 lowercase alphabetical characters
    for (int i = (int) 'a'; i <= 'z'; i++)
    {
        alphabet[k] = i;
        k++;
    }

    //change characters in alphabet array to null characters if the character exists in the key
    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            char inp = tolower(key[1][i]);
            if (alphabet[j] == inp)
            {
                alphabet[j] = '\0';
            }
        }
    }

    // check that every letter of the alphabet existed in the key
    for (int i = 0; i < 26; i++)
    {
        if (alphabet[i] == '\0')
        {

        }
        else
        {
            printf("Error. Key can only contain each letter exactly once.\n");
            return 1;
        }
    }

    string plaintext = get_string("plaintext: ");
    int n = strlen(plaintext);
    char ciphertext[n];
    for (int i = 0; i < n; i++)
    {
        if (isupper(plaintext[i]))
        {
            int position = plaintext[i] - 'A'; // find character position in the alphabet
            ciphertext[i] = toupper(key[1][position]); // change ciphertext to the same character position from the key
        }
        else if (islower(plaintext[i]))
        {
            int position = plaintext[i] - 'a';  // find character position in the alphabet
            ciphertext[i] = tolower(key[1][position]); // change ciphertext to the same character position from the key
        }
        else
        {
            ciphertext[i] = plaintext[i];
        }
    }

    // print the ciphertext by looping through the array
    printf("ciphertext: ");
    for (int i = 0; i < n; i++)
    {
        printf("%c", ciphertext[i]);
    }

    printf("\n");
    return 0;
}
