#include "iostream"

int main()
{
    int w = 2;
    int player;
    std::cout << "Wellcome To the Big Math\n";
    std::cout << "Enter your number: ";
    std::cin >> player;
    if (player % w == 0)
    {
        std::cout << "Your number is even\n";
        for (int i = 0; i < player; i++)
        {
            if (i % w == 0)
            {
                std::cout << i << " ";
            }
            
        }
    }
    else 
    {
        std::cout << "Your number is odd\n";
    }
    
}