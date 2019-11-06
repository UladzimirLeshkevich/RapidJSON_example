//http://rapidjson.org/md_doc_tutorial.html

#include "include/rapidjson/document.h"
//#include "include/rapidjson/schema.h"
#include "include/rapidjson/writer.h"
#include <fstream>
#include <iostream>

using namespace rapidjson;

int main()
{
    std::string file = "D:\\test2.json";
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
        //std::cout << string_ << std::endl;
    }

    std::cout << string_ << std::endl;
    std::cout << "======================================================================================" << std::endl;

    //const char *json = "{\"project\":\"rapidjson\",\"stars\":10}";
    Document dom;
    dom.Parse(string_.data()); //

    static const char *kTypeNames[] =
        {"Null", "False", "True", "Object", "Array", "String", "Number"};

    // object m == pair 'name : value'
    for (auto &m : dom.GetObject())
    {
        // name : value !!!
        std::cout << m.name.GetString()
                  << " : " << kTypeNames[m.value.GetType()] << std::endl;
        if (m.value.GetType() == 5) //string
        {
            std::cout << "String is : '" << m.value.GetString() << "'" << std::endl;
            std::cout << "===========" << std::endl;
        }
        if (m.value.GetType() == 3) //object
        {
            std::cout << "Object is : " << std::endl;
            for (auto &obj : m.value.GetObject())
            {
                std::cout << obj.name.GetString()
                          << " : " << kTypeNames[obj.value.GetType()] << std::endl;
            }
            std::cout << "===========" << std::endl;
        }
        if (m.value.GetType() == 4) //array
        {
            std::cout << "Array is : " << std::endl;
            for (auto &arr : m.value.GetArray())
            {
                for (auto &arr_obj : arr.GetObject())
                {

                    std::cout << arr_obj.name.GetString()
                              << " : " << kTypeNames[arr_obj.value.GetType()] << std::endl;
                }
            }
            std::cout << "===========" << std::endl;
        }
    }

    //    assert(my_d.HasMember("hello"));
    //    assert(my_d["hello"].IsString());
    //    std::cout << my_d["hello"].GetString() << std::endl;
    //    hello_keyword_value = my_d["hello"].GetString();
    //    std::cout << "hello_keyword_value = " << hello_keyword_value << std::endl;

    return 0;
}
