#ifndef BIT_CONTROL
#define BIT_CONTROL

typedef enum Bool { 
    FALSE = 0, 
    TRUE = 1,
} Bool;

int is_bit_set(int num, int index);
int set_bit(int* num, int index);
int reset_bit(int* num, int index);
Bool place_bit(int* num, int index, Bool bit);

#endif