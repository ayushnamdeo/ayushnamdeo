#pragma once

#include<string>
#include"Calculation.h"
using namespace std;
class FileRead : Calculation
{
public:
    
    double read(string file)
    {
       
        int arr[10];
        double Triangle_coordinates[3][3];
        // int SumArea = 0;

        int row_number = 0;
        double arr1[10], Co[3], Area, SumArea=0;
        int size = getsize(file);
        for (int i = 0; i < size; i++)
        {
            int* Nodes = getnodes(file, arr, i + 2);
            int column = 0;
            for (column = 0; column < 3; column++)
            {

                row_number = Nodes[column];
                double* row_coordinate = get_cordinates(file, arr1, Co, row_number + 2);
                for (int l = 0; l < 3; l++)
                {
                    Triangle_coordinates[column][l] = *(row_coordinate + l);
                }

            }
            Area = areatriangle(Triangle_coordinates);

            SumArea += Area;
        }
        return SumArea;
    }
};

