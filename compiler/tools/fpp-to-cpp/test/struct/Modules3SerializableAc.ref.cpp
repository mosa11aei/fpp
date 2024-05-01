// ======================================================================
// \title  Modules3SerializableAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for Modules3 struct
// ======================================================================

#include "Fw/Types/Assert.hpp"
#include "Fw/Types/StringUtils.hpp"
#include "Modules3SerializableAc.hpp"

// ----------------------------------------------------------------------
// Constructors
// ----------------------------------------------------------------------

Modules3 ::
  Modules3() :
    Serializable(),
    m_x(M::Modules1(0, 0.0f))
{
  for (FwSizeType i = 0; i < 3; i++) {
    this->m_arr[i] = M::Modules2(M::Modules1(0, 0.0f));
  }
}

Modules3 ::
  Modules3(
      const M::Modules2& x,
      const Type_of_arr& arr
  ) :
    Serializable(),
    m_x(x)
{
  for (FwSizeType i = 0; i < 3; i++) {
    this->m_arr[i] = arr[i];
  }
}

Modules3 ::
  Modules3(const Modules3& obj) :
    Serializable(),
    m_x(obj.m_x)
{
  for (FwSizeType i = 0; i < 3; i++) {
    this->m_arr[i] = obj.m_arr[i];
  }
}

Modules3 ::
  Modules3(
      const M::Modules2& x,
      const M::Modules2& arr
  ) :
    Serializable(),
    m_x(x)
{
  for (FwSizeType i = 0; i < 3; i++) {
    this->m_arr[i] = arr;
  }
}

// ----------------------------------------------------------------------
// Operators
// ----------------------------------------------------------------------

Modules3& Modules3 ::
  operator=(const Modules3& obj)
{
  if (this == &obj) {
    return *this;
  }

  set(obj.m_x, obj.m_arr);
  return *this;
}

bool Modules3 ::
  operator==(const Modules3& obj) const
{
  // Compare non-array members
  if (!(this->m_x == obj.m_x)) {
    return false;
  }

  // Compare array members
  if (!(this->m_arr == obj.m_arr)) {
    for (FwSizeType i = 0; i < 3; i++) {
      if (!(this->m_arr[i] == obj.m_arr[i])) {
        return false;
      }
    }
  }

  return true;
}

bool Modules3 ::
  operator!=(const Modules3& obj) const
{
  return !(*this == obj);
}

#ifdef BUILD_UT

std::ostream& operator<<(std::ostream& os, const Modules3& obj) {
  Fw::String s;
  obj.toString(s);
  os << s.toChar();
  return os;
}

#endif

// ----------------------------------------------------------------------
// Member functions
// ----------------------------------------------------------------------

Fw::SerializeStatus Modules3 ::
  serialize(Fw::SerializeBufferBase& buffer) const
{
  Fw::SerializeStatus status;

  status = buffer.serialize(this->m_x);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  for (FwSizeType i = 0; i < 3; i++) {
    status = buffer.serialize(this->m_arr[i]);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
  }

  return status;
}

Fw::SerializeStatus Modules3 ::
  deserialize(Fw::SerializeBufferBase& buffer)
{
  Fw::SerializeStatus status;

  status = buffer.deserialize(this->m_x);
  if (status != Fw::FW_SERIALIZE_OK) {
    return status;
  }
  for (FwSizeType i = 0; i < 3; i++) {
    status = buffer.deserialize(this->m_arr[i]);
    if (status != Fw::FW_SERIALIZE_OK) {
      return status;
    }
  }

  return status;
}

#if FW_SERIALIZABLE_TO_STRING

void Modules3 ::
  toString(Fw::StringBase& sb) const
{
  static const char* formatString =
    "( "
    "x = %s, "
    "arr = [ %s, "
    "%s, "
    "%s ]"
    " )";

  // Declare strings to hold any serializable toString() arguments
  Fw::String xStr;
  Fw::String arrStr[3];

  // Call toString for arrays and serializable types
  this->m_x.toString(xStr);
  for (FwSizeType i = 0; i < 3; i++) {
    this->m_arr[i].toString(arrStr[i]);
  }

  sb.format(
    formatString,
    xStr.toChar(),
    arrStr[0].toChar(),
    arrStr[1].toChar(),
    arrStr[2].toChar()
  );
}

#endif

// ----------------------------------------------------------------------
// Setter functions
// ----------------------------------------------------------------------

void Modules3 ::
  set(
      const M::Modules2& x,
      const Type_of_arr& arr
  )
{
  this->m_x = x;

  for (FwSizeType i = 0; i < 3; i++) {
    this->m_arr[i] = arr[i];
  }
}

void Modules3 ::
  setx(const M::Modules2& x)
{
  this->m_x = x;
}

void Modules3 ::
  setarr(const Type_of_arr& arr)
{
  for (FwSizeType i = 0; i < 3; i++) {
    this->m_arr[i] = arr[i];
  }
}
