//NVPair.h
//
#ifndef _NVPAIR_H_
#define _NVPAIR_H_
namespace json{
	template<typename N, typename V>
	class NVPair{
		N n;
		V v;
	public:
		NVPair(){}
		NVPair(N src_n, V src_v){
			n = src_n;
			v = src_v;
		}
		N name() const{
			return n;
		}
		V value() const{
			return v;
		}
	};
}
#endif