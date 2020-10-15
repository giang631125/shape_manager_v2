#include "menu.h"

class_menu::class_menu()
{
}

class_menu::~class_menu()
{
}

void class_menu::load_shape_data(std::string file_Name)
{
    string data_line;
    ifstream inFile;
    inFile.open("data.txt");
    if(!inFile)
    {
        cout<<"Unable to open file.";
        exit(1);
    }
    while( getline(inFile,data_line) )
    {
        if(data_line == "*circle")
        {
            m_circle = new class_circle;
            // class_circle::load_data(inFile,"data.txt",data_line);
            getline(inFile,data_line);  m_circle->name = data_line;       cout<<data_line;
            // getline(inFile,data_line);  m_circle->get_name() = data_line;       cout<<data_line;
            // getline(inFile,data_line);  m_circle->get_radius() = stoi(data_line) ;    cout<<data_line;
            getline(inFile,data_line);  m_circle->radius = stoi(data_line) ;    cout<<data_line;
            m_shape.push_back(m_circle);
        }
        if(data_line == "*rectangle")
        {
            m_rectangle = new class_rectangle;
            getline(inFile,data_line); m_rectangle->name = data_line;           cout<<data_line;
            getline(inFile,data_line); m_rectangle->edge1 = stoi(data_line);    cout<<data_line;
            getline(inFile,data_line); m_rectangle->edge2 = stoi(data_line);    cout<<data_line;
            m_shape.push_back(m_rectangle);
        }
        if(data_line == "*triangle")
        {
            m_triangle = new class_triangle;
            getline(inFile,data_line); m_triangle->name = data_line;           cout<<data_line;
            getline(inFile,data_line); m_triangle->edge1 = stoi(data_line);    cout<<data_line;
            getline(inFile,data_line); m_triangle->edge2 = stoi(data_line);    cout<<data_line;
            getline(inFile,data_line); m_triangle->edge3 = stoi(data_line);    cout<<data_line;
            m_shape.push_back(m_triangle);
        }
    }
}
void class_menu::show_menu()
{
    int choise;
    while( user_choise != OPTION_EXIT )
    {   
        cout<<endl;
        cout<<"---MENU---"<<endl;
        cout<<"1.Import data"<<endl;
        cout<<"2.Show data"<<endl;
        cout<<"3.Delete data"<<endl;
        cout<<"4.Update"<<endl;
        cout<<"5.Save"<<endl;
        cout<<"6.Arrange"<<endl;
        cout<<"0.Exit"<<endl;
        
        cin>>choise;
        user_choise = (option_menu) choise;
        switch (user_choise)
        {
        case OPTION_IMPORT:
            import_shape_data();
            break;
        case OPTION_SHOW:
            show_shape_data();
            break;
        case OPTION_DELETE:
            delete_shape_data();
            break;
        case OPTION_UPDATE:
            update_shape_data();
            break;
        case OPTION_SAVE:
            save_shape_data("data.txt");
            break;
        case OPTIOM_ARRANGE:
            // arrange_shape_data();
        default:
            break;
        }
    }
    cout<<"Save changed? \n 1.Yes  0.No"<<endl;
    cin>>choise;
    if(choise)
        save_shape_data("data.txt");
}

void class_menu::import_shape_data()
{
    cout<<"---SHAPE CHOISE---"<<endl;
    int choise;
    do
    {
        cout<<"1.Circle  2.Rectangle  3.Triangle  0.Back to menu"<<endl;
        cin>>choise;
        switch (choise)
        {
        case 1:
            m_circle = new class_circle();
            m_circle->import_data();
            m_shape.push_back(m_circle);
            break;
        case 2:
            m_rectangle = new class_rectangle();
            m_rectangle->import_data();
            m_shape.push_back(m_rectangle);
            break;
        case 3:
            m_triangle = new class_triangle();
            m_triangle->import_data();
            m_shape.push_back(m_triangle);
            break;
        default:
            break;
        }
    }
    while(choise != 0);
}
void class_menu::show_shape_data()
{
    for (auto it = m_shape.begin(); it != m_shape.end(); it++)
    {
        cout<<*it;
        (*it)->show_data();
    }
}
void class_menu::delete_shape_data()
{
    cout<<"---Choise delete shape---"<<endl;
    int stt=0;
    for(auto it = m_shape.begin(); it != m_shape.end(); it++)
    {
        cout<<stt<<"."<<(*it)->name<<"\t"<<endl;
        stt++;
    }
    cin>>stt;
    m_shape.erase(m_shape.begin()+stt);
}
void class_menu::update_shape_data()
{
    cout<<"---Choise change shape---"<<endl;
    int data_change=0;
    for(auto it = m_shape.begin(); it != m_shape.end(); it++)
    {
        cout<<data_change<<"."<<(*it)->name<<"\t"<<(*it)->get_type()<<endl;
        data_change++;
    }
    cin>>data_change;
    switch (m_shape.at(data_change)->get_type())
    {
    case RECTANGLE_TYPE:
        m_rectangle = new class_rectangle;
        m_rectangle->import_data();
        m_shape.at(data_change) = m_rectangle;
        break;
    case TRIANGLE_TYPE:
        m_triangle = new class_triangle;
        m_triangle->import_data();
        m_shape.at(data_change) = m_triangle;
        break;
    case CIRCLE_TYPE:
        m_circle = new class_circle;
        m_circle->import_data();
        m_shape.at(data_change) = m_circle;
        break;
    default:
        break;
    }
}
void class_menu::save_shape_data(string filename)
{
    ofstream inFile;
    inFile.open("data.txt", std::ofstream::out | std::ofstream::trunc);      // clear all data of file
    inFile.close();
    cout<<"Saved data to file: "<<filename<<endl;
    for (auto it = m_shape.begin(); it != m_shape.end(); it++)
    {
        (*it)->save_data("data.txt");
    }
}
bool name_atoz(int a, int b)
{
    return (a<b);
}
void class_menu::arrange_shape_data()
{
    vector<string> name_shape;
    for(auto it = 0; it != m_shape.size(); it++)
    {
        name_shape.push_back(m_shape.at(it)->name);
        std::sort_heap(m_shape.begin(), m_shape.end());
    }
    sort_heap(name_shape.begin(),name_shape.end());
    for(auto it = name_shape.begin(); it!=name_shape.end();it++)
    {
        cout<<*it<<" ";
    }
}