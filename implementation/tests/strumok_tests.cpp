#include <gtest/gtest.h>
#include "../strumok_funcs.h"
#include <cstdint>

TEST(Strumok256Test, TestVectorsFromStandard) {

    uint64_t key[4] = {0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL, 0x8000000000000000ULL};
    uint64_t iv[4]  = {0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL};

    init_256(key, iv);

    uint64_t expected_z0 = 0xe442d15345dc66caULL;
    uint64_t expected_z1 = 0xf47d700ecc66408aULL;
    uint64_t expected_z2 = 0xb4cb284b5477e641ULL;
    uint64_t expected_z3 = 0xa2afc9092e4124b0ULL;
    uint64_t expected_z4 = 0x728e5fa26b11a7d9ULL;
    uint64_t expected_z5 = 0xe6a7b9288c68f972ULL;
    uint64_t expected_z6 = 0x70eb3606de8ba44cULL;
    uint64_t expected_z7 = 0xaced7956bd3e3de7ULL;


    EXPECT_EQ(next(false), expected_z0);
    EXPECT_EQ(next(false), expected_z1);
    EXPECT_EQ(next(false), expected_z2);
    EXPECT_EQ(next(false), expected_z3);
    EXPECT_EQ(next(false), expected_z4);
    EXPECT_EQ(next(false), expected_z5);
    EXPECT_EQ(next(false), expected_z6);
    EXPECT_EQ(next(false), expected_z7);

}

TEST(Strumok256Test, TestVector2FromStandard) {
    uint64_t key[4] = {0xaaaaaaaaaaaaaaaaULL, 0xaaaaaaaaaaaaaaaaULL, 0xaaaaaaaaaaaaaaaaULL, 0xaaaaaaaaaaaaaaaaULL};
    uint64_t iv[4]  = {0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL};

    init_256(key, iv);

    uint64_t expected_z0 = 0xa7510b38c7a95d1dULL;
    uint64_t expected_z1 = 0xcd5ea28a15b8654fULL;
    uint64_t expected_z2 = 0xc5e2e2771d0373b2ULL;
    uint64_t expected_z3 = 0x98ae829686d5fceeULL;
    uint64_t expected_z4 = 0x45bddf65c523dbb8ULL;
    uint64_t expected_z5 = 0x32a93fcdd950001fULL;
    uint64_t expected_z6 = 0x752a7fb588af8c51ULL;
    uint64_t expected_z7 = 0x9de92736664212d4ULL;

    EXPECT_EQ(next(false), expected_z0);
    EXPECT_EQ(next(false), expected_z1);
    EXPECT_EQ(next(false), expected_z2);
    EXPECT_EQ(next(false), expected_z3);
    EXPECT_EQ(next(false), expected_z4);
    EXPECT_EQ(next(false), expected_z5);
    EXPECT_EQ(next(false), expected_z6);
    EXPECT_EQ(next(false), expected_z7);
}

TEST(Strumok256Test, TestVector3FromStandard) {
    uint64_t key[4] = {0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL, 0x8000000000000000ULL};
    uint64_t iv[4]  = {0x0000000000000001ULL, 0x0000000000000002ULL, 0x0000000000000003ULL, 0x0000000000000004ULL};

    init_256(key, iv);

    uint64_t expected_z0 = 0xfe44a2508b5a2acdULL;
    uint64_t expected_z1 = 0xaf355b4ed21d2742ULL;
    uint64_t expected_z2 = 0xdcd7fdd6a57a9e71ULL;
    uint64_t expected_z3 = 0x5d267bd2739fb5ebULL;
    uint64_t expected_z4 = 0xb22eee96b2832072ULL;
    uint64_t expected_z5 = 0xc7de6a4cdaa9a847ULL;
    uint64_t expected_z6 = 0x72d5da93812680f2ULL;
    uint64_t expected_z7 = 0x4a0acb7e93da2ce0ULL;

    EXPECT_EQ(next(false), expected_z0);
    EXPECT_EQ(next(false), expected_z1);
    EXPECT_EQ(next(false), expected_z2);
    EXPECT_EQ(next(false), expected_z3);
    EXPECT_EQ(next(false), expected_z4);
    EXPECT_EQ(next(false), expected_z5);
    EXPECT_EQ(next(false), expected_z6);
    EXPECT_EQ(next(false), expected_z7);
}

