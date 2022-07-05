// ======================================================================
// \title  PrimitiveArrayArrayAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for PrimitiveArray array
// ======================================================================

#include <cstring>
#include <cstdio>

#include "Fw/Types/Assert.hpp"
#include "Fw/Types/StringUtils.hpp"

#include "PrimitiveArrayArrayAc.hpp"

// ----------------------------------------------------------------------
// Constructors
// ----------------------------------------------------------------------

PrimitiveArray ::
  PrimitiveArray() :
    Serializable()
{
  // Construct using element-wise constructor
  *this = PrimitiveArray(
    M::Primitive2(1.0f, 1.0f, 1.0f, 1.0f, 1.0f),
    M::Primitive2(1.0f, 1.0f, 1.0f, 1.0f, 1.0f),
    M::Primitive2(1.0f, 1.0f, 1.0f, 1.0f, 1.0f),
    M::Primitive2(1.0f, 1.0f, 1.0f, 1.0f, 1.0f),
    M::Primitive2(1.0f, 1.0f, 1.0f, 1.0f, 1.0f)
  );
}

PrimitiveArray ::
  PrimitiveArray(const ElementType (&a)[SIZE]) :
    Serializable()
{
  for (U32 index = 0; index < SIZE; index++) {
    this->elements[index] = a[index];
  }
}

PrimitiveArray ::
  PrimitiveArray(const ElementType& e) :
    Serializable()
{
  for (U32 index = 0; index < SIZE; index++) {
    this->elements[index] = e;
  }
}

PrimitiveArray ::
  PrimitiveArray(
      const ElementType (&e1),
      const ElementType (&e2),
      const ElementType (&e3),
      const ElementType (&e4),
      const ElementType (&e5)
  ) :
    Serializable()
{
  this->elements[0] = e1;
  this->elements[1] = e2;
  this->elements[2] = e3;
  this->elements[3] = e4;
  this->elements[4] = e5;
}

PrimitiveArray ::
  PrimitiveArray(const PrimitiveArray& obj) :
    Serializable()
{
  for (U32 index = 0; index < SIZE; index++) {
    this->elements[index] = obj.elements[index];
  }
}

// ----------------------------------------------------------------------
// Operators
// ----------------------------------------------------------------------

PrimitiveArray::ElementType& PrimitiveArray ::
  operator[](const U32 i)
{
  FW_ASSERT(i < SIZE);
  return this->elements[i];
}

const PrimitiveArray::ElementType& PrimitiveArray ::
  operator[](const U32 i) const
{
  FW_ASSERT(i < SIZE);
  return this->elements[i];
}

PrimitiveArray& PrimitiveArray ::
  operator=(const PrimitiveArray& obj)
{
  if (this == &obj) {
    return *this;
  }

  for (U32 index = 0; index < SIZE; index++) {
    this->elements[index] = obj.elements[index];
  }
  return *this;
}

PrimitiveArray& PrimitiveArray ::
  operator=(const ElementType (&a)[SIZE])
{
  for (U32 index = 0; index < SIZE; index++) {
    this->elements[index] = a[index];
  }
  return *this;
}

PrimitiveArray& PrimitiveArray ::
  operator=(const ElementType& e)
{
  for (U32 index = 0; index < SIZE; index++) {
    this->elements[index] = e;
  }
  return *this;
}

bool PrimitiveArray ::
  operator==(const PrimitiveArray& obj) const
{
  for (U32 index = 0; index < SIZE; index++) {
    if ((*this)[index] != obj[index]) {
      return false;
    }
  }
  return true;
}

bool PrimitiveArray ::
  operator!=(const PrimitiveArray& obj) const
{
  return !(*this == obj);
}

#ifdef BUILD_UT

std::ostream& operator<<(std::ostream& os, const PrimitiveArray& obj) {
  Fw::String s;
  obj.toString(s);
  os << s;
  return os;
}

#endif

// ----------------------------------------------------------------------
// Member functions
// ----------------------------------------------------------------------

Fw::SerializeStatus PrimitiveArray ::
  serialize(Fw::SerializeBufferBase& buffer) const
{
  Fw::SerializeStatus status = Fw::FW_SERIALIZE_OK;
  for (U32 index = 0; index < SIZE; index++) {
    status = buffer.serialize((*this)[index]);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
  }
  return status;
}

Fw::SerializeStatus PrimitiveArray ::
  deserialize(Fw::SerializeBufferBase& buffer)
{
  Fw::SerializeStatus status = Fw::FW_SERIALIZE_OK;
  for (U32 index = 0; index < SIZE; index++) {
    status = buffer.deserialize((*this)[index]);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
  }
  return status;
}

#if FW_ARRAY_TO_STRING || BUILD_UT

void PrimitiveArray ::
  toString(Fw::StringBase& sb) const
{
  static const char *formatString = "[ "
    "%s "
    "%s "
    "%s "
    "%s "
    "%s ]";

  // Declare strings to hold any serializable toString() arguments
  char outputString[FW_ARRAY_TO_STRING_BUFFER_SIZE];
  (void) snprintf(
    outputString,
    FW_ARRAY_TO_STRING_BUFFER_SIZE,
    formatString,
    this->elements[0],
    this->elements[1],
    this->elements[2],
    this->elements[3],
    this->elements[4]
  );

  outputString[FW_ARRAY_TO_STRING_BUFFER_SIZE-1] = 0; // NULL terminate
  sb = outputString;
}

#endif
