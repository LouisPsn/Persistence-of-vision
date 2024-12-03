#include "../h/buffer.h"


// Initialise le buffer circulaire
void ring_buffer_init(struct ring_buffer *rb)
{
    for (int i = 0; i < RING_BUFFER_SIZE; i++)
    {
        rb->buffer[i] = 0;
    }
    rb->write = 0;
    rb->read = 0;
    rb->available = 0;
}

// gère l'incrémentation de write
void ring_buffer_incr_write(struct ring_buffer *rb)
{
    if (rb->write == RING_BUFFER_SIZE - 1)
    {
        rb->write = 0;
    }
    else
    {
        rb->write += 1;
    }
    //rb->available--;
}

// gère l'incrémentation de read
void ring_buffer_incr_read(struct ring_buffer *rb)
{
    if (rb->read == RING_BUFFER_SIZE - 1)
    {
        rb->read = 0;
    }
    else
    {
        rb->read += 1;
    }
    //rb->available++;
}

// Ajoute un octet dans le buffer circulaire
void ring_buffer_put(struct ring_buffer *rb, uint16_t data)
{
    rb->buffer[rb->write] = data;
    ring_buffer_incr_write(rb);
}

// Récupère un octet du buffer circulaire
uint16_t ring_buffer_get(struct ring_buffer *rb)
{
    uint16_t res = rb->buffer[rb->read];
    ring_buffer_incr_read(rb);
    return res;
}

// Indique le nombre d'octets disponibles dans le buffer circulaire
uint8_t ring_buffer_available_bytes(struct ring_buffer *rb)
{
    return rb->available;
}

// Indique si le buffer circulaire est plein
uint8_t ring_buffer_is_full(struct ring_buffer *rb)
{
    if (rb->available == 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

void ring_buffer_put_2(struct ring_buffer *rb, uint16_t data, uint16_t position)
{
    rb->buffer[position] = data;
}


uint16_t ring_buffer_get_2(struct ring_buffer *rb, int16_t position)
{
    uint16_t res = rb->buffer[position];
    return res;
}

void clear_buffer(struct ring_buffer *rb){
    for(int i=0; i<RING_BUFFER_SIZE;i++){
        ring_buffer_put_2(rb, 0, i);
    }
}