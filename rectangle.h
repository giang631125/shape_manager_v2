#include "shape.h"

class class_rectangle: public class_shape
{
private:
    
public:
    class_rectangle(); 
    ~class_rectangle();
    static const shape_type m_type = RECTANGLE_TYPE;
    void import_data();
    void show_data();
    void save_data(string filename);
    shape_type get_type();
    float get_area();
    float get_perimeter();
};
