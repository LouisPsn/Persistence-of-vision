#ifndef BUFFER_H
#define BUFFER_H

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define RING_BUFFER_SIZE 60

// typedef ring_buffer ring_buffer;
struct ring_buffer
{
    uint16_t buffer[RING_BUFFER_SIZE];
    uint8_t write;
    uint8_t read;
    uint8_t available;
};

// Initialise le buffer circulaire
void ring_buffer_init(struct ring_buffer *rb);

// gère l'incrémentation de write
void ring_buffer_incr_write(struct ring_buffer *rb);

// gère l'incrémentation de read
void ring_buffer_incr_read(struct ring_buffer *rb);


// Ajoute un octet dans le buffer circulaire
void ring_buffer_put(struct ring_buffer *rb, uint16_t data);


// Récupère un octet du buffer circulaire
uint16_t ring_buffer_get(struct ring_buffer *rb);


// Indique le nombre d'octets disponibles dans le buffer circulaire
uint8_t ring_buffer_available_bytes(struct ring_buffer *rb);


// Indique si le buffer circulaire est plein
uint8_t ring_buffer_is_full(struct ring_buffer *rb);

void ring_buffer_put_2(struct ring_buffer *rb, uint16_t data, uint16_t position);

uint16_t ring_buffer_get_2(struct ring_buffer *rb, int16_t position);

void clear_buffer(struct ring_buffer *rb);

uint8_t rb_has_data(struct ring_buffer *rb);

#endif