#include "parser.h"

Parser::Parser()
{
}

//========================================================================================
void Parser::parse_json_object(const Value::Member &input)
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
void Parser::parse_json_array(const Value::Member &input)
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
void Parser::parse_json_string(const Value::Member &input)
{
    //std::cout << "String is : '" << input.value.GetString() << "'" << std::endl;
    std::cout << "String is : ";
    print_string(input);
    std::cout << "======================" << std::endl;
}

//========================================================================================
void Parser::print_string(const Value::Member &input)
{
    std::cout << "'" << input.value.GetString() << "'" << std::endl;
    //std::cout << "======================" << std::endl;
}

//========================================================================================
void Parser::parse_json_type(const Value::Member &input)
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
void Parser::parse_json_number(const Value::Member &input)
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
