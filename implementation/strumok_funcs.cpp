#include "strumok_funcs.h"
#include "strumok_tables.h"
#include <cstdint>
#include <iostream>

static uint64_t
a_mul(const uint64_t x) {
    return ( ( (x) << 8 ) ^ ( strumok_alpha_mul[x >> 56] ) );
}


static uint64_t
ainv_mul(const uint64_t x) {
    return ( ( (x) >> 8 ) ^ ( strumok_alphainv_mul[x & 0xff] ) );
}


static uint64_t transform_T(const uint64_t x) {
    return ((strumok_T0[  x        & 0xff ]) ^
            (strumok_T1[ (x >>  8) & 0xff ]) ^
            (strumok_T2[ (x >> 16) & 0xff ]) ^
            (strumok_T3[ (x >> 24) & 0xff ]) ^
            (strumok_T4[ (x >> 32) & 0xff ]) ^
            (strumok_T5[ (x >> 40) & 0xff ]) ^
            (strumok_T6[ (x >> 48) & 0xff ]) ^
            (strumok_T7[ (x >> 56) & 0xff ]));
}

uint64_t fsm(uint64_t x, uint64_t y, uint64_t z ) {
    return (x + y) ^ z;
}


void init_256(const uint64_t key[4], const uint64_t iv[4]) {
    r0 = 0;
    r1 = 0;

    s[15] = ~key[0];
    s[14] = key[1];
    s[13] = ~key[2];
    s[12] = key[3];
    s[11] = key[0];
    s[10] = ~key[1];

    s[9]  = key[2];
    s[8]  = key[3];
    s[7]  = ~key[0];
    s[6]  = ~key[1];
    s[5]  = key[2] ^ iv[3];
    s[4]  = key[3];

    s[3]  = key[0] ^ iv[2];
    s[2]  = key[1] ^ iv[1];
    s[1]  = key[2];
    s[0]  = key[3] ^ iv[0];

    for (int i = 0; i < 32; ++i) {
        next(true);
    }
    next(false);

}

void init_512(const uint64_t key[8], const uint64_t iv[4]) {
    s[15] = key[0];
    s[14] = ~key[1];
    s[13] = key[2];
    s[12] = key[3];
    s[11] = ~key[7];
    s[10] = key[5];

    s[9]  = ~key[6];
    s[8]  = key[4] ^ iv[3];
    s[7]  = ~key[0];
    s[6]  = key[1];
    s[5]  = key[2] ^ iv[2];
    s[4]  = key[3];

    s[3]  = key[4] ^ iv[1];
    s[2]  = key[5];
    s[1]  = key[6];
    s[0]  = key[7] ^ iv[0];

    r0 = 0;
    r1 = 0;

    for (int i = 0; i < 32; ++i) {
        next(true);
    }
    next(false);
}

uint64_t next(bool isInitMode) {
    uint64_t new_r1 = transform_T(r0);
    uint64_t new_r0 = r1 + s[13];

    uint64_t new_s[16] = {};

    for (int j = 0; j < 15; ++j) {
        new_s[j] = s[j + 1];
    }
    uint64_t fsm_v = fsm(s[15], r0, r1);
    uint64_t gamma = fsm_v ^ s[0];

    new_s[15] = a_mul(s[0]) ^ ainv_mul(s[11]) ^ s[13];
    if (isInitMode) {
        new_s[15] ^= fsm_v;
    }

    r0 = new_r0;
    r1 = new_r1;
    for (int j = 0; j <= 15; ++j) {
        s[j] = new_s[j];
    }

    return gamma;
}

