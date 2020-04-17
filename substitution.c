#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    /*declared variables*/
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";//alfabeto maiusculo
    string alphabetM = "abcdefghijklmnopqrstuvwxyz";//alfabeto minusculo
    int arrayAlph[26];//delaro array do alfabeto
    int arrayAlphM[26]; //array alfabeto minusculo
    int arrayKey[26];//chave recibida via argumento em um array

    /*if has argv*/
    if (argc != 2) // testa se recebeu um segundo argumento com a key
    {
        printf("missing command-line argument\n");
        return 1;
    }
    if (strlen(argv[1]) < 26 || strlen(argv[1]) > 26)  // testa se a chave tem o tamanho especifico
    {
        printf("missing command-line argument\n");
        return 1;
    }

    for (int i = 0; i < 26; i++) //testa se é do alfabeto
    {
        if (!isalpha(argv[1][i]))
        {
            printf("missing command-line argument\n");
            return 1;
        }
    }
    for (int i = 0; i < 26; i++)
    {
        int index = 0;
        for (int it = 0; it < 26; it++)
        {
            if (argv[1][i] == argv[1][it])
            {
                index++;
            }
            if (index >= 2)
            {
                printf("missing command-line argument\n");
                return 1;
            }
        }
    }

    /*get_string*/
    string plainText = get_string("plaintext: ");//recebe o texto a ser criptografado
    int cipherText[strlen(plainText)];//cria um array apartir do tamanho da string acima

    for (int i = 0; i < 26; i++) // cria o arrays
    {
        arrayAlph[i] = alphabet[i];
        arrayAlphM[i] = alphabetM[i];
        if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
        {
            arrayKey[i] = argv[1][i];
        }
        else
        {
            arrayKey[i] = argv[1][i] - 32;
        }

    }
    /*position char in alphabet*/
    for (int i = 0; i < 26; i++)//para cada letra do alfabeto(26) faça ...
    {
        for (int it = 0, n = strlen(plainText); it < n; it++) //para cada letra do texto a ser criptografado faça ....
        {
            if (plainText[it] >= 'a' && plainText[it] <= 'z') //se for uma letra minuscula
            {
                if (alphabetM[i] == plainText[it]) //se alfabeto minusculo for igual a letra
                {
                    cipherText[it] = arrayKey[i] + 32; // adicione a letra da key na posição [i] no array criptografado
                }
            }
            else if (plainText[it] >= 'A' && plainText[it] <= 'Z') // mesma coisa de cima só que para letra maiuscula
            {
                if (alphabet[i] == plainText[it])
                {
                    cipherText[it] = arrayKey[i];
                }
            }
            else
            {
                cipherText[it] = plainText[it];
            }
        }
    }
    printf("ciphertext: ");
    for (int i = 0, n = strlen(plainText); i < n; i++) // printa cada posição do array formando uma frase
    {
        printf("%c", cipherText[i]);
    }
    printf("\n");
    return 0;
}