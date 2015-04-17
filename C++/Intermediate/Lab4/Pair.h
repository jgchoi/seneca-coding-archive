#ifndef PAIR_H
#define PAIR_H

template <typename A, typename B>
class Pair
{
	A a;
	B b;
public:
	Pair(){ ; }
	Pair(const A & aa, const B & bb)
	{
		a = aa;
		b = bb;
	}

	const A & first() const 
	{
		return a;
	}

	const B & second() const
	{
		return b;
	}

	int width() const
	{
		return a.length();
	}

};

template <>
class Pair<std::string, double>
{
	std::string a;
	double b;
public:
	Pair(){ a = ""; b = 0; }
	Pair(const std::string & aa, const double bb)
	{
		a = aa;
		b = bb;
	}

	const std::string & first() const
	{
		return a;
	}

	const double second() const
	{
		return b;
	}

	int width() const
	{
		return a.length();
	}

};

template <>
class Pair<std::string, std::string>
{
	std::string a;
	std::string b;
public:
	Pair(){ a = ""; b = ""; }
	Pair(const std::string & aa, const std::string & bb)
	{
		a = aa;
		b = bb;
	}

	const std::string & first() const
	{
		return a;
	}

	const std::string & second() const
	{
		return b;
	}

	int width() const
	{
		return a.length();
	}

};
#endif