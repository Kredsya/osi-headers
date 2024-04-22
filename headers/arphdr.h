#ifndef ARPHDR_H_
#define ARPHDR_H_

#include "hpch.h"

#define ARP_SIZE 28

#pragma pack(push, 1)
struct ArpHdr {
    uint16_t hw_type_;
    uint16_t proto_type_;
    uint8_t hw_size_;
    uint8_t proto_size_;
    uint16_t opcode_;
    uint8_t src_hw_mac_[6];
    uint8_t src_proto_ipv4_[6];
    uint8_t dst_hw_mac_[6];
    uint8_t dst_proto_ipv4_[6];

    uint16_t hw_type() { return ntohs(hw_type_); };
    uint16_t proto_type() { return ntohs(proto_type_); };
    uint8_t hw_size() { return hw_size_; };
    uint8_t proto_size() { return proto_size_; };
    uint16_t opcode() { return ntohs(opcode_); };
    uint8_t *src_hw_mac() { return src_hw_mac_; };
    uint8_t *src_proto_ipv4() { return src_proto_ipv4_; };
    uint8_t *dst_hw_mac() { return dst_hw_mac_; };
    uint8_t *dst_proto_ipv4() { return dst_proto_ipv4_; };

    enum : uint16_t {
        ethernet = 1,
        ipv4 = 0x0800,
        request = 1,
        reply = 2
    };
};
#pragma pack(pop)

#endif // ARPHDR_H_
