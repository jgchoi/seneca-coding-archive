class iFood {
	public:
		virtual int portions() const = 0;
		virtual void consume() = 0;
		virtual int remaining() const = 0;
		virtual void display() const = 0;
};
