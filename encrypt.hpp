/**
 * file: encrypt.hpp
 * Author: Jinpa Tsering
 * Date: 6/15/2022
 * Description: Implementation of encryption and decryption function.
*/

#include <iostream>

std::string decrypt(std::string &msg){
    char ch;
    int key = 7;
    for(int i = 0; msg[i] != '\0'; ++i) 
    {
        ch = msg[i];
        if(ch == '@')
        {
            ch = 'y';
            msg[i] = ch;
            continue;
        } 
        else if(ch == '$')
        {
            ch = 'z';
            msg[i] = ch;
            continue;
        }
        else if(ch == 'f')
        {
            ch = '$';
            msg[i] = ch;
            continue;
        }
        else if(ch == 'g')
        {
            ch = '@';
            msg[i] = ch;
            continue;
        }
        else if(ch >= 'a' && ch <= 'z')
        {
            //decrypt for lowercase letter
            ch = ch - key;
            if(ch < 'a')
            {
               ch = ch + 'z' - 'a' + 1;
            }
            msg[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z')
        {
            //decrypt for uppercase letter
            ch = ch - key;
            if(ch < 'A') 
            {
               ch = ch + 'Z' - 'A' + 1;
            }
            msg[i] = ch;
        }
        else if(ch >= '0' && ch <= '9')
        {
            ch = ch - key;
            if(ch < '0')
            {
                ch = ch + '9' - '0' + 1;
            }
            msg[i] = ch;
        }
    }
    return msg;
}

std::string encrypt(std::string msg)
{
    int i, j, length,key;
    key = 7;
    length = msg.size();
    char ch;
    for(int i = 0; msg[i] != '\0'; ++i) 
    {
        ch = msg[i];
        if(ch == 'y')
        {
            ch = '@';
            msg[i] = ch;
            continue;
        } 
        else if(ch == 'z')
        {
            ch = '$';
            msg[i] = ch;
            continue;
        }
        else if(ch == '$')
        {
            ch = 'f';
            msg[i] = ch;
            continue;
        }
        else if(ch == '@')
        {
            ch = 'g';
            msg[i] = ch;
            continue;
        }
        else if (ch >= 'a' && ch <= 'z')
        {
            //encrypt for lowercase letter
            ch = ch + key;
            if (ch > 'z') 
            {
               ch = ch - 'z' + 'a' - 1;
            }  
            msg[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            //encrypt for uppercase letter
            ch = ch + key;
            if (ch > 'Z')
            {
               ch = ch - 'Z' + 'A' - 1;
            }
            msg[i] = ch;
        } 
        else if(ch >= '0' && ch <= '9')
        {
            // encrypt for numbers
            ch = ch + key;
            if(ch > '9')
            {
                ch = ch - '9' + '0' - 1;
            }
            msg[i] = ch;
        }
    }
    return msg;
}
