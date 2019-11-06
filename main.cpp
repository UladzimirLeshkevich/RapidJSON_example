//http://rapidjson.org/md_doc_tutorial.html

#include "include/rapidjson/document.h"
//#include "include/rapidjson/schema.h"
#include "include/rapidjson/writer.h"
#include <fstream>
#include <iostream>

//define all rapidjson types
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

void parse_json_object(const Value::Member &input);
void parse_json_array(const Value::Member &input);
void parse_json_string(const Value::Member &input);
void print_string(const Value::Member &input);
void parse_json_type(const Value::Member &input);
void parse_json_number(const Value::Member &input);

//=============================== MAIN ====================================================
int main()
{
    //std::string file = "D:\\test2.json";
    std::string file = "test.json";
    std::string string_from_file("empty");
    std::string string_;

    std::ifstream input_file(file);
    if (!input_file)
    {
        std::cerr << "\nfrom main():\ncan't open file " << file
                  << "\n";
        return EXIT_FAILURE;
    }

    //SkipWhitespace(input_file); //

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
        parse_json_type(m);
    }
    return 0;
}

//========================================================================================
void parse_json_object(const Value::Member &input)
{
    std::cout << "Object is : " << std::endl;
    for (auto &obj : input.value.GetObject())
    {
        std::cout << "   " << obj.name.GetString()
                  << " : " << kTypeNames[obj.value.GetType()] << std::endl;
        parse_json_type(obj); // !!!
    }
    std::cout << "======================" << std::endl;
}

//========================================================================================
void parse_json_array(const Value::Member &input)
{
    std::cout << "Array is : " << std::endl;
    for (auto &arr : input.value.GetArray())
    {
        for (auto &arr_obj : arr.GetObject())
        {
            std::cout << "   " << arr_obj.name.GetString()
                      << " : " << kTypeNames[arr_obj.value.GetType()] << std::endl;
            parse_json_type(arr_obj); // !!!
        }
    }
    std::cout << "======================" << std::endl;
}

//========================================================================================
void parse_json_string(const Value::Member &input)
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
void parse_json_type(const Value::Member &input)
{
    switch (input.value.GetType())
    {
    case JSON_NULL:
        std::cout << "NULL" << std::endl; //
        break;
    case JSON_FALSE:
        std::cout << "false" << std::endl; //
        break;
    case JSON_TRUE:
        std::cout << "true" << std::endl; //
        break;
    case JSON_OBJECT:
        parse_json_object(input);
        break;
    case JSON_ARRAY:
        parse_json_array(input);
        break;
    case JSON_STRING:
        parse_json_string(input);
        break;
    case JSON_NUMBER:
        parse_json_number(input);
        break;
    default:
        std::cerr << " INVALID RAPIDJSON TYPE !!!" << std::endl;
        return;
    }
    return;
}

//========================================================================================
void parse_json_number(const Value::Member &input)
{
    std::cout << "Number is : ";
    if (input.value.IsInt())
    {
        std::cout << input.value.GetInt() << std::endl;
    }
    else
    {
        std::cout << input.value.GetDouble() << std::endl;
    }
    std::cout << "======================" << std::endl;
}
