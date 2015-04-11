const int MAX = 700;

struct Prefix {
    int  no;             // number of entries
    int  area[MAX];      // area elements
    char pubLow[MAX][8]; // low end of publisher range
    char pubHgh[MAX][8]; // high end of publisher range
    int  pubLen[MAX];    // no of chars in publisher string
};

bool load(const char* filename, Prefix* p);
bool isRegistered(const Prefix* p, int area);
int minNoDigits(const Prefix* p, int area);
bool isRegistered(const Prefix* p, int area, const char* publisher);