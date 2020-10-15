#include "shape.h"
#ifndef TRIANGLE_H
#define TRIANGLE_H

class class_triangle : public class_shape
{
private:
    
public:
    class_triangle(); 
    ~class_triangle();
    static const shape_type m_type = TRIANGLE_TYPE;
    void import_data();
    void show_data();
    void save_data(string filename);
    shape_type get_type();
    float get_area();
    float get_perimeter();
};
#endif