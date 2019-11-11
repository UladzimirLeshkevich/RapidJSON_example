#pragma once

#include "include/rapidjson/document.h"
//#include "include/rapidjson/schema.h"
#include "include/rapidjson/writer.h"
#include <fstream>
#include <iostream>
#include <string>

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

class Parser
{
  public:
    Parser();

    void parse_json_object(const Value::Member &input);
    void parse_json_array(const Value::Member &input);
    void parse_json_string(const Value::Member &input);
    void print_string(const Value::Member &input);
    void parse_json_type(const Value::Member &input);
    void parse_json_number(const Value::Member &input);
};
