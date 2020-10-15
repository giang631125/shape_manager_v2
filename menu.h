#include <string>
#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>    // std::sort

// #include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "triangle.h"

enum option_menu
{
    OPTION_EXIT,    
    OPTION_IMPORT,   
    OPTION_SHOW,    
    OPTION_DELETE,  
    OPTION_UPDATE,  
    OPTION_SAVE,     
    OPTIOM_ARRANGE  
};

class class_menu 
{
    private:
        option_menu     user_choise;
        void            import_shape_data();
        void            show_shape_data();
        void            delete_shape_data();
        void            update_shape_data();
        void            save_shape_data(string filename);
        void            arrange_shape_data();
        vector<class_shape*>    m_shape;
        class_circle*           m_circle;
        class_rectangle*        m_rectangle;
        class_triangle*         m_triangle;
    public:
        class_menu();
        ~class_menu();
        void load_shape_data(std::string file_name);
        void show_menu();
};