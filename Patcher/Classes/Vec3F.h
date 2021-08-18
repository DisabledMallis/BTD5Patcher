#ifndef NKHOOK5_CLASSES_VEC3F
#define NKHOOK5_CLASSES_VEC3F
namespace Patcher
{
    namespace Classes
    {
        class Vec3F
        {
            union
            {
                struct
                {
                    float x;
                    float y;
                    float z;
                };
                float arr[3];
            };
        };
    } // namespace Classes
    
} // namespace Patcher
#endif /* NKHOOK5_CLASSES_VEC3F */
