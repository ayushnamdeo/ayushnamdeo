#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include <math.h>
#include "FileRead.h"
#include"Calculation.h"
using namespace std;


int main()
{
    double Area_mesh_ref, Area_mesh1, Area_mesh2;
    FileRead f;
    Area_mesh_ref = f.read("mesh_reference.csv");
    Area_mesh1 = f.read("mesh1.csv");
    Area_mesh2 = f.read("mesh2.csv");

    cout << "area of reference mesh is : " << Area_mesh_ref << endl;
    cout << "area of 1st mesh is : " << Area_mesh1 << endl;
    cout << "area of 2nd mesh is : " << Area_mesh2 << endl;
    //  Compare areas;

    double tolerence_mesh1 = ((abs(Area_mesh1 - Area_mesh_ref)) / (Area_mesh_ref)) * 100;
    double tolerence_mesh2 = ((abs(Area_mesh2 - Area_mesh_ref)) / (Area_mesh_ref)) * 100;

    cout << "tolerence_mesh1 = " << tolerence_mesh1 << " % " << endl;
    cout << "tolerence_mesh2 = " << tolerence_mesh2 << " % " << endl;

    cout << " You can see that mesh2 is more closely related to Mesh Reference than mesh1" << endl;


}