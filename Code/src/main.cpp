#include "Xila.hpp"

// -- Import "My Software" header file.
#include "My_Software.hpp"

void setup()
{
    // -- Import all software handle.
    extern Xila_Class::Software_Handle Calculator_Handle;
    extern Xila_Class::Software_Handle Clock_Handle;
    extern Xila_Class::Software_Handle Internet_Browser_Handle;
    extern Xila_Class::Software_Handle Music_Player_Handle;
    extern Xila_Class::Software_Handle Oscilloscope_Handle;
    extern Xila_Class::Software_Handle Paint_Handle;
    extern Xila_Class::Software_Handle Periodic_Handle;
    extern Xila_Class::Software_Handle Piano_Handle;
    extern Xila_Class::Software_Handle Pong_Handle;
    extern Xila_Class::Software_Handle Simon_Handle;
    extern Xila_Class::Software_Handle Text_Editor_Handle;
    extern Xila_Class::Software_Handle Tiny_Basic_Handle;
    extern Xila_Class::Software_Handle My_Software_Handle;

    // -- Create a software package with all software reference.
    Software_Handle_Class *Custom_Software_Package[13] =
        {
            &Calculator_Handle,
            &Clock_Handle,
            &Internet_Browser_Handle,
            &Music_Player_Handle,
            &Oscilloscope_Handle,
            &Paint_Handle,
            &Periodic_Handle,
            &Piano_Handle,
            &Pong_Handle,
            &Simon_Handle,
            &Text_Editor_Handle,
            &Tiny_Basic_Handle,
            &My_Software_Handle};

    // -- Import software package and start Xila.
    Xila.System.Start(Custom_Software_Package, 13);
}

void loop()
{
    // -- Delete loop task because it's unused.
    Xila.Task.Delete();
}
