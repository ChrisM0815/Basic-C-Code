#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*ctype.h contains functions that can be used to check if the char equivalent of a int number belongs to a certain group 
 * of symbols(for example alhanumeric,dcimal digit,etc.)
 * If the number belongs to the group a 1 is returned. Else a 0 is returned
 * 
 * It also contains to functions to convert Uppercase letters to lowercase letters an vise versa 
*/
int main()
{
    int number = 65;
    char ch = number;
    printf("The number %d as a Charakter is : %c\n",number,ch);
    
    if(isalnum(number))//This is a set of Digits, Lowercase letters and Uppercase letters.
        printf("It's alphanumeric\n");
    
    if(isalpha(number))//This is a set of lowercase and uppercase letters.
        printf("It's alphabetic\n");
    
    if(iscntrl(number))//In ASCII, these characters have octal codes 000 through 037, and 177 (DEL).
        printf("It's a control charakter\n");
    
    if(isdigit(number))//{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }
        printf("It's decimal\n");
    
    if(isgraph(number))//This is a set of Alphanumeric characters and Punctuation characters.
        printf("It has a graphical representation using locale\n");
    
    if(islower(number))//{ a b c d e f g h i j k l m n o p q r s t u v w x y z }
        printf("It's a lowercase letter\n");
    
    if(isprint(number))//This is a set of Alphanumeric characters, Punctuation characters and Space characters.
        printf("It's printable\n");
    
    if(ispunct(number))//This is a set of ! " # $ % & ' ( ) * + , - . / : ; < = > ? @ [ \ ] ^ _ ` { | } ~
        printf("It's a punctuation charakter\n");
    
    if(isspace(number))//This is a set of tab, newline, vertical tab, form feed, carriage return, and space.
        printf("It's a white-space\n");
    
    if(isupper(number))//{A B C D E F G H I J K L M N O P Q R S T U V W X Y Z }
        printf("It's a uppercase letter\n");
    
    if(isxdigit(number))//{ 0 1 2 3 4 5 6 7 8 9 A B C D E F a b c d e f }
        printf("It's hexadecimal digit\n");
        
     //functions to convert to Upper-/lowercase   
        
    if(islower(number))
        printf("The Letter as uppercase: ASCII:%d char:%c\n", toupper(number),tolower(number));
    
    if(isupper(number))
        printf("The Letter as lowercase: ASCII:%d char:%c\n", tolower(number),tolower(number));
    
}

