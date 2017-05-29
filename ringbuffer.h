#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define MAX_BUFFER 10 ///< Length of global buffer space

#define OK 1        ///< OK
#define ERROR -1        ///< Error

#define BUFF_LEN(a,b) a<b?b-a:a-b

//! \enum error_type enumerators for error conditions
enum error_type
{
  BUFF_OK,                    /*! No error */
  BUFFER_EMPTY,               /*! Buffer is empty */
  BUFFER_FULL,                /*! Buffer is full */
  BUFFER_OVERRUN,              /*! Try to read over buffer end */
  BUFFER_ERROR,
  UNKNOWN_ERROR
};

/*
\struct buffer_type
*/
struct buffer_type
{
  unsigned char *head;   ///< Current adding position of the buffer
  unsigned char *tail;     ///< Currently last entry
  unsigned char *buffer;  ///< Pointer to buffer
};


void empty_buffer(struct buffer_type *b);
void init_buffer(struct buffer_type *b, unsigned char *buffer);
enum error_type create_buffer(struct buffer_type *b, unsigned int size);
int add_char_to_buffer(struct buffer_type *b, unsigned char c, enum error_type *err);
unsigned char get_char_from_buffer(struct buffer_type *b, enum error_type *err);
int add_string_to_buffer(struct buffer_type *b, unsigned char *s, enum error_type *err);
unsigned char get_string_from_buffer(struct buffer_type *b, unsigned char *s, enum error_type *err);
int get_buffer_state(struct buffer_type b);
void print_buffer(struct buffer_type b);
unsigned char *move_pointer_to_next(struct buffer_type *b, unsigned char *p);

enum error_type is_buffer_full(struct buffer_type *b);
enum error_type is_buffer_empty(struct buffer_type *b);
int get_buffer_length(struct buffer_type *b);

extern unsigned char transmission_buffer[MAX_BUFFER];
extern unsigned char recive_buffer[MAX_BUFFER];
