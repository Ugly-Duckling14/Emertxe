#ifndef TYPES_H
#define TYPES_H

/* User defined types */
typedef unsigned int uint;

/* Status will be used in fn. return type */
typedef enum
{
    e_success,
    e_failure
} Status;

/* Status_pass will be used for password validation. return type */
typedef enum
{
    e_successp,
    e_failurep,
    e_neitherp
} Status_pass;

typedef enum
{
    e_encode,
    e_decode,
    e_unsupported
} OperationType;

#endif
