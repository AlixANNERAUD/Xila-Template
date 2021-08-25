#include "My_Software.hpp"

Xila_Class::Software_Handle My_Software_Handle("My Software", My_Software::Icon_32, My_Software::Load);

// Software loader
Xila_Class::Software *My_Software::Load()
{
    // -- Check if there is a duplicate.
    if (Instance_Pointer != NULL)
    {
        // -- Delete the duplicate.
        delete Instance_Pointer;
    }
    // -- Reset instance pointer
    Instance_Pointer = new My_Software();
    // -- Return instance pointer for Xila.
    return Instance_Pointer;
};

// Software constructor : executed when software is loaded into memory.
My_Software::My_Software() : Xila_Class::Software(My_Software_Handle)
{
    // -- Create main task
    Xila.Task.Create(Main_Task, "My Software Task", Memory_Chunk(4), NULL, &Task_Handle);
};

// Software destructor : executed when software is unloaded of memory.
My_Software::~My_Software()
{
    // -- Check if there is a duplicate
    if (Instance_Pointer != this)
    {
        // -- Delete the duplicate
        delete Instance_Pointer;
    }
    // -- Reset instance pointer
    Instance_Pointer = NULL;
};

// Software variable setter
void My_Software::Set_Variable(Xila_Class::Address Address, Xila_Class::Type Type, const void *Data)
{
    // -- Binds "MA" (0x4D41) address with My_Attribute.
    if (Address == Address('M', 'A'))
    {
        // -- Checks if the indicated type matches the type of the variable.
        if (Type == Xila.Variable_Number)
        {
            My_Attribute = *(double *)Data;
        }
    }
}

// A regular method
void My_Software::My_Method()
{
    Send_Instruction('M', 'M'); // -- Add instruction "MM" to instruction queue.
}

// Software main task
void My_Software::Main_Task(void *)
{
    // -- Main task must never return, so an infinite loop is required
    while (1)
    {
        // -- Get instruction from instruction queue, then bind with a function / instruction.
        switch (Instance_Pointer->Get_Instruction())
        {
        case Instruction('M', 'M'): // -- Bind My_Function() with the instruciton "MM" (0x4D4D)
            Instance_Pointer->My_Method();
            break;
        default: // -- Don't forget default statement.
            break;
        }
        Xila.Task.Delay(20); // -- Don't forget to add delays between operations.
    }
};
