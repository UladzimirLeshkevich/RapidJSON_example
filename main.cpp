//http://rapidjson.org/md_doc_tutorial.html

#include "include/rapidjson/document.h"
//#include "include/rapidjson/schema.h"
#include "include/rapidjson/writer.h"
#include <fstream>
#include <iostream>

//define all rapidjson types
//http://rapidjson.org/namespacerapidjson.html#ae79a4751c1c460ff0de5ecc07874f3e4
#define JSON_NULL 0
#define JSON_FALSE 1
#define JSON_TRUE 2
#define JSON_OBJECT 3
#define JSON_ARRAY 4
#define JSON_STRING 5
#define JSON_NUMBER 6

static const char *kTypeNames[] = {
    "Null",   // 0
    "False",  // 1
    "True",   // 2
    "Object", // 3
    "Array",  // 4
    "String", // 5
    "Number"  // 6
};

using namespace rapidjson;

void print_json_object(const Value::Member &input);
void print_json_array(const Value::Member &input);
void print_json_string(const Value::Member &input);
void print_string(const Value::Member &input);
void print_json_type(const Value::Member &input);

void parse_json_object(const Value::Member &input);

//=============================== MAIN ====================================================
int main()
{
    std::string file = "D:\\test2.json";
    std::string string_from_file("empty");
    std::string string_;

    std::ifstream input_file(file);
    if (!input_file)
    {
        std::cerr << "\nfrom main():\ncan't open file " << file
                  << "\n";
        return EXIT_FAILURE;
    }

    while (getline(input_file, string_from_file))
    {
        string_ = string_ + string_from_file;
        //std::cout << string_ << std::endl;
    }

    //std::cout << string_ << std::endl;// result string from json file
    //std::cout << "======================================================================================" << std::endl;

    Document dom;
    dom.Parse(string_.data()); //

    // object &m == pair 'name : value'
    for (auto &m : dom.GetObject())
    {
        std::cout << "(" << m.name.GetString()
                  << " : " << kTypeNames[m.value.GetType()] << ")" << std::endl;
        print_json_type(m);
    }
    return 0;
}

//========================================================================================
void print_json_object(const Value::Member &input)
{
    std::cout << "Object is : " << std::endl;
    for (auto &obj : input.value.GetObject())
    {
        std::cout << "   " << obj.name.GetString()
                  << " : " << kTypeNames[obj.value.GetType()] << std::endl;
    }
    std::cout << "======================" << std::endl;
}

//========================================================================================
void print_json_array(const Value::Member &input)
{
    std::cout << "Array is : " << std::endl;
    for (auto &arr : input.value.GetArray())
    {
        for (auto &arr_obj : arr.GetObject())
        {

            //print_json_type(arr_obj); //

            std::cout << "   " << arr_obj.name.GetString()
                      << " : " << kTypeNames[arr_obj.value.GetType()] << std::endl;
        }
    }
    std::cout << "======================" << std::endl;
}

//========================================================================================
void print_json_string(const Value::Member &input)
{
    //std::cout << "String is : '" << input.value.GetString() << "'" << std::endl;
    std::cout << "String is : ";
    print_string(input);
    std::cout << "======================" << std::endl;
}

//========================================================================================
void print_string(const Value::Member &input)
{
    std::cout << "'" << input.value.GetString() << "'" << std::endl;
    //std::cout << "======================" << std::endl;
}

//========================================================================================
void print_json_type(const Value::Member &input)
{
    switch (input.value.GetType())
    {
    case JSON_NULL:
        break;
    case JSON_FALSE:
        break;
    case JSON_TRUE:
        break;
    case JSON_OBJECT:
        print_json_object(input);
        //parse_json_object(input);
        break;
    case JSON_ARRAY:
        print_json_array(input);
        break;
    case JSON_STRING:
        print_json_string(input);
        break;
    case JSON_NUMBER:
        break;
    default:
        std::cerr << " INVALID RAPIDJSON TYPE !!!" << std::endl;
    }
    return;
}

//========================================================================================
void parse_json_object(const Value::Member &input)
{
    switch (input.value.GetType())
    {
    case JSON_NULL:
        break;
    case JSON_FALSE:
        break;
    case JSON_TRUE:
        break;
    case JSON_OBJECT:
        //parse_json_object(input);
        print_json_object(input);
        break;
    case JSON_ARRAY:
        print_json_array(input);
        break;
    case JSON_STRING:
        print_json_string(input);
        break;
    case JSON_NUMBER:
        break;
    default:
        std::cerr << " INVALID RAPIDJSON TYPE !!!" << std::endl;
    }
    return;
}
