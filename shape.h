#include <iostream>
using namespace std;
#include <string>
#include <fstream>      //
#include <iomanip>      // std::setw()

#ifndef CLASS_SHAPE_h
#define CLASS_SHAPE_h

enum shape_type
{
    CIRCLE_TYPE,
    RECTANGLE_TYPE,
    TRIANGLE_TYPE
};

class class_shape
{
    public:
        int edge1, edge2, edge3;
        // shape_type m_type;
        string name;
        class_shape();
        ~class_shape();
        virtual shape_type get_type();
        virtual void import_data();
        virtual void show_data();
        virtual void save_data(string filename);
        // virtual string get_name();
        virtual float get_area();
        virtual float get_perimeter();
};
#endif