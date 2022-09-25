/*
 * Copyright 2021 curoky(cccuroky@gmail.com).
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

//go:generate go-enum --marshal -f=$GOFILE -a "+:Plus,#:Sharp"

package ast

// ENUM(
// Void,
// Constant,
// Bool
// Byte
// I16
// I32
// I64
// Double
// String
// Binary
// Map
// List
// Set
// Enum
// Struct
// Union
// Exception
// Service
// Typedef
// Identifier
// Unknown
// )
type Category int32

type Annotation struct {
	Name  string
	Value string
}

type Type struct {
	Name        string
	Category    Category
	Annotations map[string]*Annotation
	Belong      *Thrift `json:"-"`

	// for list/set/map
	KeyType   *Type
	ValueType *Type

	// for typedef or reference
	PreRefType   *Type
	FinalRefType *Type

	// for struct
	Fields []*Field

	// for enum
	Values []*EnumValue

	ExpandCategoryStr string
}

func (t *Type) FinalType() *Type {
	if t.FinalRefType != nil {
		return t.FinalRefType
	}
	return t
}

type Namespace struct {
	Name        string
	Language    string
	Annotations map[string]*Annotation
}

type EnumValue struct {
	Name        string
	Value       int64
	Annotations map[string]*Annotation
}

// ENUM(
// Double,
// Int,
// Literal,
// Identifier,
// List,
// Map
// )
type ConstType int32

type ConstValueExtra struct {
	Name   string
	IsEnum bool
	Index  int64
	Sel    string
}

type ConstValue struct {
	Type       ConstType
	TypedValue *ConstTypedValue
	Extra      *ConstValueExtra
}

type ConstTypedValue struct {
	Double     *float64
	Int        *int64
	Literal    *string
	Identifier *string
	List       []*ConstValue
	Map        []*MapConstValue
}

type MapConstValue struct {
	Key   *ConstValue
	Value *ConstValue
}

type Constant struct {
	Name        string
	Type        *Type
	Value       *ConstValue
	Annotations map[string]*Annotation
}

// ENUM(
// Default,
// Required,
// Optional,
// )
type FieldType int32

type Field struct {
	ID           int64
	Name         string
	Requiredness FieldType
	Type         *Type
	Default      *ConstValue
	Annotations  map[string]*Annotation
}

type Function struct {
	Name        string
	ReturnType  *Type
	Arguments   []*Field
	Exceptions  []*Field
	Annotations map[string]*Annotation
}

type Service struct {
	Name        string
	Extends     string
	Functions   []*Function
	Annotations map[string]*Annotation
}

type Include struct {
	Path      string
	Name      string // short name when include
	Reference *Thrift
}

type Thrift struct {
	Filename    string
	Includes    []*Include
	CppIncludes []string
	Namespaces  map[string]*Namespace
	Constants   map[string]*Constant
	Enums       map[string]*Type
	Typedefs    map[string]*Type
	Structs     map[string]*Type
	Unions      map[string]*Type
	Exceptions  map[string]*Type
	Services    map[string]*Service

	// Just for resolve
	// TODO: remove this
	AllTypes []*Type
}

type Document struct {
	Thrifts map[string]*Thrift
}