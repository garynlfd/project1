#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main(int argc, char *argv[])
{
    int row, col;
    int num = 0;
    string file = "./";
    string studentID = argv[1];
    string fileinput = file + studentID + "/matrix.data";
    string fileoutput = file + studentID + "/final.peak";
    ifstream input;
    ofstream output;
    input.open(fileinput.c_str());
    if(input)
    {
        input >> row >> col;
        int matrix[row][col];
        int tmp[row][col] = {0};
        int ans[row*col*2] = {0};
        while(!input.eof())
        {
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
        input.close();
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
                            num++;
                            ans[2*num-2] = i;
                            ans[2*num-1] = j;
                        }
                    }
                    else if(i == row - 1)
                    {
                        if(matrix[i][j] >= matrix[i-1][j])
                        {
                            num++;
                            ans[2*num-2] = i;
                            ans[2*num-1] = j;
                        }
                    }
                    else
                    {
                        if(matrix[i][j] >= matrix[i-1][j] && matrix[i][j] >= matrix[i+1][j])
                        {
                            num++;
                            ans[2*num-2] = i;
                            ans[2*num-1] = j;
                        }
                    }
                }
            }
        }
        output.open(fileoutput.c_str());
        output << num << endl;
        for(int i = 0; i <= 2*num-1; ++i)
        {
            if(!(i % 2)) output << ans[i] + 1 << ' ';
            else output << ans[i] + 1 << endl;
        }
        output.close();
    }
    return 0;
}