TEST(Strumok256Test, TestVector4FromStandard) {
    uint64_t key[4] = {0xaaaaaaaaaaaaaaaaULL, 0xaaaaaaaaaaaaaaaaULL, 0xaaaaaaaaaaaaaaaaULL, 0xaaaaaaaaaaaaaaaaULL};
    uint64_t iv[4]  = {0x0000000000000001ULL, 0x0000000000000002ULL, 0x0000000000000003ULL, 0x0000000000000004ULL};

    init_256(key, iv);

    uint64_t expected_z0 = 0xe6d0efd9cea5abcdULL;
    uint64_t expected_z1 = 0x1e78ba1a9b0e401eULL;
    uint64_t expected_z2 = 0xbcfbea2c02ba0781ULL;
    uint64_t expected_z3 = 0x1bd375588ae08794ULL;
    uint64_t expected_z4 = 0x5493cf21e114c209ULL;
    uint64_t expected_z5 = 0x66cd5d7cc7d0e69aULL;
    uint64_t expected_z6 = 0xa5cdb9f3380d07faULL;
    uint64_t expected_z7 = 0x2940d61a4d4e9ce4ULL;

    EXPECT_EQ(next(false), expected_z0);
    EXPECT_EQ(next(false), expected_z1);
    EXPECT_EQ(next(false), expected_z2);
    EXPECT_EQ(next(false), expected_z3);
    EXPECT_EQ(next(false), expected_z4);
    EXPECT_EQ(next(false), expected_z5);
    EXPECT_EQ(next(false), expected_z6);
    EXPECT_EQ(next(false), expected_z7);
}

TEST(Strumok512Test, TestVector1FromStandard) {
    uint64_t key[8] = {0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL,
                       0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL, 0x8000000000000000ULL};
    uint64_t iv[4]  = {0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL};

    init_512(key, iv);

    uint64_t expected_z0 = 0xf5b9ab51100f8317ULL;
    uint64_t expected_z1 = 0x898ef2086a4af395ULL;
    uint64_t expected_z2 = 0x59571fecb5158d0bULL;
    uint64_t expected_z3 = 0xb7c45b6744c71fbbULL;
    uint64_t expected_z4 = 0xff2efcf05d8d8db9ULL;
    uint64_t expected_z5 = 0x7a585871e5c419c0ULL;
    uint64_t expected_z6 = 0x6b5c4691b9125e71ULL;
    uint64_t expected_z7 = 0xa55be7d2b358ec6eULL;

    EXPECT_EQ(next(false), expected_z0);
    EXPECT_EQ(next(false), expected_z1);
    EXPECT_EQ(next(false), expected_z2);
    EXPECT_EQ(next(false), expected_z3);
    EXPECT_EQ(next(false), expected_z4);
    EXPECT_EQ(next(false), expected_z5);
    EXPECT_EQ(next(false), expected_z6);
    EXPECT_EQ(next(false), expected_z7);
}

TEST(Strumok512Test, TestVector2FromStandard) {
    uint64_t key[8] = {0xaaaaaaaaaaaaaaaaULL, 0xaaaaaaaaaaaaaaaaULL, 0xaaaaaaaaaaaaaaaaULL, 0xaaaaaaaaaaaaaaaaULL,
                       0xaaaaaaaaaaaaaaaaULL, 0xaaaaaaaaaaaaaaaaULL, 0xaaaaaaaaaaaaaaaaULL, 0xaaaaaaaaaaaaaaaaULL};
    uint64_t iv[4]  = {0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL};

    init_512(key, iv);

    uint64_t expected_z0 = 0xd2a6103c50bd4e04ULL;
    uint64_t expected_z1 = 0xdc6a21af5eb13b73ULL;
    uint64_t expected_z2 = 0xdf4ca6cb07797265ULL;
    uint64_t expected_z3 = 0xf453c253d8d01876ULL;
    uint64_t expected_z4 = 0x039a64dc7a01800cULL;
    uint64_t expected_z5 = 0x688ce327dccb7e84ULL;
    uint64_t expected_z6 = 0x41e0250b5e526403ULL;
    uint64_t expected_z7 = 0x9936e478aa200f22ULL;

    EXPECT_EQ(next(false), expected_z0);
    EXPECT_EQ(next(false), expected_z1);
    EXPECT_EQ(next(false), expected_z2);
    EXPECT_EQ(next(false), expected_z3);
    EXPECT_EQ(next(false), expected_z4);
    EXPECT_EQ(next(false), expected_z5);
    EXPECT_EQ(next(false), expected_z6);
    EXPECT_EQ(next(false), expected_z7);
}

