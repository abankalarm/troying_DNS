#include <arpa/nameser.h>
#include <functional>
#include <iostream>
#include <netinet/in.h>
#include <resolv.h>
#include <string.h>
#include <map>
using namespace std;
int main(int argc, char **argv) {
    res_init();
    int r;
    unsigned char q[1024];
    {
    r= res_query(argv[1], C_IN, ns_t_txt, q, sizeof(q));
    } ns_msg n;
    ns_initparse(q, r, &n);
    map<ns_type, function<void (const ns_rr &rr)>> callbacks;
    callbacks[ns_t_srv]= [&n](const ns_rr &rr) -> void {
        cout << ns_rr_ttl(rr) << ntohs(*(unsigned short*)ns_rr_rdata(rr)) << ntohs(*((unsigned short*)ns_rr_rdata(rr) + 1)) << ntohs(*((unsigned short*)ns_rr_rdata(rr) + 2));
        char name[1024];
        dn_expand(ns_msg_base(n), ns_msg_end(n), 
                ns_rr_rdata(rr) + 6, name, sizeof(name));
        cout << name;
    };
    callbacks[ns_t_txt]= [&n](const ns_rr &rr) -> void {
        cout << ns_rr_rdata(rr) + 1 << endl;
    };
    for(int x= 0; x < ns_msg_count(n, ns_s_an); x++) {
        ns_rr rr;
        ns_parserr(&n, ns_s_an, x, &rr);
        ns_type type= ns_rr_type(rr);
        if (callbacks.count(type)) {
            callbacks[type](rr);
        }
    }return 0;
}