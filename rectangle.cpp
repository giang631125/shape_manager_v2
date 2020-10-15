#include "rectangle.h"

class_rectangle::class_rectangle()
{
}

class_rectangle::~class_rectangle()
{
}

void class_rectangle::import_data()
{
    cout<<"Name:";
    cin>>name;
    cout<<"Import 2 edges:"<<endl;
    cin>>edge1;
    cin>>edge2;
}
void class_rectangle::show_data()
{
    cout
    <<setw(15)<<"Rectangle "
    <<setw(3)<<class_rectangle::m_type
    <<setw(15)<<name
    <<setw(14) <<"width: "    <<setw(2)<<edge1
    <<setw(17) <<"diameter: "  <<setw(2)<<edge2
    <<setw(15+1)<<"Area: "      <<setw(6)<<get_area()
    <<setw(15)<<"Perimeter: "   <<setw(6)<<get_perimeter()
    <<endl;
}
void class_rectangle::save_data(string filename)
{
    ofstream outFile;
    outFile.open(filename, ios::app);                    // chen noi dung moi vao cuoi
    outFile
    <<"*rectangle" <<endl
    <<name      <<endl
    <<edge1    <<endl
    <<edge2  <<endl
    <<get_area()        <<endl
    <<get_perimeter()   <<endl;
    outFile.close();
}
shape_type class_rectangle::get_type()
{
    return m_type;
}
float class_rectangle::get_area()
{
    return 2*(edge1+edge2);
}
float class_rectangle::get_perimeter()
{
    return edge1*edge2;
}