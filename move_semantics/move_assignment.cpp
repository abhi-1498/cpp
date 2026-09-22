#include<iostream>
#include<utility>

class buffer{

private:
    int* data;
    int size;

public:
    buffer(){
        data = new int(0);
        size = 1;
    }

    buffer(buffer& other){
        std::cout<<"copy constructor called.\n";
        data = new int(*(other.data));
        size = other.size;
    }

    buffer(buffer&& other){
        std::cout<<"move constructor called.\n";
        //stealing resource
        data = other.data;
        size = other.size;

        //making sure the rvalue other is point to clear data.
        other.data = nullptr;
        other.size = 0;
    }

    buffer& operator=(buffer&& other) noexcept {
        if(this != &other){
            std::cout<<"move assignment.\n";
            delete data;

            data = other.data;
            size = other.size;

            other.data = nullptr;
            size = 0;
        }
        return *this;
    }

    ~buffer(){
        delete data;
    }
};

int main(){
    buffer obj;

    //copy constructor
    buffer objcp = obj;

    //move constructor
    buffer obj2 = std::move(obj);

    //move assignment
    objcp = std::move(obj2);

    return 0;
}