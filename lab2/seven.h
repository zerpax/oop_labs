#include<string>

#ifndef Seven

class Seven {
private:
    unsigned char* value;
    int size = 0;

public:
    Seven();

    Seven(const size_t& , const unsigned char);
    Seven(const std::initializer_list<unsigned char>&);

    Seven(const std::string& );
    Seven(const Seven& );

    Seven(Seven&& ) noexcept;

    ~Seven();

    unsigned char* Value();
    int Size();
    void Print();


    Seven Plus(const Seven& );
    Seven Minus(const Seven& );
    bool Equals(const Seven&);

    Seven Copy(Seven& );
    bool Greater(const Seven& );

    bool Less(const Seven& );
};
#endif 