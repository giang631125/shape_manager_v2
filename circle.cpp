#include "circle.h"
#include <fstream>      //

class_circle::class_circle()
{
}

class_circle::~class_circle()
{
}

void class_circle::import_data()
{
    cout<<"Name: ";
    cin>>name;
    cout<<"Import radius: ";
    cin>>radius;
    diameter = 2*radius;
}
void class_circle::show_data()
{
    cout
    <<setw(15)<<"Circle "
    <<setw(3)<<m_type
    <<setw(15)<<name
    <<setw(14) <<"radius: "    <<setw(2)<<radius
    <<setw(17) <<"diameter: "  <<setw(2)<<2*radius
    <<setw(15+1)<<"Area: "      <<setw(6)<<class_circle::get_area()
    <<setw(15)<<"Perimeter: "   <<setw(6)<<class_circle::get_perimeter()
    <<endl;
}
void class_circle::save_data(string filename)
{
    ofstream outFile;
    outFile.open(filename, ios::app);                    // chen noi dung moi vao cuoi
    outFile
    <<"*circle" <<endl
    <<name      <<endl
    <<radius    <<endl
    <<diameter  <<endl
    <<get_area()        <<endl
    <<get_perimeter()   <<endl;
    outFile.close();
}
void class_circle::load_data(ifstream inFile, string filename, string data_line)
{
    // ifstream inFile;
    // getline(inFile,data_line);  name = data_line;       cout<<data_line;
    // getline(inFile,data_line);  radius = stoi(data_line) ;    cout<<data_line;
    // getline(inFile,data_line);  diameter = stoi(data_line);   cout<<data_line;
    // getline(inFile,data_line);  area = stof(data_line);       cout<<data_line;
    // getline(inFile,data_line);  perimeter = stoi(data_line);  cout<<data_line;
}
int class_circle::get_radius()
{
    return radius;
}
int class_circle::get_diameter()
{
    return 2*radius;
}
string class_circle::get_name()
{
    return name;
}
shape_type class_circle::get_type()
{
    return m_type;
}
float class_circle::get_area()
{
    return PI*2*radius;
}
float class_circle::get_perimeter()
{
    return PI*radius*radius;
}