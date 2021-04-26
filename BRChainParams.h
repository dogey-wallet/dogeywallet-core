//
//  BRChainParams.h
//
//  Created by Aaron Voisine on 1/10/18.
//  Copyright (c) 2019 breadwallet LLC
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#ifndef BRChainParams_h
#define BRChainParams_h

#include "BRMerkleBlock.h"
#include "BRSet.h"
#include <assert.h>

typedef struct {
    uint32_t height;
    UInt256 hash;
    uint32_t timestamp;
    uint32_t target;
} BRCheckPoint;

typedef struct {
    const char * const *dnsSeeds; // NULL terminated array of dns seeds
    uint16_t standardPort;
    uint32_t magicNumber;
    uint64_t services;
    int (*verifyDifficulty)(const BRMerkleBlock *block, const BRSet *blockSet); // blockSet must have last 2016 blocks
    const BRCheckPoint *checkpoints;
    size_t checkpointsCount;
} BRChainParams;

static const char *BRMainNetDNSSeeds[] = {
    "dogecoin.com.", "seed.dogecoin.com.", "doger.dogecoin.com.", "seed.doger.dogecoin.com.",
    "multidoge.org.", "seed.multidoge.org.", "seed2.multidoge.org.", NULL
};

static const char *BRTestNetDNSSeeds[] = {
    "jrn.me.uk.", "testseed.jrn.me.uk.", NULL
};

// blockchain checkpoints - these are also used as starting points for partial chain downloads, so they must be at
// difficulty transition boundaries in order to verify the block difficulty at the immediately following transition
static const BRCheckPoint BRMainNetCheckpoints[] = {
    {       0, uint256("1a91e3dace36e2be3bf030a65679fe821aa1d6ef92e7c9902eb318182c355691"), 1386325540, 0x1e0ffff0 },
    {  104679, uint256("35eb87ae90d44b98898fec8c39577b76cb1eb08e1261cfc10706c8ce9a1d01cf"), 1392637497, 0x1b41676b },
    {  145000, uint256("cc47cae70d7c5c92828d3214a266331dde59087d4a39071fa76ddfff9b7bde72"), 1395094679, 0x1b499dfd },
    {  371337, uint256("60323982f9c5ff1b5a954eac9dc1269352835f47c2c5222691d80f0d50dcf053"), 1410464577, 0x1b364184 },
    {  450000, uint256("d279277f8f846a224d776450aa04da3cf978991a182c6f3075db4c48b173bbd7"), 1415413000, 0x1b03efda },
    {  771275, uint256("1b7d789ed82cbdc640952e7e7a54966c6488a32eaad54fc39dff83f310dbaaed"), 1435666139, 0x1b0444d2 },
    {  1000000, uint256("6aae55bea74235f0c80bd066349d4440c31f2d0f27d54265ecd484d8c1d11b47"), 1450031952, 0x1b02dcf8 },
    {  1250000, uint256("00c7a442055c1a990e11eea5371ca5c1c02a0677b33cc88ec728c45edc4ec060"), 1465690401, 0x1b045d00 },
    {  1500000, uint256("f1d32d6920de7b617d51e74bdf4e58adccaa582ffdc8657464454f16a952fca6"), 1481313507, 0x1b0306ef },
    {  1750000, uint256("5c8e7327984f0d6f59447d89d143e5f6eafc524c82ad95d176c5cec082ae2001"), 1496985750, 0x1b00d4d4 },
    {  2000000, uint256("9914f0e82e39bbf21950792e8816620d71b9965bdbbc14e72a95e3ab9618fea8"), 1512600918, 0x1a1c1225 },
    {  2031142, uint256("893297d89afb7599a3c571ca31a3b80e8353f4cf39872400ad0f57d26c4c5d42"), 1514549787, 0x1a15d633 },
    {  2250000, uint256("0a87a8d4e40dca52763f93812a288741806380cd569537039ee927045c6bc338"), 1528215255, 0x1a053477 },
    {  2510150, uint256("77e3f4a4bcb4a2c15e8015525e3d15b466f6c022f6ca82698f329edef7d9777e"), 1544484077, 0x1a0868af },
    {  2750000, uint256("d4f8abb835930d3c4f92ca718aaa09bef545076bd872354e0b2b85deefacf2e3"), 1559459044, 0x1a0292e2 },
    {  3000000, uint256("195a83b091fb3ee7ecb56f2e63d01709293f57f971ccf373d93890c8dc1033db"), 1575096781, 0x1a07da10 },
    {  3250000, uint256("7f3e28bf9e309c4b57a4b70aa64d3b2ea5250ae797af84976ddc420d49684034"), 1590799169, 0x1a05bfa3 },
    {  3500000, uint256("eaa303b93c1c64d2b3a2cdcf6ccf21b10cc36626965cc2619661e8e1879abdfb"), 1606543340, 0x1a08d505 },
    {  3606083, uint256("954c7c66dee51f0a3fb1edb26200b735f5275fe54d9505c76ebd2bcabac36f1e"), 1613218169, 0x1a03d764 },
};

static const BRCheckPoint BRTestNetCheckpoints[] = {
    {       0, uint256("bb0a78264637406b6360aad926284d544d7049f45189db5664f3c4d07350559e"), 1391503289, 0x1e0ffff0 }
};

static int BRMainNetVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet)
{
    // const BRMerkleBlock *previous, *b = NULL;
    // uint32_t i;

    // assert(block != NULL);
    // assert(blockSet != NULL);

    // // check if we hit a difficulty transition, and find previous transition block
    // if ((block->height % BLOCK_DIFFICULTY_INTERVAL) == 0) {
    //     for (i = 0, b = block; b && i < BLOCK_DIFFICULTY_INTERVAL; i++) {
    //         b = BRSetGet(blockSet, &b->prevBlock);
    //     }
    // }

    // previous = BRSetGet(blockSet, &block->prevBlock);
    // return BRMerkleBlockVerifyDifficulty(block, previous, (b) ? b->timestamp : 0);
    return 1;
}

static int BRTestNetVerifyDifficulty(const BRMerkleBlock *block, const BRSet *blockSet)
{
    return 1; // XXX skip testnet difficulty check for now
}

static const BRChainParams BRMainNetParams = {
    BRMainNetDNSSeeds,
    22556,       // standardPort
    0xc0c0c0c0, // magicNumber
    0,          // services
    BRMainNetVerifyDifficulty,
    BRMainNetCheckpoints,
    sizeof(BRMainNetCheckpoints) / sizeof(*BRMainNetCheckpoints)};

static const BRChainParams BRTestNetParams = {
    BRTestNetDNSSeeds,
    44556,      // standardPort
    0xdcb7c1fc, // magicNumber
    0,          // services
    BRTestNetVerifyDifficulty,
    BRTestNetCheckpoints,
    sizeof(BRTestNetCheckpoints) / sizeof(*BRTestNetCheckpoints)};

#endif // BRChainParams_h
