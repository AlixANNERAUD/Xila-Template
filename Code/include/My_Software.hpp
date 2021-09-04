///
 /// @file My_Software.hpp
 /// @author Alix ANNERAUD (alix.anneraud@outlook.fr)
 /// @brief This the header file of Xila software template.
 /// @version 0.1
 /// @date 03-09-2021
 /// 
 /// @copyright Copyright (c) 2021
 /// 

#include "Xila.hpp"

// -- Software class which contains all function and data of the software.
class My_Software : public Xila_Class::Software
{
// -- Opt for private encapsulation for methods and attributes.
private:
    static My_Software *Instance_Pointer;

    void Set_Variable(Xila_Class::Address Address, Xila_Class::Type Type, const void *Data);

    double My_Attribute;

    void My_Method();

// -- Avoid public encapsulation as much as you can.
public:
    // -- Main task
    static void Main_Task(void *);

    // -- Pages enumeration
    enum Pages
    {
        Pages = 39
    };

    // -- Image enumeration
    enum Image
    {
        Icon_32 = 44
    };

    My_Software();

    ~My_Software();

    static Xila_Class::Software *Load();
};
