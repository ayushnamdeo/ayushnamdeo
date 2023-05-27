#pragma once
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <math.h>
#include "FileRead.h"
using namespace std;


class Calculation
{

public:
   
    int getsize(string file)
    {
        vector<vector <string>> data;
       
        ifstream infile(file);
        while (infile)
        {
            string s;
            if (!getline(infile, s)) break;
            istringstream ss(s);
            vector <std::string> record;
            while (ss)
            {
                string s;
                if (!getline(ss, s, ',')) break;
                record.push_back(s);
            }
            data.push_back(record);
        }

        if (!infile.eof())
        {
            cerr << "Fooey!\n";
        }
        int x = data.size();
        return x;
    }


    int* getnodes(string file, int* arr, int row)
    {
        string line, csvItem;
        int i = 0, count = 0;
        ifstream myfile(file);
        int lineNumber = 0;
        int lineNumberSought = row;  // you may get it as argument
        if (myfile.is_open()) {
            while (getline(myfile, line)) {
                lineNumber++;
                if (lineNumber == lineNumberSought) {

                    istringstream myline(line);
                    while (getline(myline, csvItem, ',')) {


                        if (count >= 3)
                        {
                            arr[i] = stoi(csvItem);
                            i++;

                        }
                        count++;

                    }
                }
            }



            myfile.close();
           // return arr;

        }
        return arr;
    }


    double* get_cordinates(string file, double* arr1, double* return_row_Co, int row)
    {
        string line, csvItem;
        int flag = 0;
        int i = 0, count = 0;

        ifstream myfile(file);
        int lineNumber = 0;
        int lineNumberSought = row;
        if (myfile.is_open()) {
            while (getline(myfile, line)) {
                lineNumber++;

                if ((lineNumber == lineNumberSought) && (flag == 0))
                {
                    flag = 1;
                    istringstream myline(line);
                    while (getline(myline, csvItem, ','))
                    {
                        arr1[i] = stod(csvItem);
                        i++;
                        count++;
                    }

                }
                else if ((lineNumber != lineNumberSought) && (flag == 1))
                {
                    break;
                }
            }
            myfile.close();
            for (int j = 0; j < 3; j++)
            {
                return_row_Co[j] = arr1[j];
            }

           // return return_row_Co;
        }
        return return_row_Co;

    }


    double Area(double a, double b, double c)
    {
        double s = (a + b + c) / 2;

        double area = sqrt((s * (s - a) * (s - b) * (s - c)));
        return area;
    }


    double distance3d(double x1, double y1, double z1, double x2, double y2, double z2)
    {
        long double d = sqrt(pow(x1 - x2, 2.0) + pow(y1 - y2, 2.0) + pow(z1 - z2, 2.0));
        return d;
    }


    double areatriangle(double Triangle_coordinate[3][3])
    {
        double  x1 = Triangle_coordinate[0][0];
        double  y1 = Triangle_coordinate[0][1];
        double  z1 = Triangle_coordinate[0][2];
        double	x2 = Triangle_coordinate[1][0];
        double	y2 = Triangle_coordinate[1][1];
        double	z2 = Triangle_coordinate[1][2];
        double	x3 = Triangle_coordinate[2][0];
        double	y3 = Triangle_coordinate[2][1];
        double	z3 = Triangle_coordinate[2][2];
        double	a = distance3d(x1, y1, z1, x2, y2, z2);
        double	b = distance3d(x2, y2, z2, x3, y3, z3);
        double	c = distance3d(x3, y3, z3, x1, y1, z1);
        double	A = Area(a, b, c);

        return A;

    }


};

