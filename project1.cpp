#include <iostream>
#include <chrono>
#include <iomanip>
#include <cmath>
#include <limits>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    int row, col;
    int matrix[row][col];
    int num = 0;
    int tmp[1000][1000] = {0};
    int ans[1000][1000] = {0};
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
            for(int i = 0; i < row; ++i)
            {
                for(int j = 0; j < col; ++j)
                {
                    input >> matrix[i][j];
                }
            }
            int eat;
            input >> eat;
        }
    }
    input.close();
    auto start = chrono::high_resolution_clock::now();
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            if(j == 0)
            {
                if(matrix[i][j] >= matrix[i][j+1])
                {
                    tmp[i][j] = 1;
                    if(matrix[i][j] > matrix[i][j+1])
                    {
                        ++j;
                    }
                }
            }
            else if(j == col - 1)
            {
                if(matrix[i][j] >= matrix[i][j-1])
                {
                    tmp[i][j] = 1;
                }
            }
            else
            {
                if(matrix[i][j] >= matrix[i][j+1] && matrix[i][j] >= matrix[i][j-1])
                {
                    tmp[i][j] = 1;
                    if(matrix[i][j] > matrix[i][j+1])
                    {
                        ++j;
                    }
                }
            }
        }
    }
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            if(tmp[i][j] == 1)
            {
                if(i == 0)
                {
                    if(matrix[i][j] >= matrix[i+1][j])
                    {
                        ans[i][j] = 1;
                        num++;
                    }
                }
                else if(i == row - 1)
                {
                    if(matrix[i][j] >= matrix[i-1][j])
                    {
                        ans[i][j] = 1;
                        num++;
                    }
                }
                else
                {
                    if(matrix[i][j] >= matrix[i-1][j] && matrix[i][j] >= matrix[i+1][j])
                    {
                        ans[i][j] = 1;
                        num++;
                    }
                }
            }
        }
    }
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double, nano> diff = end - start;
    cout << num << endl;
    for(int i = 0; i < row; ++i)
    {
        for(int j = 0; j < col; ++j)
        {
            if(ans[i][j] == 1)
            {
                cout << i << " " << j << endl;
            }
        }
    }
    cout << diff.count() << " nanoseconds" << std::endl;
    output.open(fileoutput.c_str());
    //output <<
    output.close();
    return 0;
}
