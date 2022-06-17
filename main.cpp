/**
 * file: main.hpp
 * Author: Jinpa Tsering
 * Date: 6/15/2022
 * Description: write encrypted text to file.
 *              read and decrypt the file content.
*/

#include <iostream>
#include <fstream>
#include "encrypt.hpp"

int main()
{
    // open for writing
    std::ofstream f;
    f.open("file.txt");
    std::string linesOfText[] = {
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789\n",
        "I love encryption for real.\n",
        };
    for (int i = 0; i < 2; i++) 
    {
        f << encrypt(linesOfText[i]);
    }
    f.close();
    
    // open for reading
    std::ifstream myfile ("file.txt"); 
    std::string lineOfText;
    if (myfile.is_open())
    {
        while(getline(myfile,lineOfText))
        {
            std::cout << "Encrypted message: " << lineOfText << std::endl; //void(string)
            std::cout << "Decrypted message: " << decrypt(lineOfText) << std::endl; //void(string)
        }
    }
    myfile.close();
    
    return 0;
}
