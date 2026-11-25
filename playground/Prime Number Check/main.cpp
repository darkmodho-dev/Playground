#include <iostream>
int main()
{
    int player;
    int W = 2;
    bool prime = true;
    std::cout << "Enter Number: ";
    std::cin >> player;
    if (player == 2 || player == 1) {std::cout << "Prime"; prime = false;}
    if (player < 1){std::cout << "InvalidInput"; prime = false;}
    while (prime) {
        if (player % W == 0)
        {
            std::cout << "Is Not Prime";
            prime = false;
        }
        else{W++;}
        if (W == player)
        {
            std::cout << "Prime";
            prime = false;
        }
    }
}
