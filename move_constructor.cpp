#include<iostream>
#include<utility>

class abc{

private:
    int* data;
    int size;

public:
    abc(){
        data = new int(0);
        size = 1;
    }

    abc(abc& obj){
        std::cout<<"copy constructor called.\n";
        data = new int(*(obj.data));
        size = obj.size;
    }

    abc(abc&& obj){
        std::cout<<"move constructor called.\n";
        //stealing resource
        data = obj.data;
        size = obj.size;

        //making sure the rvalue obj is point to clear data.
        obj.data = nullptr;
        obj.size = 0;
    }

    ~abc(){
        delete data;
    }
};

int main(){
    abc obj;

    //copy constructor
    abc objcopy = obj;

    //move constructor
    abc obj2 = std::move(obj);

    return 0;
}