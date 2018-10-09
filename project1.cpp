<<<<<<< HEAD
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <limits>
using namespace std;

int main()
{
    int row, col;
    int a_row = 0, a_col = 0;
    int max = 0;
    cin >> row >> col;
    int map[row][col];
    auto start = chrono::high_resolution_clock::now();
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin >> map[i][j];
            if(i == 0 && j == 0)
            {
                max = map[i][j];
                a_row = i, a_col = j;
            }
            else
            {
                if(map[i][j] > max)
                {
                    max = map[i][j];
                    a_row = i, a_col = j;
                }
            }
        }
    }
    auto end = chrono::high_resolution_clock::now();
    cout << max << endl;
    chrono::duration<double, nano> diff = end - start;
    cout << a_row << ' ' << a_col << endl;
    cout << diff.count() << " nanoseconds" << std::endl;
    return 0;
}
=======
#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <limits>
using namespace std;

int main()
{
    int row, col;
    int max = 0;
    cin >> row >> col;
    int map[row][col];
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            cin >> map[i][j];
        }
    }
    auto start = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(i == 0 && j == 0)
            {
                max = map[i][j];
            }
            else
            {
                if(map[i][j] > max)
                {
                    max = map[i][j];
                }
            }
        }
    }
    auto end = std::chrono::high_resolution_clock::now();
    cout << max << endl;
    std::chrono::duration<double, std::nano> diff = end - start;
    std::cout << diff.count() << " nanoseconds" << std::endl;
    return 0;
}
>>>>>>> c345ea4ddf6474c6307541ac99cdbe61f5b98026