void cipher_velocity_evaluation_256() {

    std::cout << "Max speed measuring for strumok_256\n";
    uint64_t key[4] = {0};
    uint64_t iv[4] = {0};
    init_256(key, iv);

    const uint64_t ITERATIONS = 1000000ULL;

    auto start_time = std::chrono::high_resolution_clock::now();

    uint64_t block_for_test = 0;

    for (uint64_t i = 0; i < ITERATIONS; ++i) {
        block_for_test ^= next(false);
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end_time - start_time;
    double seconds = diff.count();

    double total_bits = static_cast<double>(ITERATIONS) * 64.0;

    double total_gigabits = total_bits / 1e9;//gigabit

    double speed_gbps = total_gigabits / seconds;

    std::cout << "Execution time: " << seconds << " s\n";
    std::cout << "Max speed: " << speed_gbps << " gigabit/s\n\n";

    std::cout << block_for_test << std::endl;

}

void cipher_velocity_evaluation_512() {

    std::cout << "Max speed measuring for strumok_512\n";
    uint64_t key[8] = {0};
    uint64_t iv[4] = {0};
    init_512(key, iv);

    const uint64_t ITERATIONS = 1000000ULL;

    auto start_time = std::chrono::high_resolution_clock::now();

    uint64_t block_for_test = 0;

    for (uint64_t i = 0; i < ITERATIONS; ++i) {
        block_for_test ^= next(false);
    }

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end_time - start_time;
    double seconds = diff.count();

    double total_bits = static_cast<double>(ITERATIONS) * 64.0;

    double total_gigabits = total_bits / 1e9;//gigabit

    double speed_gbps = total_gigabits / seconds;

    std::cout << "Execution time: " << seconds << " s\n";
    std::cout << "Max speed: " << speed_gbps << " gigabit/s\n\n";

    std::cout << block_for_test << std::endl;

}

void attack_simulation_for_t4() {
    std::cout << "Basis: S15_3, R1_4, R0_4, S0_4, S12_4, S13_4, S15_5\n\n";

    uint64_t key[8] = {0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL,
                       0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL, 0x8000000000000000ULL};
    uint64_t iv[4]  = {0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL};

    init_512(key, iv);
    uint64_t Z[22] = {0};

    Z[0] = next(false);
    Z[1] = next(false);
    Z[2] = next(false);

    uint64_t s15_3 = s[15];

    Z[3] = next(false);

    uint64_t r1_4  = r1;
    uint64_t r0_4  = r0;
    uint64_t s0_4  = s[0];
    uint64_t s12_4 = s[12];
    uint64_t s13_4 = s[13];

    uint64_t s_check[16];
    std::copy(std::begin(s), std::end(s), s_check);

    Z[4] = next(false);

    uint64_t s15_5 = s[15];

    for (int i = 5; i <= 15; ++i) {
        Z[i] = next(false);
    }

    std::cout << "Start of calculation: \n";

    uint64_t sim_R0[22] = {0}, sim_R1[22] = {0};
    uint64_t sim_S0[22] = {0}, sim_S11[22] = {0}, sim_S13[22] = {0}, sim_S15[22] = {0};

    sim_R0[4] = r0_4;
    sim_R1[4] = r1_4;
    sim_S0[4] = s0_4;
    sim_S13[4] = s13_4;

    uint64_t s14_4 = s15_3;
    uint64_t s15_4 = (Z[4] ^ r1_4 ^ s0_4) - r0_4;
    uint64_t s11_4 = a_mul(s15_5 ^ a_mul(s0_4) ^ s13_4);

    sim_S15[4] = s15_4;
    sim_S15[5] = s15_5;

    std::cout << "What we get without gamma cycles, only with 4th tact's gamma and guessed vales: \n";
    std::cout << "s[11]: "<< s11_4 << std::endl;
    std::cout << "s[12]: "<< s12_4 << std::endl;
    std::cout << "s[13]: "<< s13_4 << std::endl;
    std::cout << "s[14]: "<< s14_4 << std::endl;
    std::cout << "s[15]: "<< s15_4 << std::endl;

    std::cout << "\nWhat we get from the gamma cycles for the 4th tact:\n";

    for(int t = 4; t < 14; ++t) {
        sim_R1[t+1] = transform_T(sim_R0[t]);
        sim_R0[t+1] = sim_R1[t] + sim_S13[t];

        if (t+1 == 5) {
            sim_S13[5] = s15_3;
        }
        else if (t+1 == 6) {
            sim_S13[6] = s15_4;
        }
        else {
            sim_S13[t+1] = sim_S15[t+1 - 2];
        }

        if (t+1 == 5) {
            sim_S11[5] = s12_4;
        }
        else if (t+1 == 6) {
            sim_S11[6] = s13_4;
        }
        else if (t+1 == 7) {
            sim_S11[7] = s15_3;
        }
        else if (t+1 == 8) {
            sim_S11[8] = s15_4;
        }
        else {
            sim_S11[t+1] = sim_S15[t+1 - 4];
        }

        if (t+1 > 5) {
            sim_S15[t+1] = a_mul(sim_S0[t]) ^ ainv_mul(sim_S11[t]) ^ sim_S13[t];
        }

        sim_S0[t+1] = Z[t+1] ^ (sim_S15[t+1] + sim_R0[t+1]) ^ sim_R1[t+1];

        std::cout << "s[" << (t - 3) << "]: " << sim_S0[t+1] << std::endl;
    }

    std::cout << "\nCheck comparison with real values whether they are same: \n";
    std::cout << std::boolalpha;

    std::cout << "s[0]: " << (s0_4 == s_check[0]) << std::endl;
    for(int t = 4; t < 14; ++t) {
        std::cout << "s[" << (t - 3) << "]: " << (sim_S0[t+1] == s_check[t - 3]) << std::endl;
    }
    std::cout << "s[11]: " << (s11_4 == s_check[11]) << std::endl;
    std::cout << "s[12]: " << (s12_4 == s_check[12]) << std::endl;
    std::cout << "s[13]: " << (s13_4 == s_check[13]) << std::endl;
    std::cout << "s[14]: " << (s14_4 == s_check[14]) << std::endl;
    std::cout << "s[15]: " << (s15_4 == s_check[15]) << std::endl;
}