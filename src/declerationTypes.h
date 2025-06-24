#include <cstdint>

#ifdef ASM_CONTEXT
    // Character type override
    #define CHAR_OVERRIDE_START \
        _Pragma("push_macro(\"char\")") \
        _Pragma("undef char") \
        typedef uint8_t char;
    #define CHAR_OVERRIDE_END \
        _Pragma("pop_macro(\"char\")")
    
    // Integer types override
    #define INT_TYPES_OVERRIDE_START \
        _Pragma("push_macro(\"short\")") \
        _Pragma("push_macro(\"int\")") \
        _Pragma("push_macro(\"long\")") \
        _Pragma("undef short") \
        _Pragma("undef int") \
        _Pragma("undef long") \
        typedef int16_t short; \
        typedef int32_t int; \
        typedef uint32_t unsigned int; \
        typedef int32_t long; \
        typedef int64_t long long;
    #define INT_TYPES_OVERRIDE_END \
        _Pragma("pop_macro(\"long\")") \
        _Pragma("pop_macro(\"int\")") \
        _Pragma("pop_macro(\"short\")")
    
    // Pointer types override - Fix syntax issues
    #define PTR_TYPES_OVERRIDE_START \
        _Pragma("push_macro(\"char*\")") \
        _Pragma("push_macro(\"int*\")") \
        /* Can't directly typedef pointer types with the * in the name */ \
        /* Instead, use typedefs for the pointer types */ \
        typedef uint32_t* char_ptr_t; \
        typedef uint32_t* int_ptr_t;
    #define PTR_TYPES_OVERRIDE_END \
        _Pragma("pop_macro(\"int*\")") \
        _Pragma("pop_macro(\"char*\")")
    
    // Floating point types override
    #define FLOAT_TYPES_OVERRIDE_START \
        _Pragma("push_macro(\"float\")") \
        _Pragma("push_macro(\"double\")") \
        _Pragma("undef float") \
        _Pragma("undef double") \
        typedef float float; \
        typedef double double;
    #define FLOAT_TYPES_OVERRIDE_END \
        _Pragma("pop_macro(\"double\")") \
        _Pragma("pop_macro(\"float\")")
    
    // All types override convenience macros
    #define X86_TYPES_OVERRIDE_START \
        CHAR_OVERRIDE_START \
        INT_TYPES_OVERRIDE_START \
        PTR_TYPES_OVERRIDE_START \
        FLOAT_TYPES_OVERRIDE_START
    
    #define X86_TYPES_OVERRIDE_END \
        FLOAT_TYPES_OVERRIDE_END \
        PTR_TYPES_OVERRIDE_END \
        INT_TYPES_OVERRIDE_END \
        CHAR_OVERRIDE_END
#else
    // Redefining things ends when not in ASM context
    #define CHAR_OVERRIDE_START
    #define CHAR_OVERRIDE_END
    #define INT_TYPES_OVERRIDE_START
    #define INT_TYPES_OVERRIDE_END
    #define PTR_TYPES_OVERRIDE_START
    #define PTR_TYPES_OVERRIDE_END
    #define FLOAT_TYPES_OVERRIDE_START
    #define FLOAT_TYPES_OVERRIDE_END
    #define X86_TYPES_OVERRIDE_START
    #define X86_TYPES_OVERRIDE_END
#endif

