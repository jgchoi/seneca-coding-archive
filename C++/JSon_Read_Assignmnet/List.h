#ifndef _LIST_H_
#define _LIST_H_
namespace json{
	template<typename T,int objects_size>
	class List{
		T objects[objects_size];
		int current_size;
	public:
		List(){current_size=0;}
		size_t size() const{ return current_size; }
		const T & operator[](int i){ 
			// filter range out of boundary
			if ( i < 0 || i > current_size-1 )
				throw std::string("Request element is in out of boundary");
			return objects[i];
		}

		void operator+=(const T & src){
			if (current_size < objects_size){
				//copy to last empty element spot, increase current size
				objects[current_size++] = src;
			}
		}

		void operator+=(T&& src){
			if (current_size < objects_size){
				//move to last empty element spot
				objects[current_size++] = std::move(src);
			}
		}
	};
}
#endif