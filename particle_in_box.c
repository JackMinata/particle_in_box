#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TIME_STEPS 1000
#define BOX_SIZE 10.0
#define TIME_INTERVAL 0.1

typedef struct {
    double position;
    double velocity;
} Particle;

void updateParticle(Particle *p) {
    p->position += p->velocity * TIME_INTERVAL;

    // Reflective boundaries
    if (p->position >= BOX_SIZE || p->position <= 0) {
        p->velocity = -p->velocity;
        p->position = (p->position >= BOX_SIZE) ? 2*BOX_SIZE - p->position : -p->position;
    }
}

int main() {
    srand(time(NULL));

    Particle p;
    p.position = (double) rand() / RAND_MAX * BOX_SIZE;
    p.velocity = (double) rand() / RAND_MAX * 2.0 - 1.0;  // Between -1 and 1

    printf("Initial Position: %f, Initial Velocity: %f\n", p.position, p.velocity);

    for (int t = 0; t < TIME_STEPS; ++t) {
        updateParticle(&p);
        printf("Time: %f, Position: %f, Velocity: %f\n", t * TIME_INTERVAL, p.position, p.velocity);
    }

    return 0;
}
