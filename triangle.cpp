#include "triangle.h"
#include <math.h>

class_triangle::class_triangle()
{
}
class_triangle::~class_triangle()
{
}
void class_triangle::import_data()
{
    cout<<"Name: ";
    cin>>name;
    // class_triangle::m_type = TRIANGLE_TYPE;
    do
    {
        cout<<"Import 3 edges:"<<endl;
        cin>>edge1;
        cin>>edge2;
        cin>>edge3;  
    }
    while( !((edge1+edge2)>edge3 && (edge3+edge2)>edge1 && (edge1+edge3)>edge2) );
        //  cout<<"Wrong triangle. Pls import again.";
    
}
void class_triangle::show_data()
{
    cout
    <<setw(15)<<"Triangle "
    <<setw(3)<<class_triangle::get_type()
    <<setw(15)<<name
    <<setw(14) <<"edge1: "    <<setw(2)<<edge1
    <<setw(8) <<"edge2: "   <<setw(2)<<edge2
    <<setw(8) <<"edge3: "  <<setw(2)<<edge3
    <<setw(15)<<"Area: "      <<setw(6)<<get_area()
    <<setw(15)<<"Perimeter: "   <<setw(6)<<get_perimeter()
    <<endl;
}
void class_triangle::save_data(string filename)
{
    ofstream outFile;
    outFile.open(filename, ios::app);                    // chen noi dung moi vao cuoi
    outFile
    <<"*triangle" <<endl
    <<name      <<endl
    <<edge1    <<endl
    <<edge2  <<endl
    <<edge3  <<endl
    <<get_area()        <<endl
    <<get_perimeter()   <<endl;
    outFile.close();
}
shape_type class_triangle::get_type()
{
    return m_type;
}
float class_triangle::get_area()
{
    return edge1+edge2+edge3;
}
float class_triangle::get_perimeter()
{
    float p = (float)(edge1 + edge2 + edge3) / 2;
	float s = std::sqrt(p * (p - edge1) * (p - edge2) * (p - edge3));
	return s;
}