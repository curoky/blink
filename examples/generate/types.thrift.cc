/*
 * Copyright (c) 2020-2023 curoky(cccuroky@gmail.com).
 *
 * This file is part of go-thrift-parser.
 * See https://github.com/curoky/blink for further info.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

// Code generated by Compiler (0.1.0).
// DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING.
// @filename: types.thrift.cc
// @source: types.thrift
// @date:
// @version: 0.1.0
#include "types.thrift.h"
#include <rttr/registration>
namespace foo {
RTTR_REGISTRATION {
// BEGIN Register_enums
  rttr::registration::enumeration<EnumType>("EnumType")(
    rttr::value("ZERO", EnumType::ZERO),
    rttr::value("ONE", EnumType::ONE),
    rttr::value("TWO", EnumType::TWO),
    rttr::value("THREE", EnumType::THREE),
  rttr::metadata("thrift", "")
  );
// END Register_enums
// BEGIN Register_structs
  rttr::registration::class_<StructType>("StructType")
    .property("var_bool", &StructType::var_bool)(
      rttr::metadata("thrift", "1,Default,bool")
    )
    .property("var_byte", &StructType::var_byte)(
      rttr::metadata("thrift", "2,Default,byte")
    )
    .property("var_i16", &StructType::var_i16)(
      rttr::metadata("thrift", "3,Default,i16")
    )
    .property("var_i32", &StructType::var_i32)(
      rttr::metadata("thrift", "4,Default,i32")
    )
    .property("var_i64", &StructType::var_i64)(
      rttr::metadata("thrift", "5,Default,i64")
    )
    .property("var_double", &StructType::var_double)(
      rttr::metadata("thrift", "6,Default,double")
    )
    .property("var_string", &StructType::var_string)(
      rttr::metadata("thrift", "7,Default,string")
    )
    .property("var_binary", &StructType::var_binary)(
      rttr::metadata("thrift", "8,Default,binary")
    )
    .property("var_string_type", &StructType::var_string_type)(
      rttr::metadata("thrift", "9,Default,StrType")
    )
    .property("var_string_list", &StructType::var_string_list)(
      rttr::metadata("thrift", "10,Default,list|String")
    )
    .property("var_binary_list", &StructType::var_binary_list)(
      rttr::metadata("thrift", "11,Default,list|Binary")
    )
    .property("var_string_set", &StructType::var_string_set)(
      rttr::metadata("thrift", "12,Default,set|String")
    )
    .property("var_string_binary_map", &StructType::var_string_binary_map)(
      rttr::metadata("thrift", "13,Default,map|String|Binary")
    )
    .property("var_enum", &StructType::var_enum)(
      rttr::metadata("thrift", "14,Default,EnumType")
    )
    .property("var_enum_set", &StructType::var_enum_set)(
      rttr::metadata("thrift", "15,Default,set|Enum")
    )
    .property("var_union", &StructType::var_union)(
      rttr::metadata("thrift", "16,Default,UnionType")
    )
    .property("var_required_i32", &StructType::var_required_i32)(
      rttr::metadata("thrift", "17,Required,i32")
    )
    .property("var_optional_i32", &StructType::var_optional_i32)(
      rttr::metadata("thrift", "18,Optional,i32")
    )
  ;
  rttr::registration::class_<OutterStructType>("OutterStructType")
    .property("req", &OutterStructType::req)(
      rttr::metadata("thrift", "1,Default,StructType")
    )
  ;
// END Register_structs
}
} // namespace foo