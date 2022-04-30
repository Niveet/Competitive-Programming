#include <iostream>
#include <utility>


int main()
{
    //Fast IO
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    //Get length of the board
    long long int len{ 0 };
    std::cin >> len;

    
    // Init white and black king's position
    std::pair < unsigned long long int, unsigned long long int> white_king(1,1);
    std::pair < unsigned long long int, unsigned long long int> black_king(len, len);


    //Get gold_coords
    unsigned long long int x{}; 
    unsigned long long int y{};
    std::cin >> x >> y;

    std::pair < unsigned long long int, unsigned long long int> coin(x, y);
    
    //check for base cases
    if ((white_king == coin))
    {
        std::cout << "white" << std::endl;
        return 0;
    }

    else if ((black_king == coin))
    {
        std::cout << "black" << std::endl;
        return 0;
    }

    //finding steps that white will take
    std::pair < unsigned long long int, unsigned long long int > distanceW(0, 0);
    distanceW.first = coin.first - white_king.first;
    distanceW.second = coin.second - white_king.second;
    unsigned long long int stepsW{ std::max(distanceW.first, distanceW.second) };

    //finding steps that black will take
    std::pair < unsigned long long int, unsigned long long int > distanceB(0, 0);
    distanceB.first = black_king.first - coin.first;
    distanceB.second = black_king.second - coin.second;
    unsigned long long int stepsB{ std::max(distanceB.first, distanceB.second) };

    //Since white starts first, it will beat black if the steps are equal
    if (stepsW <= stepsB)
    {
        std::cout << "white" << std::endl;
    }
    else
    {
        std::cout << "black" << std::endl;
    }
    
}
