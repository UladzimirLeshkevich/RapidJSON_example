//http://rapidjson.org/md_doc_tutorial.html

#include "include/rapidjson/document.h"
//#include "include/rapidjson/schema.h"
#include "include/rapidjson/writer.h"
#include <fstream>
#include <iostream>

//using namespace std;
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

    // 1. Parse a JSON string into DOM.
    const char *json = "{\"project\":\"rapidjson\",\"stars\":10}";
    Document d, my_d;
    d.Parse(json);
    my_d.Parse(string_.data()); //

    static const char *kTypeNames[] =
        {"Null", "False", "True", "Object", "Array", "String", "Number"};

    //    for (Value::ConstMemberIterator itr = my_d.MemberBegin();
    //         itr != my_d.MemberEnd(); ++itr)
    //    {
    //        printf("Type of member %s is %s\n",
    //               itr->name.GetString(), kTypeNames[itr->value.GetType()]);

    //        std::cout << "Type of member is " << itr->name.GetString()
    //                  << " | " << kTypeNames[itr->value.GetType()] << std::endl;
    //    }

    for (auto &m : my_d.GetObject())
    {
        //        printf("  Type of member %s is %s\n",
        //               m.name.GetString(), kTypeNames[m.value.GetType()]);

        //        std::cout << "Type of member is " << m.name.GetString()
        //                  << " | " << kTypeNames[m.value.GetType()] << std::endl;

        // name : value !!!
        std::cout << m.name.GetString()
                  << " : " << kTypeNames[m.value.GetType()] << std::endl;
        if (m.value.GetType() == 5)
        {
            std::cout << m.value.GetString() << std::endl;
        }

        //        std::cout << "    Type of member is " << m.name.GetString()
        //                  << " | " << m.value.GetType() << std::endl;//type = 0,1,2,3,4,5,6
    }

    //    assert(my_d.HasMember("hello"));
    //    assert(my_d["hello"].IsString());
    //    std::cout << my_d["hello"].GetString() << std::endl;
    //    hello_keyword_value = my_d["hello"].GetString();
    //    std::cout << "hello_keyword_value = " << hello_keyword_value << std::endl;

    //    // 2. Modify it by DOM.
    //    Value &s = d["stars"];
    //    s.SetInt(s.GetInt() + 1);

    //    // 3. Stringify the DOM
    //    StringBuffer buffer;
    //    Writer<StringBuffer> writer(buffer);
    //    d.Accept(writer);

    //    // Output {"project":"rapidjson","stars":11}
    //    std::cout << buffer.GetString() << std::endl;
    return 0;
}
