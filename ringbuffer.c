//
#include "include.h"

void empty_buffer(struct buffer_type *b)
{}
void init_buffer(struct buffer_type *b, unsigned char *buffer)
{}
enum error_type create_buffer(struct buffer_type *b, int size)
{}
int add_char_to_buffer(struct buffer_type *b, unsigned char c,
                                 enum error_type *err) {}
unsigned char get_char_from_buffer(struct buffer_type *b,
                                             enum error_type *err)
{}
int add_string_to_buffer(struct buffer_type *b, unsigned char *s,
                         enum error_type *err)
{}
unsigned char get_string_from_buffer(struct buffer_type *b, unsigned char *s,
                                     enum error_type *err)
{}
int get_buffer_state(struct buffer_type b)
{}
void print_buffer(struct buffer_type b)
{}
unsigned char *move_pointer_to_next(struct buffer_type *b, unsigned char *p)
{}
