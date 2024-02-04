#ifndef TYPES_H
#define TYPES_H
#define DEC 50

typedef enum
{
    e_help,
    e_view,
    e_edit,
    e_version,
    e_unsupported
}OperaType;

typedef enum
{
    e_failure,
    e_success
}Status; 

#endif