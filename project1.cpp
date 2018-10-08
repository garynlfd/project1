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
