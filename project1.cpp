#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <limits>
#include <string>
#include <fstream>
using namespace std;

void calculate()
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
    //return 0;
}

int main(int argc, char *argv[])
{
    int row, col;
    string file = "./";
    string studentID = argv[1];
    string fileinput = file + studentID + "/matrix.data";
    string fileoutput = file + studentID + "/final.peak";
    ifstream input;
    ofstream output;
    input.open(fileinput.c_str());
    if(input)
    {
        while(!input.eof())
        {
            input >> row >> col;
            int matrix[row][col];
            for(int i = 0; i < row; ++i)
            {
                for(int j = 0; j < col; ++j)
                {
                    input >> matrix[i][j];
                }
            }
            for(int i = 0; i < row; ++i)
            {
                for(int j = 0; j < col; ++j)
                {
                    cout << matrix[i][j] << " ";
                }
                cout << endl;
            }
            int eat;
            input >> eat;
        }
    }

    input.close();
    output.open(fileoutput.c_str());
    output.close();
    return 0;
}
