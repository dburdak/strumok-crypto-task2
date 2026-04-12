#pragma once
#include <cstdint>

inline uint64_t s[16];
inline uint64_t r0;
inline uint64_t r1;

void init_512(const uint64_t key[8], const uint64_t iv[4]);
void init_256(const uint64_t key[4], const uint64_t iv[4]);
uint64_t next(bool isInitMode=false);
void cipher_velocity_evaluation_256();
void cipher_velocity_evaluation_512();
void attack_simulation_for_t4();