TEST(Strumok512Test, TestVector3FromStandard) {
    uint64_t key[8] = {0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL,
                       0x0000000000000000ULL, 0x0000000000000000ULL, 0x0000000000000000ULL, 0x8000000000000000ULL};
    uint64_t iv[4]  = {0x0000000000000001ULL, 0x0000000000000002ULL, 0x0000000000000003ULL, 0x0000000000000004ULL};

    init_512(key, iv);

    uint64_t expected_z0 = 0xcca12eae8133aaaaULL;
    uint64_t expected_z1 = 0x528d85507ce8501dULL;
    uint64_t expected_z2 = 0xda83c7fe3e1823f1ULL;
    uint64_t expected_z3 = 0x21416ebf63b71a42ULL;
    uint64_t expected_z4 = 0x26d76d2bf1a625ebULL;
    uint64_t expected_z5 = 0xeec66ee0cd0b1efcULL;
    uint64_t expected_z6 = 0x02dd68f338a345a8ULL;
    uint64_t expected_z7 = 0x47538790a5411adbULL;

    EXPECT_EQ(next(false), expected_z0);
    EXPECT_EQ(next(false), expected_z1);
    EXPECT_EQ(next(false), expected_z2);
    EXPECT_EQ(next(false), expected_z3);
    EXPECT_EQ(next(false), expected_z4);
    EXPECT_EQ(next(false), expected_z5);
    EXPECT_EQ(next(false), expected_z6);
    EXPECT_EQ(next(false), expected_z7);
}

TEST(Strumok512Test, TestVector4FromStandard) {
    uint64_t key[8] = {0xaaaaaaaaaaaaaaaaULL, 0xaaaaaaaaaaaaaaaaULL, 0xaaaaaaaaaaaaaaaaULL, 0xaaaaaaaaaaaaaaaaULL,
                       0xaaaaaaaaaaaaaaaaULL, 0xaaaaaaaaaaaaaaaaULL, 0xaaaaaaaaaaaaaaaaULL, 0xaaaaaaaaaaaaaaaaULL};
    uint64_t iv[4]  = {0x0000000000000001ULL, 0x0000000000000002ULL, 0x0000000000000003ULL, 0x0000000000000004ULL};

    init_512(key, iv);

    uint64_t expected_z0 = 0x965648e775c717d5ULL;
    uint64_t expected_z1 = 0xa63c2a7376e92df3ULL;
    uint64_t expected_z2 = 0x0b0eb0bbd47ca267ULL;
    uint64_t expected_z3 = 0xea593d979ae5bd39ULL;
    uint64_t expected_z4 = 0xd773b5e5193cafe1ULL;
    uint64_t expected_z5 = 0xb0a26671d259422bULL;
    uint64_t expected_z6 = 0x85b2aa326b280156ULL;
    uint64_t expected_z7 = 0x511ace6451435f0cULL;

    EXPECT_EQ(next(false), expected_z0);
    EXPECT_EQ(next(false), expected_z1);
    EXPECT_EQ(next(false), expected_z2);
    EXPECT_EQ(next(false), expected_z3);
    EXPECT_EQ(next(false), expected_z4);
    EXPECT_EQ(next(false), expected_z5);
    EXPECT_EQ(next(false), expected_z6);
    EXPECT_EQ(next(false), expected_z7);
}