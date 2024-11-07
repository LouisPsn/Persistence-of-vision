#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include "../h/buffer.h"

#define RING_BUFFER_SIZE  // Aka number of "frames" during 1 turn of wheel
#define MAX_NB_FRAME 10

struct ring_buffer
{
    uint16_t data[RING_BUFFER_SIZE][MAX_NB_FRAME];
    int read;
    int write;
    int nb_frames;
};

// Initialise le buffer circulaire
void ring_buffer_init(struct ring_buffer *rb)
{
    for (int i = 0; i < RING_BUFFER_SIZE; i++)
    {
        rb->data[i] = 0;
    }
    rb->read = 0;
    rb->write = 0;
}

// Ajoute un octet dans le buffer circulaire
void ring_buffer_put(struct ring_buffer *rb, uint8_t data)
{
    rb->data[rb->write] = data;
    rb->write++;
    if (rb->write >= RING_BUFFER_SIZE)
    {
        rb->write = 0;
    }
}

// Récupère un octet du buffer circulaire
uint8_t ring_buffer_get(struct ring_buffer *rb)
{
    uint8_t data = rb->data[rb->read];
    rb->read++;
    if (rb->read >= RING_BUFFER_SIZE)
    {
        rb->read = 0;
    }
    return data;
}

// Indique le nombre d'octets disponibles dans le buffer circulaire
uint8_t ring_buffer_available_bytes(struct ring_buffer *rb)
{
    int write;
    if (rb->write < rb->read)
    {
        write = rb->write + RING_BUFFER_SIZE;
    }
    else
    {
        write = rb->write;
    }

    uint8_t size = RING_BUFFER_SIZE - write + rb->read;
    return size;
}

// Indique si le buffer circulaire est plein
uint8_t ring_buffer_is_full(struct ring_buffer *rb)
{
    return ring_buffer_available_bytes(rb) == 0;
}

int main()
{
    struct ring_buffer rb;
    ring_buffer_init(&rb);

    for (int iter = 0; iter < 10; iter++)
    {
        ring_buffer_put(&rb, 'C');
        ring_buffer_put(&rb, 'a');
        ring_buffer_put(&rb, ' ');
        ring_buffer_put(&rb, 'v');
        ring_buffer_put(&rb, 'a');
        ring_buffer_put(&rb, ' ');
        ring_buffer_put(&rb, 'b');
        ring_buffer_put(&rb, 'i');
        ring_buffer_put(&rb, 'e');
        ring_buffer_put(&rb, 'n');
        ring_buffer_put(&rb, '?');

        printf("Taille dispo : %d\n", ring_buffer_available_bytes(&rb));

        for (int i = 0; i < 11; i++)
        {
            printf("%c", ring_buffer_get(&rb));
        }
        printf("\n");

        printf("Taille dispo : %d\n", ring_buffer_available_bytes(&rb));
    }

    return EXIT_SUCCESS;
}