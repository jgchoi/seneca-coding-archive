#ifndef LIST_H
#define LIST_H



template<typename T, int N>
class List
{
	T t[N];
public:
	List(){ ; }

	size_t size() const
	{
		int i;
		for (i = 0; i < N; i++)
		{
			if (t[i].width() == 0)
				break;
		}
		return i;
	}

	int width() const
	{
		int max = 0;
		for (int i = 0; i < N; i++)
		{
			if (t[i].width()>max)
				max = t[i].width();
		}
		return max;
	}

	const T & operator[](int i)const
	{	
		T dummy;
		return i >= 0 && i < N ? t[i] : dummy;
	}

	void operator+=(const T & src)
	{
		for (int i = 0; i < N; i++)
		{
			if (t[i].width() == 0)
			{
				t[i] = src;
				break;
			}
		}
	}
};
#endif