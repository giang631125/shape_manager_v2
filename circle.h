#include "shape.h"
// #include "rectangle.h"

#define PI 3.14
#ifndef CIRCLE_H
#define CIRCLE_H

class class_circle : public class_shape
{
private:
       
public:
    int radius,diameter;
    // float area, perimeter; 
    // string name;
    class_circle(); 
    ~class_circle();
    const shape_type m_type = CIRCLE_TYPE;
    void import_data();
    void show_data();
    void save_data(string filename);
    void load_data(ifstream inFile, string filename, string data_line);
    int get_radius();
    int get_diameter();
    string get_name();
    shape_type get_type();
    float get_area();
    float get_perimeter();
};
#endif