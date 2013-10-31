#ifndef RINGBUFFER_H
#define RINGBUFFER_H

#define RING_SIZE 256

struct ring {
	unsigned char head;
	unsigned char fill1[63];
	unsigned char tail;
	unsigned char fill2[63];
	unsigned char data[RING_SIZE];
};

static inline unsigned int ring_next_head(const volatile struct ring *ring)
{
	return (ring->head + 1) & (RING_SIZE - 1);
}

static inline unsigned int ring_next_tail(const volatile struct ring *ring)
{
	return (ring->tail + 1) & (RING_SIZE - 1);
}

static inline int ring_have_space(const volatile struct ring *ring)
{
	return ring_next_head(ring) != ring->tail;
}

static inline int ring_have_data(const volatile struct ring *ring)
{
	return ring->head != ring->tail;
}

#endif /* RINGBUFFER_H */
