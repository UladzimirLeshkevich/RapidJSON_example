#include "include/rapidjson/document.h"
//#include "include/rapidjson/schema.h"
#include "include/rapidjson/writer.h"
#include <fstream>
#include <iostream>

//using namespace std;
using namespace rapidjson;

int main()
{
    std::string file = "D:\\test.json";
    std::string string_from_file("empty");
    std::string string_;
    std::string hello_keyword_value;

    std::ifstream input_file(file);
    if (!input_file)
    {
        std::cerr << "\nfrom main():\ncan't open file " << file
                  << "\n";
        return EXIT_FAILURE;
    }

    std::cout << string_from_file << std::endl;
    while (getline(input_file, string_from_file))
    {
        string_ = string_ + string_from_file;
        std::cout << string_ << std::endl;
    }

    std::cout << string_ << std::endl;

    // 1. Parse a JSON string into DOM.
    const char *json = "{\"project\":\"rapidjson\",\"stars\":10}";
    Document d, my_d;
    d.Parse(json);
    my_d.Parse(string_.data()); //
    assert(my_d.HasMember("hello"));
    assert(my_d["hello"].IsString());
    std::cout << my_d["hello"].GetString() << std::endl;
    hello_keyword_value = my_d["hello"].GetString();
    std::cout << "hello_keyword_value = " << hello_keyword_value << std::endl;

    //assert(my_d.HasMember("hello"));
    //assert(my_d["hello"].IsString());

    //printf("hello = %s\n", my_d["hello"].GetString());

    // 2. Modify it by DOM.
    Value &s = d["stars"];
    s.SetInt(s.GetInt() + 1);

    // 3. Stringify the DOM
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);

    // Output {"project":"rapidjson","stars":11}
    std::cout << buffer.GetString() << std::endl;
    return 0;
}
