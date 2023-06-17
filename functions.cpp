#include "functions.hpp"
#include <iostream>
#include <string>


void render_table(std::string (*chessPieces)[8])
{

std::string (*arr)[8]= chessPieces;
    for (int row = 0; row < 9; ++row)
    {
        int num = 8 - row;
        if (row == 0)
        {
            std::cout << "        ";
            for (int alf = 0; alf < 8; ++alf)
            {
                char ch = 'a' + alf;
                std::cout << "   " << ch << "  ";

                if (alf == 7)
                {
                    std::cout << std::endl;
                }
            }
        }

        std::cout << "         ";
        for (int col1 = 0; col1 < 9; ++col1)
        {
            if (col1 != 8)
            {
                std::cout << "+ - - ";
            }
            else
            {
                std::cout << "+";
            }
        }

        std::cout << std::endl;
        if (row != 8)
        {
            std::cout << "       " << num << " ";
            for (int col2 = 0; col2 < 9; ++col2)
            {
                if (col2 != 8)
                {
                    std::cout << "| " << chessPieces[row][col2] << " ";
                }
                else
                {
                    std::cout << "| " << num;
                }
            }
        }

        if (row == 8)
        {
            std::cout << "         ";
            for (int alf = 0; alf < 8; ++alf)
            {
                char ch = 'a' + alf;
                std::cout << "   " << ch << "  ";

                if (alf == 7)
                {
                    std::cout << std::endl;
                }
            }
        }

        std::cout << std::endl;
    }
    
}

void step(std::string (*chessPieces)[8])
{
   // what figure want to move 
   std::string currentPos;
   std::cout << "what figure do you want to move (example a1)";
   std:: cin >> currentPos;
   int current_col = currentPos[0] - 'a';
   int current_row = 8 -  (currentPos[1] - '0');

   // where want to move
   std::string newPos;
   std::cout << "where do you want to move (example a4)";
   std:: cin >> newPos;
   int newPos_col = (newPos[0] - 'a');
   int newPos_row = 8 -  (newPos[1] - '0');
   

 // moving
   std::string c_pos =  chessPieces[current_row][current_col];
   chessPieces[current_row][current_col] = "   ";
   chessPieces[newPos_row][newPos_col] = c_pos;



// new table   
   render_table(chessPieces);
}





