#ifndef NKHOOK5_CLASSES_COLOR
#define NKHOOK5_CLASSES_COLOR
namespace Patcher
{
    namespace Classes
    {
        class Color
        {
            union{
                struct{
                    char Red,Green,Blue,Alpha;
                };
                char arr[4];
            };
        };
    } // namespace Classes
    
} // namespace Patcher
#endif /* NKHOOK5_CLASSES_COLOR */
